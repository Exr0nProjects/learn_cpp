cache="./.template_state/last.txt"
modpath=$1

if [[ -z "$1" || "$1" == "_last" ]]; then
  modpath=$(< "$cache")
fi

echo $modpath

newpath="$(dirname $modpath)/x$(basename $modpath)"

mv "$modpath" "$newpath"

echo "$newpath" > "$cache"
"$(dirname $cache)/live_commit.sh" "$newpath $cache" "script: AC $newpath"
