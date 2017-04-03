# Unicode::DisplayWidth ___for mruby!___ [![Build Status](https://travis-ci.org/appPlant/mruby-unicode-display_width.svg?branch=master)](https://travis-ci.org/appPlant/mruby-unicode-display_width)

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

## Authors

- Sebastián Katzer, Fa. appPlant GmbH


## License

The gem is available as open source under the terms of the [MIT License][license].

Made with :yum: from Leipzig

© 2017 [appPlant GmbH][appplant]

[unicode-display_width]: https://github.com/janlelis/unicode-display_width
[license]: http://opensource.org/licenses/MIT
[appplant]: www.appplant.de
