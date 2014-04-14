#!/usr/bin/perl
use warnings;
#use strict; #use this line and you could not initialize like this.
$family_name{"fred"} = "flintstone";
$family_name{"barney"} = "rubble";
foreach $person (qw< barney fred >) {
	print "I've heard of $person $family_name{$person}.\n"
}
$foo = "bar";
print $family_name{$foo . "ney"};

# => is ,
# reverse %hash is useful!!
# keys values
# each has a key in a hash
while ((my $key, my $value) = each %family_name) {
	print "$key => $value\n";
}

# exists
$books{"fred"} = 3;
$books{"wilma"} = 1;
if (exists $books{"dino"}) {
	print "Hey, there is a lib card for dino!\n";
}
#delete
delete $books{"wilma"};

# Hash cannot insert into strings directly!

#%ENV
print "PATH is $ENV{'PATH'}\n";
