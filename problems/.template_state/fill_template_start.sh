#!/bin/bash
dateformat="+%a %d %b %Y @ %R (%Z)";

echo "Using path: $1"

while read ln; do
  echo $ln | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    | sed "s/\[\!meta\:srcpath\!\]$/(${1//\//\\/})/g"\
    | sed "s/\[\!meta\:beg\!\]$/$(date "$dateformat")/g"
done