#!/usr/bin/perl
#This cannot run
#CGI protocol
use CGI qw(:all);
print header("text/plain");
foreach my $param(param()) {
	print "$param: " . param($param) . "\n"
}

#To use DBI ,you need DBD (DataBase Driver for Perl)
# OO module
use DBI;
$data_source = "dbi:Pg:dbname=XXXXXXX";
$dbh = DBI->connect($data_source, $username, $password);

$sth = $dbh->prepare("SELECT * FROM foo WHERE bla");
$sth->execute();
@row_ary = $sth->fetchrow_array;
$sth->finish;

$dbh->disconnect
