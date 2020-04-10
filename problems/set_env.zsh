#!/bin/zsh

export ENVROOT=$(dirname "$(realpath -s "$0")")
tmux setenv ENVROOT $ENVROOT

tmux setenv IDEMODE 0
export IDEMODE=0
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ answer.cpp -o answer && ./answer && cat *.out'
alias check='py gen.py | tee >(./auto > a.diff) >(./answer > b.diff) && [[ ! -z "$(diff --brief *.diff)" ]] && v -d *.diff'

