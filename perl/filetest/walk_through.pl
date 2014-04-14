#!/usr/bin/perl -w
use strict;

#opendir readdir closedir
opendir my $DIR, '.' or die "Can't open the current directory: $!\n";
my @names = readdir $DIR or die "Unable to read current dir:$!\n";
print "@names\n";
closedir $DIR;

foreach my $name (@names) {
	next if ($name eq '.'); # skip the current directory entry
	next if ($name eq '..'); # skip the parent directory entry

	if (-d $name) { # is a directory , -d
		print "found a directory: $name\n";
		next;
	}
	if ($name eq 'core') { # a file named core
		print "found a core file!\n";
	}
}
