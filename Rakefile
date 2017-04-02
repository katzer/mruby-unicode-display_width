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

MRUBY_CONFIG = File.expand_path(ENV['MRUBY_CONFIG'] || 'build_config.rb')

file :mruby do
  sh 'git clone --depth 1 git://github.com/mruby/mruby.git'
end

desc 'compile binary'
task compile: :mruby do
  sh "cd mruby && MRUBY_CONFIG=#{MRUBY_CONFIG} ruby minirake all"
end

desc 'test'
task test: :mruby do
  sh "cd mruby && MRUBY_CONFIG=#{MRUBY_CONFIG} ruby minirake test"
end

desc 'cleanup'
task :clean do
  sh 'cd mruby && ruby minirake deep_clean'
end
