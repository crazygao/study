#!/usr/bin/perl
use strict;
use warnings;

#Easy mode
$_ = "yabba dabba doo";
if (/abba/) {
	print "It matched\n";
}
#quantifier: * . + {1..2}
#Regexp group: ()
#\1 \2 to backward-reference

$_ = "abba";
if (/(.)\1/) {#match a sequence of two same char , bb
	print "It matched same character next to itself!\n"
}
$_ = "yabba dabba doo";
if (/y(....) d\1/) {
	print "It matched the same after y and d!\n";
}
#Palindrome 回文
if (/y(.)(.)\2\1/) {
	print "It mached a palindrome!\n";
}
#Sequence, count the left of bracket/parentheses
if (/y((.)(.)\3\2) d\1/) {
	print "Match almost whole!\n";
}

# a new way to write to avoid multi-meanings
use 5.010;
$_ = "aa11bb";
if (/(.)\g{1}11/) { # \111 is the 111st parentheses
	print "It matched!\n";
}
# use -1 in g{}, this is reference relative to current position! not
# absolute parentheses number.
if (/(.)\g{-1}11/) {
	print "It matched!\n";
}

#Match only one '|'
#/fred|barney|betty/

#char sets '[]', kind of enumeration
# [^sth]  ^ is reverse, must come first in the []
$_ = "The HAL-9000 requires authorization to continue.";
if (/HAL-[0-9]+/) {
	print "The string mentions some model of HAL computer.\n";
}
#some abbreviation
#\d [0-9]
#\w [A-Za-z0-9_]
#\s [\f\t\n\r ]
#\h [\t ]
#\v [\f\n\r]
#\R [CRLF] on any OS
