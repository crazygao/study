#!/usr/bin/perl
use strict;
use warnings;

chomp(my $line = <STDIN>);
while (defined($line = <STDIN>)) {
	print "I saw $line";
}

