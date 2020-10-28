#!/bin/zsh
cache="./.template_state/last.txt"

dateformat="+%a %d %b %Y @ %R (%Z)";

mkdir -p $1

[[ -s "$1/main_$(basename $1).cpp" ]] ||\
    #cat ./.template_state/template.cpp\
    cat ./.template_state/defines_everywhere.cpp\
    | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    | sed "s/\[\!meta\:srcpath\!\]/${1//\//\\/}/g"\
    | sed "s/\[\!meta\:beg\!\]/$(date "$dateformat")/g"\
    >> "$1/main_$(basename $1).cpp"
echo "$1" > "$cache"
./list_completed.sh

cat ./.template_state/Makefile\
    | sed "s/\[\!meta\:pid\!\]/$(basename $1)/g"\
    > "$1/Makefile"

#tmux new-window -n "$(basename $1)" "cd $1 && tmux split-window -v && PROB=$(basename $1) && tmux resizep -y 30 && tmux selectp -U && nvim 'main_$(basename $1).cpp' -c 'execute \"normal /-1;/\" | normal \"ggnn\" | noh'"
#tmux new-window -n "$(basename $1)" "cd $1 && tmux split-window -h && PROB=$(basename $1) && tmux selectp -L && nvim 'main_$(basename $1).cpp' -c 'normal 8Gzf58Gjf-'"

export PROB=$(basename $1)
cd $1
nvim main_$(basename $1).cpp -c "normal 8Gzf72Gjf-"

#[[ -s "$1/main_$(basename $1).cpp" ]] && printf "File exists!\n" | exit 1
