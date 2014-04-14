#!/usr/bin/perl
use strict;
use warnings;

$_ = "He's out bowling with Barney tonight.";
s/Barney/Fred/;
print "$_\n";

s/with (\w+)/against $1's team/;
print "$_\n";

#return bool, true on match and replaced
$_ = "fred flintstone";
if (s/fred/wilma/) {
	print "Successfully replaced fred with wilma!\n";
}

#/g go through all possible, not repeated replacement
$_ = "home, swee home!";
s/home/cave/g;
print "$_\n";

#reduce blanks: s/\s+/ /g;
#reduce beginning blanks: s/^\s+//g;
#reduce ending blanks: s/\s+$//g;

#we could use s###
#or s{}{} s[]() s<>##

#/i /x /s are also useful

#=~ is remained

#Upper and lower transfer
#To Upper \U
$_ = "I saw Barney with Fred.";
s/(fred|barney)/\U$1/gi;
print "$_\n";
#To Lower \L
s/(fred|barney)/\L$1/gi;
print "$_\n";
#Normal \E
s/(\w+) with (\w+)/\U$2\E with $1/i;
print "$_\n";
#\l \u will change only the letter after
#It's ok to use both \u\L: first letter Upper

#split, string to Arrays @fields = split /separator/, $string;
my @fields = split /:/, "abc:def:g:h";
print "@fields\n";

@fields = split /\s+/, "This is a \t       test.\n";
print "@fields\n";
#join, arrays to string, join $glue, @array
my $x = join ":", 4, 6, 8, 10, 12;
my @values = split /:/, $x;
my $z = join '-', @values;
print "$z\n";

#m// in arrays
$_ = "Hello there, neighbor!";
my ($first, $second, $third) = /(\S+) (\S+), (\S+)/;
print "$second is my $third\n";
