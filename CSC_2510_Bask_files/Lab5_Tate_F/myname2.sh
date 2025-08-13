#!/bin/bash

${TEMPDIR:=/tmp}

tempfile=$(mktemp "/tmp/$$.XXXXX --suffix name")

read -p "Enter a String: " name

echo $name > "$TEMPDIR/$$.name"

cat "$TEMPDIR/$$.name"

rm "$TEMPDIR/$$.name"
