#!/bin/zsh

export ENVROOT=$(dirname "$(realpath -s "$0")")
tmux setenv ENVROOT $ENVROOT

#tmux setenv IDEMODE 0
#export IDEMODE=0
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ -std=c++11 answer*.cpp -o answer && ./answer && cat *.out'
alias check='for (( i=1; ; i++ )); do py gen.py > test.in && ./auto < test.in > test.diff && ./answer < test.in > correct.diff && echo -en "\rtest case $i" && [[ -z "$(diff --brief *.diff)" ]] || break; done'
alias clean='setopt +o nomatch && rm -f auto *.in *.out answer *.diff'

