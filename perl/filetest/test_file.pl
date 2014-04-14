#!/usr/bin/perl -w


# -r F/D  OOOrOOrOO current user
# -w F/D  OOOOwOOwO current user
# -w F/D  OOOOOxOOx current user
# -o F/D  own by current user
# -R F/D  OOOrOOrOO real user
# -W
# -X
# -O
# -e F/D  is existed
# -z F    is existed and no content (For Directory this is False)
# -s F/D  is is existed and has content   Return sum in Byte
# -f F    is normal
# -d D    is normal
# -l      is link
# -S F    is Socket
# -p F    is FIFO/named pipe
# -b F    is block device
# -c F    is character device
# -u F/D  is SUID
# -g F/D  is SGID
# -k F/D  is sticky
# -t F    is tty
# -T F    looks like a text file
# -B F    looks like a binary file
# -M F    last modify till today
# -A F    last visit till today
# -C F    last inode change till today


# if (-r $file and -w _)    stat not twice
#
# use 5.010
# if (-w -r $file)    test like a stack -r will test first


# stat lstat
# my ($dev, $ino, $mode, $nlike, $uid, $gid, $rdev, $size, $atime, $mtime, $ctime, $blksize, $blocks) = stat($filename);
# $dev $ino device No and iNode No.
# $mode rwx bits
# $nlink hard links.
# $uid $gid user and group id
# $size file size in bytes
# $atime $mtime $ctime 32 integer of systemtime

# localtime change 32 integer into readable
my $timestamp = 1180630098;
my $date = localtime $timestamp;
print $date, "\n";
# gmtime Greewich time
my $now = gmtime;
print $now, "\n";

#bitwise operator
#& | ^ << >> ~
