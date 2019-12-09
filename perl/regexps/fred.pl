#!/usr/bin/perl -w

use strict;

chomp(my $date = `date`); #System call
$^I = ".bak"; #backup origin file to *.bak

while (<>) {
	s/^Author:.*/Author: Randal L. Schwartz/;
	s/^Phone:.*\n//; #delete the line , of course the \n should be deleted
	s/^Date:.*/Date: $date/;
	print; # print back file
}

#in brief: perl -p -i.bak -w -e 's/Randall/Randal/g' fred*.dat
# -p: while (<>) {...;print;}
# -n: while (<>) {...;}
# -i.bak: $^I = ".bak"
# -w: use warnings
# -e: ... is replaced by these
# @ARGV
