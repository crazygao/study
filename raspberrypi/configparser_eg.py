#!/usr/bin/python

# https://docs.python.org/2/library/configparser.html
# config file like windows ini file.
# 1. Config consist of sections, [section]
# 2. Items like this, name: value , name=value
# 3. Lines start with '#' or ';' are ignored
# 4. SafeConfigParser allow interpolation: values can contain format strings %(name) refer to other value IN THE SAME SECTION, or in [DEFAULT].

import ConfigParser

config = ConfigParser.SafeConfigParser()

config.add_section('Section1')
config.set('Section1', 'an_int', '15')
config.set('Section1', 'a_bool', 'true')
config.set('Section1', 'a_float', '3.1415')
config.set('Section1', 'baz', 'fun')
config.set('Section1', 'bar', 'Python')
config.set('Section1', 'foo', '%(bar)s is %(baz)s!')

with open('example.cfg', 'wb') as configfile:
    config.write(configfile)
