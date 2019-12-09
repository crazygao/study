#!/usr/bin/perl
use strict;
use warnings;

#invocation arguments are files!
#'-' is special, it represents STDIN

while (defined(my $line = <>)) { #every line in every file, if empty, STDIN
	#different file name will represent difference in $ARGV, this is not the length of @ARGV
	chomp($line);
	print "It was $line that I saw!\n"
} 
