#!/bin/bash
git pull

mkdir $1

./git_push.sh "script: creating new page folder $1"
