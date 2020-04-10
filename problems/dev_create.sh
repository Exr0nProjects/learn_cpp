#!/bin/zsh
cache="./.template_state/last.txt"

dateformat="+%a %d %b %Y @ %R (%Z)";

mkdir -p $1

[[ -s "$1/main_$(basename $1).cpp" ]] ||\
    cat ./.template_state/defines_test.cpp\
    | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    | sed "s/\[\!meta\:srcpath\!\]/${1//\//\\/}/g"\
    | sed "s/\[\!meta\:beg\!\]/$(date "$dateformat")/g"\
    >> "$1/main_$(basename $1).cpp"
echo "$1" > "$cache"
./list_completed.sh

cat ./.template_state/Makefile\
    | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    >> "$1/Makefile"

COMMAND='cd $1 && echo hi && tmux split-window -h && PROB=$(basename $1) && source $ENVROOT/set_env.zsh && tmux selectp -L && nvim "main_$(basename $1).cpp" -c "execute \"normal /-1;/\" | normal \"ggnn\" | noh"'

echo "$COMMAND"

tmux new-window -n "$(basename $1)" "$COMMAND"

#[[ -s "$1/main_$(basename $1).cpp" ]] && printf "File exists!\n" | exit 1
