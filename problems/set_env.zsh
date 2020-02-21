#!/bin/zsh

# set command line env for competitive programming
source $ZSH_CUSTOM/../dontrun_custom/laptop_config.zsh

ENVROOT=$(pwd)
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ answer.cpp -o answer && ./answer && cat *.out'

