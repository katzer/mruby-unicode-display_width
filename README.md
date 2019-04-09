# Unicode::DisplayWidth ___for mruby!___ <br> [![Build Status](https://travis-ci.com/appPlant/mruby-unicode-display_width.svg?branch=master)](https://travis-ci.com/appPlant/mruby-unicode-display_width) [![Build status](https://ci.appveyor.com/api/projects/status/gyyr55n46at2regc/branch/master?svg=true)](https://ci.appveyor.com/project/katzer/mruby-unicode-display-width/branch/master)

Determines the monospace display width of a string in Ruby. Implementation inspired by [unicode-display_width][unicode-display_width] and based on http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c from the University of Cambridge.

## Installation

Add the line below to your `build_config.rb`:

```ruby
MRuby::Build.new do |conf|
  # ... (snip) ...
  conf.gem 'mruby-unicode-display_width'
end
```

Or add this line to your aplication's `mrbgem.rake`:

```ruby
MRuby::Gem::Specification.new('your-mrbgem') do |spec|
  # ... (snip) ...
  spec.add_dependency 'mruby-unicode-display_width'
end
```

## Usage

The interace follows [unicode-display_width][unicode-display_width]. However custom overwrites nor the 2nd parameter for ambiguous values aren't supported. 

```ruby
Unicode::DisplayWidth.of("⚀") # => 1
Unicode::DisplayWidth.of("一") # => 2
```

With String Extension:

```ruby
'⚀'.display_width #=> 1
'一'.display_width #=> 2
```

## Development

Clone the repo:
    
    $ git clone https://github.com/appplant/mruby-unicode-display_width.git && cd mruby-unicode-display_width/

Compile the source:

    $ rake compile

Run the tests:

    $ rake test

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/appplant/mruby-unicode-display_width.

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## Authors

- Sebastián Katzer, Fa. appPlant GmbH

## License

The gem is available as open source under the terms of the [MIT License][license].

Made with :yum: in Leipzig

© 2017 [appPlant GmbH][appplant]

[unicode-display_width]: https://github.com/janlelis/unicode-display_width
[license]: http://opensource.org/licenses/MIT
[appplant]: www.appplant.de
