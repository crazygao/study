#!/usr/bin/perl -w
$string = "Hello world";
$value = substr($string, 1, 3);
print $value, "\n";
$value = substr($string, 5);
print $value, "\n";
substr($string, 1, 3) = "le";
print $string, "\n";

#use with pattern
substr($string, 1, 3) =~ s/H/h/g;
print $string, "\n";
#Unpack
print "\n Unpack \n";
($b, $c) = unpack("x6 A2 X5 A2", $string);
print $leading, $s1, $s2, $trailing, "\n";
@fivers = unpack("A5" x (length($string)/5), $string);
print @fivers, "\n";
@chars = unpack("A1" x length($string), $string);
print @chars, "\n";
