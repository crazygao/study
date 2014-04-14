#!/usr/bin/perl
use strict;
use warnings;

#Scoping like C
my $x = "foo";
my $some_condition = 1;
if ($some_condition) {
	my $y = "bar";
	print $x;
	print $y;
}
print $x;
print $y; # bad on use strict;
