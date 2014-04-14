#!/usr/bin/perl
use strict;
use warnings;

my @input_array;
my @reg_array;
while (<>) {
	my $AccessNO; # a new regexp
	my $FeatureStr;
	my %reg_elem;
	$AccessNO = chomp(<>);
	$FeatureStr= (chomp(<>) eq '(null)' ? "", $_); # null input
	if (chomp(<>) eq "1") {# ANCheckFlag
		$reg_elem{"ANReg"} = /\b$AccessNO\b/; # Accurate
	} else {
		$reg_elem{"ANReg"} = /$AccessNO/; # Not accurate
	}
	if (chomp(<>) eq "1") {# FSCheckFlag
		$reg_elem{"FSReg"} = /\b$FeatureStr\b/; #Accurate
	} else {
		$reg_elem{"FSReg"} = /$FeatureStr/; #Not accurate
	}
	push @reg_array $reg_elem;
}

while (1) {
	print "Input FeatureStr:\n";
	my $FSString = <STDIN>;
	for (my $i = 0; $i < $#reg_array; $i++) {
		$FSString = $reg_array[$i]->{"FSReg"};
	} 
}

foreach (@input_array) {
	if ("Anch")
}
