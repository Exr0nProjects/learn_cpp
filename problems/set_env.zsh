#!/bin/zsh

ENVROOT=$(pwd)
tmux setenv IDEMODE 0
export IDEMODE=0
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ answer.cpp -o answer && ./answer && cat *.out'

