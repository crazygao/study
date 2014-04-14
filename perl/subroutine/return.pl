#!/usr/bin/perl
use strict;
use warnings;

##Return will return sth immediately
my @names = qw/ fred barney bety dino wilma pebbles bamm-bamm /;
my $result = &which_element_is("dino", @names); #Forward Declaration

sub which_element_is {
	my($what, @array) = @_;
	foreach(0..$#array) { #every index.
		if ($what eq $array[$_]) {
			return $_; #return on find
		}
	}
	-1;
}
