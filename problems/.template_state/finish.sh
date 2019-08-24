#!/bin/bash

newpath="$(dirname $1)/x$(basename $1)"
mv "$1" $newpath

./commit.sh $newpath "script: AC $newpath"
#./git_push.sh "script: finish $1/$2"
