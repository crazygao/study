#!/usr/bin/perl
use strict;
use warnings;
#Comment in Perl, Perl statements end in a semi-colon
print "Hello, world";
#Whitespace is irrelevant
print
    "Hello, world"
    ;
#...except in quoted strings:
print "Hello
world";
#double quotes quotes may be used around literal strings:
#but only double ones "interpolate" variables and special characters
my $name = 123;
print "Hello, $name\n";
print 'Hello, $name\n';
#Numbers doesn't need quotes
print 53;
#Use parenthese are allowed
print("Hello, world\n");
############# End intro for PERLSYN
