# MIT License
#
# Copyright (c) 2017 Sebastian Katzer
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

assert 'east asian width' do
  assert_equal 2, 'ä '.display_width
  assert_equal 2, '一'.display_width
  assert_equal 1, 'À'.display_width
  assert_equal 1, 'A'.display_width
  assert_equal 1, '｡'.display_width
end

assert 'zero width' do
  assert_equal 0, 'ֿ'.display_width
  assert_equal 0, '҈'.display_width
  assert_equal 0, '​'.display_width
  assert_equal 0, 'ᅠ'.display_width
end

assert 'special characters' do
  assert_equal 0, "\0".display_width
  assert_equal 0, "\x05".display_width
  assert_equal 0, "\a".display_width
  # assert_equal 3, "aaaa\b".display_width TODO: 3 != 4
  assert_equal 0, "\b".display_width
  assert_equal 0, "\n".display_width
  assert_equal 0, "\v".display_width
  assert_equal 0, "\f".display_width
  assert_equal 0, "\r".display_width
  assert_equal 0, "\x0E".display_width
  assert_equal 0, "\x0F".display_width
  assert_equal 0, "\x10".display_width
  assert_equal 1, '­'.display_width
  assert_equal 2, '⸺'.display_width
  assert_equal 3, '⸻'.display_width
end
