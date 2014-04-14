#!/usr/bin/perl
use strict;
use warnings;

print &max(3, 5, 10, 4, 6);

sub max {
	###Care Of NULL inputs
	my $max_so_far = shift @_;
	foreach(@_) {
		if ($_ > $max_so_far) {
			$max_so_far = $_;
		}
	}
	$max_so_far;
}
