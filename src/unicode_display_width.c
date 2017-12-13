/* MIT License
 *
 * Copyright (c) 2017 Sebastian Katzer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
