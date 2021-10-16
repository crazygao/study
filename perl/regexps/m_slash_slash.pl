#!/usr/bin/perl
use strict;
use warnings;
# m// m() m<> m{} etc... to match
# it's the same with //

# Optional modifier
# /i no upper or lower case
print "Would you like to play a game? ";
chomp($_ = <STDIN>);
if (/yes/i) {
	print "Go bowling!\n";
}
# /s for any chars
# because . could not match \n
$_ = "I saw Barney\ndown at the bowling alley\nwith fred\nlast night.\n";
if (/Barney.*fred/s) {
	print "String metion fred after Barney!\n";
}
#/x dismiss all spaces in regexp
# /-?\d+\.?\d*/ =
# /
#  -? #0..1 '-'
#  \d+ #1.. numbers
#  \.? #0..1 '.'
#  \d* #0.. numbers
# /x #end of string

#Hooks
# ^ $
# \b hook for word eg. /\bfork\b/

# =~
my $some_other = "I dream of betty rubble.";
if ($some_other =~/\brub/) {
	print "Aye, there's the rub.\n";
}

#insert values into match string

#Capture matched parentheses
$_ = "Hello there, neighbor";
if (/\s(\w+),/) {
	print "The word was $1\n";
}
if (/(\S+) (\S+), (\S+)/) {
	print "words are $1 $2 $3\n";
}

$_= "brontosaurus BBQburger";
#No capture mode of parentheses
if (/(?:bronto)?saurus (?:BBQ)?(steak|burger)/) {
	print "Fred wants a $1\n";
}

#5.010 ?<Label> $+Label
use 5.010;
my $names = 'Fred or Barney';
if ($names =~ m/(?<name1>\w+) (?:and|or) (?<name2>\w+)/) {
	say "I saw $+{name1} and $+{name2}";
}
#They can be used in g{} 
#in 5.010 \k<label> = \g{label}

# $& :match string, $`: match before $': match after

if ("Hello there, neighbor" =~ /\s(\w+),/) {
	print "That was ($`)($&)($').\n";
}

# a{3, 5} match a 3 to 5 times

#priority
#1: (...), (?:...), (?<LABEL>...)
#2: a* a+ a? a{n,m}
#3: abc ^a a$
#4: a|b|c
#5: a [abc] \d \1
