#!/usr/bin/perl
use strict;
use warnings;

my $name = "Larry Wall";
print "Hello there, $name, did you know that?\n";
my @array = qw/ fred barney betty/;
print @array, "\n"; # no spaces, no flush buffers, to control buffer, MORE DOCUMENTS
print "@array\n";# with spaces
# brackets in print could be omitted, and act a little bit different from other subroutines!
# ATTENTION, brackets are often CONSTRUCTOR OF ARRAYS
# but print does not treat this!

print (2+3)*4; # output a 5, and the return value is multiple by 4(result is 4 and not saved)
print "\n";

#print for something standardrized
my $usrname = "Philip";
my $days_to_die = "2099";
printf "Hello, %s; your password expires in %d days!\n", $usrname, $days_to_die;
printf "%g %g %g\n", 5/2, 51/17, 51**17; # %g General
printf "%6d\n", 42;# autofill spaces
printf "%2d\n", 2e3 + 1.95; #not enough spaces, auto expand
printf "%10s\n", "wilma";
printf "%-15s\n", "flintstone"; # fill back with spaces
printf "%12.3f\n", 6*7 + 2/3;

#arrays and printf
#
