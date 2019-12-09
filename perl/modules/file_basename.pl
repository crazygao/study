#!/usr/bin/perl -w
use strict;
use File::Basename qw/ basename /; # use basename and use File::Basename::dirname

#perldoc File::Basename
my $name = "/usr/local/bin/perl";
my $basename = basename $name;
print "$basename\n";

print "Please enter a filename: ";
chomp(my $old_name=<STDIN>);
print "$old_name\n";
my $dirname = File::Basename::dirname $old_name;
$basename = basename $old_name;

$basename =~ s/^/not/;
my $new_name = "$dirname/$basename";

rename($old_name, $new_name)
	or warn "Can't rename '$old_name' to '$new_name': $!";
