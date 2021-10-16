#!/usr/bin/perl -w
use strict;
use 5.010;
# File::Spec is very good on different systems
use File::Spec;
my $path = File::Spec->catfile(qw{home Study perl filetest test_file.pl});
say $path;
# Path::Class is a Module that is DOWNLOADED
use Path::Class;
my $pcfile = file(qw{home Study perl filetest test_file.pl});
my $pcdir = dir(qw{home Suty perl filetest});

my $absfile = $pcfile->absoulte;
my @contents = $pcfile->slurp
$pcfile->remove();
