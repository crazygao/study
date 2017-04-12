#!/usr/bin/env bash

function convert_file {
  infile=$1
  outfile=`echo $infile | sed 's/\.md$/\.html/'`
  echo "Converting $infile to $outfile... "
  ./Markdown.pl $infile --html4tag >> $outfile
}

for md in *.md; do
  convert_file $md
done
