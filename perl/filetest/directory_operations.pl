#!/usr/bin/perl -w

#cd change dir
chdir "/etc" or die "cannot chdir to /etc: $!";

#glob: find names in current directory
my @all_files = glob "*";
print "@all_files", "\n";

@all_files = <*>; # the same will glob
