#!/usr/bin/perl -w

#qw={} qx=execute qq="" q=''
@states = qw(ME MT CA FL);
$today = qx(date);
print qq/Hello\n/;
print q/He owes $5.00/,"\n";

# Here-Doc
$text = 'Text from a Perl string.';
print <<HTML;
<html>
<head>
<title>Here-Doc Example</title>
</head>
<body>
<h1>Here-Doc Example</h1>
<p>$text</p>
</body>
HTML
