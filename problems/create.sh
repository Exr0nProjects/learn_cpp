#!/bin/bash
cache="./.template_state/last.txt"

dateformat="+%a %d %b %Y @ %R (%Z)";


mkdir -p $1

[[ -s "$1/main_$(basename $1).cpp" ]] ||\
  cat ./.template_state/defines_test.cpp\
    | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    | sed "s/\[\!meta\:srcpath\!\]$/(${1//\//\\/})/g"\
    | sed "s/\[\!meta\:beg\!\]$/$(date "$dateformat")/g"\
    >> "$1/main_$(basename $1).cpp"\
  && echo "$1" > "$cache"\
  && ./list_completed.sh 
[[ -s "$1/main_$(basename $1).cpp" ]] && printf "File exists!\n" | exit 1
