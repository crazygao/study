#!/usr/bin/perl
use strict;
use warnings;

#open() function to open a file
###############perlfunc, perlopentut
open(my $in, "<", "input.txt") or die "Can't open input.txt: $!";
# or is || but it has a lower priority than || and =
# $! maybe last warning, like strerror(errno)
open(my $out, ">", "output.txt") or die "Can't open output.txt: $!";
open(my $log, ">>", "my.log") or die "Can't open my.log: $!";

#use <> operator to read from an opened filehandle.
#$ could read a line.
#@ could read the whole file
my $line = <$in>;
print $line;
my @lines = <$in>;
print @lines;
#the latter could be memory hog
#MEMORY: the file pointer doesn't go back in this example

while (<$in>) { #assigns each line in turn to $_
	print "Just read in this line: $_\n";
	print $out $_;
}

#extra option of print
print STDERR "This is your final warning.\n";
print $log "This is a log";

#close after use it
close $in or die "Closing $in: $!";
