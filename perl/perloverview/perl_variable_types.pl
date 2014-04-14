#!/usr/bin/perl
use strict;
use warnings;

#Perl has three types of variables: scalars, arrays, hashes.
###### Scalars
my $animal = "camel";
my $answer = 42;

#Scalars: strings, integers, floats. automatically-convert
#Must use my, because use strict
#Scalar could be used in various ways:
print $animal;
print "The animal is $animal\n";
print "The square of $answer is", $answer * $answer, "\n";
#"Magic" scalars:
####################Perlvar
#$_ is default variable
print;

###### Arrays
# a list of values
my @animals = ("camel", "llama", "owl");
my @numbers = (23, 42, 69);
my @mixed = ("camel", 42, 1.23);
# Arrays are zero indexed
print $animals[0];
print $animals[1];
# $#array is the last element of the array
print $mixed[$#mixed];
# use @array instead of "$#array + 1" for array size
if (@animals < 5) {
	print "Array Animal less than 5\n";
}

# get multipul values from an array:
print @animals[0,1];
print @animals[0..2];
print @animals[1..$#animals];
# some functions useful:
my @sorted = sort @animals;
print @sorted, "\n";
my @backwards = reverse @numbers;
print @numbers, "\n";
#"Special" Arrays
####################Perlvar
# @ARGV, cmd lines; @_, arguments of subroutines


######Hashes
# a set of key/value pairs:
my %fruit_color = ("apple", "red", "banana", "yellow");
# this equals
# my %fruit_color = (
#	apple => "red",
#	banana => "yellow",
# );
# To get at hash elements
print $fruit_color{"apple"}, "\n";
# To get a list of keys and values with keys() and values()
my @fruits = keys %fruit_color;
my @colors = values %fruit_color;
print @fruits, "\n";
print @colors, "\n";
#Special Hashes
#
##################Perlvar
#%ENV

##################Perldata

######Reference
#scalar value refer to any other perl data type.

my $variables = {
	scalar => {
		description => "single item",
		sigil => '$',
	},
	array => {
		description => "ordered list of items",
		sigil => '@',
	},
	hash => {
		description => "key/value pains",
		sigil => '%',
	},
};
print "Scalars begin with a $variables->{'scalar'}->{'sigil'}\n";
################Perlreftut, perllol, perlref, perldsc
