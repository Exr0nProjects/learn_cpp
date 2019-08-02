dateformat="+%a %d %b %Y @ %R %Z";

#git pull

mkdir -p $1

[[ -s "$1/main.cpp" ]] ||\
  cat ./template.cpp\
    | sed "s/\[\!meta\:pid\!\]$/$(basename $1)/g"\
    | sed "s/\[\!meta\:date\!\]$/$(date "+%a %d %b %Y @ %R %Z)")/g"\
    >> "$1/main.cpp"
    
[[ -s "$1/main.cpp" ]] && printf "File exists!\n" | exit 1

#./git_push.sh "script: creating new problem: $1"
