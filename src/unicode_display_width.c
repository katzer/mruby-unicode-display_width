/*
 * Copyright (c) 2017 by appPlant GmbH. All rights reserved.
 *
 * @APPPLANT_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apache License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://opensource.org/licenses/Apache-2.0/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPPLANT_LICENSE_HEADER_END@
 */

#include "wcwidth.c"

#include "mruby.h"
#include "mruby/string.h"

#include <locale.h>
#include <stdlib.h>
#include <string.h>

static mrb_value
mrb_unicode_display_width(mrb_state *mrb, mrb_value self)
{
  mrb_value obj;
  char *old_locale, *saved_locale, *str;
  int width;
  size_t wlen;
  wchar_t *wstr;

  mrb_get_args(mrb, "S", &obj);

  old_locale   = setlocale(LC_CTYPE, NULL);
  saved_locale = strdup(old_locale);

  // TODO: Windows has no unicode locales :´(
  setlocale(LC_CTYPE, "en_US.UTF-8");

  str  = RSTRING_PTR(obj);
  wlen = mbstowcs(NULL, str, 0);

  wstr = (wchar_t *)malloc(sizeof(wchar_t) * (wlen + 1));
  mbstowcs(wstr, str, wlen);

  width = mk_wcswidth(wstr, wlen);

  setlocale (LC_CTYPE, saved_locale);
  free (saved_locale);
  free(wstr);

  return mrb_fixnum_value(width);
}

void
mrb_mruby_unicode_display_width_gem_init(mrb_state* mrb)
{
  struct RClass *uc, *dw;

  uc = mrb_define_module(mrb, "Unicode");
  dw = mrb_define_module_under(mrb, uc, "DisplayWidth");

  mrb_define_class_method(mrb, dw, "of", mrb_unicode_display_width, MRB_ARGS_REQ(1));
}

void
mrb_mruby_unicode_display_width_gem_final(mrb_state* mrb)
{
  // Nothing to do here
}
