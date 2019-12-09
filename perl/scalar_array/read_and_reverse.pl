#!/usr/bin/perl
use strict;
use warnings;
my $in;
if ($ARGV[1]) {
	open($in, "<", $ARGV[0]) or die "Can't open this: $!"; 
}

close($in) if ($ARGV[1]);
