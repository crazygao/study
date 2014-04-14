#!/usr/bin/perl
use strict;
use warnings;

#without return
sub logger {
	my $logmessage = shift; #shift @_; or my $logmessage = $_[0];
	# my ($logmessage, $priority) = @_; # I don't what is priority
	open(my $logfile, ">>", "my.log")or die "Could not open my.log: $!"; # FAIL here and with strange output
	print $logfile, $logmessage;
}

logger("We have a logger subroutine!");
#with return
sub square {
	my ($num, $priority) = @_;
	my $result = $num * $num;
	return $result;
}

print square(8);
###########perlsub

