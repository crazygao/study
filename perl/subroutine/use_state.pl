#!/usr/bin/perl
use strict;
use warnings;
use 5.010; #must use this before use state
sub marine {
	state $n = 0;#static 
	$n += 1;
	print "Hello, sailor number $n\n";
}

marine;
marine;
marine;
