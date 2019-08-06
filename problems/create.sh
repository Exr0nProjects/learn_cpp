cache="./.template_state/last.txt"

dateformat="+%a %d %b %Y @ %R %Z";


mkdir -p $1

[[ -s "$1/main.cpp" ]] ||\
  cat ./.template_state/template.cpp\
    | sed "s/\[\!meta\:pid\!\]$/$(basename $1)/g"\
    | sed "s/\[\!meta\:date\!\]$/$(date "+%a %d %b %Y @ %R %Z)")/g"\
    >> "$1/main.cpp"
    
[[ -s "$1/main.cpp" ]] && printf "File exists!\n" | exit 1

echo "$1" > "$cache"

