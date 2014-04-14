#!/usr/bin/perl
use strict;
use warnings;

# simple matching
my $a = "abcdefoofoofoo";
if ($a =~ /foo/) { print "foo matches\n"; } # for simple when $_ is defined, if (/foo/)
############### perlop
# simple substitution
$a =~ s/foo/bar/; #replace first foo with bar in $a
print $a, "\n";
$a =~ s/foo/bar/g;#replace all
print $a, "\n";
# More complex regualr expressions
# . a single character
# \s a whitespace
# \S non-whitespace
# \d 0..9
# \D not \d
# \w a..z A..Z 0..9 _
# \W not \w
# [aeiou] match ONE LETTER
# [^aeiou] match NONE LETTER
# (foo|bar|baz) match ONE STRING
# ^ start of line
# $ end of line
#
#Qualifiers of HOW MANY
# * 0..X
# + 1..X
# ? 0..1
# {3} EXACTLY 3
# {3, 6} 3..6
# {3,} 3..X

$a = "123abc";
print "$a: string starts with one or more digits\n" if ($a =~ /^\d+/);
$a = "";
print "$a: string contains nothing\n" if ($a =~ /^$/);
$a = "a1 2 3  2354 4";
print "$a: string with 3 number followed with 3 space\n" if ($a =~ /(\d\s){3}/);
$a = "a1a3asdfsdf";
print "$a: string with ..aXaX.. series\n" if ($a =~/(a.)+/);

#capture the results of the regexp match for later use.
#in $1, $2

my $email = 'gaoylss08@gmail.com';
if ($email =~ /([^@]+)@(.+)/) {#not a @ start, @in the middle, and any words in the latter. FOR THE FIRST TIME
	print "Username is $1\n";#gaoylss, first part in the regexp
	print "Hostname is $2\n";#gmail.com
}

###########perlrequick, perlretut, perlre
