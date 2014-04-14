#!/usr/bin/perl

print "\nArithmetic Operators\n"
print ((3 + 2) * (5 - 3) / 2) #5

print qq/\nString Operators/; # concatenation
print "\tTommy" . ' '. "Savage";
print qq/Comparison Operators\n/;
print 5>=3, "\n";
print 47 ==23, "\n";

print qq/\nLogical Operators\n/;
$a > $b && $b < 100
$answer eq "yes" || $money == 200
