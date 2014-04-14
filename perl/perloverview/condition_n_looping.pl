#!/usr/bin/perl
use strict;
use warnings;

#####################Perlsyn
# if (condition) {} elseif (o_condition) {} else {}
# unless(condition) {} = if (!condition) {}
# while (condition) {}
# unless (condition) {} = while (!condition) {}

#modern ways in one line
my $zippy = 1;
print "Yow" if $zippy;
print "We have no bananas" unless $zippy;

#foreach for arrays
my @array = (1, 2, "123");
foreach(@array) { # This bracket could not be omitted
	print "This element is $_\n"; #subroutine "magic" scalars
}
print $array[$_] foreach 0..$#array;
#if you don't want to use $_
foreach my $key (@array) {
	print "This elem is $key\n";
}
