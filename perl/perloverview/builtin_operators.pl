#!/usr/bin/perl
use strict;
use warnings;

#Arithmetic
print "+", 1+2, " -", 1-2, " *", 1*2, " /", 1/2, "\n";
#Numeric comparison
print "==", 1==1, " !=", 1!=3, " <", 1<2, " >", 1>2, " <=", 1<=2, " >=", 1>=2, "\n";
#String comparation
print "eq", "ab" eq "ab";
print " ne", "ab" ne "bc";
print " lt", "10" lt "2";
print " gt", "2" gt "10";
print " le", "ab" le "abc";
print " ge", "abc" ge "ab", "\n";
#Boolean logic
#omitted
# = assignment
# . string concation
# x string multiplication
# .. range operator
print "abc" . "bcd";
print "abc" x 3;
