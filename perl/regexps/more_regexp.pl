#!/usr/bin/perl
use strict;
use warnings;

#non greedy quantitives
#+ => +? this is non-greedy
$_ = "I thought you said Fred and <BOLD>Velma</BOLD>, not <BOLD>Wilma</BOLD>";
#not match to the last
s#<BOLD>(.*?)</BOLD>#$1#g;
print;
print "\n";

#treat \n as $ and ^
#this is multiple lines /m
$_ = "I'm much better\nthanBarney is\nat bowling,\nWilma.\n";
print "Found 'wilma' at start of line\n" if /^wilma\b/im
