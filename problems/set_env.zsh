#!/bin/zsh

ENVROOT=$(pwd)
# alias crt='cd $ENVROOT && source ./create.sh && vim main*'
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ answer.cpp -o answer && ./answer && cat *.out'

