#!/bin/bash
pwd

for file in $1; do
    git add $file
done

git commit -m "$2"
