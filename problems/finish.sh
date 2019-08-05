cache="./.template_state/last.txt"
modpath=$1

if [ "$1" == "_last" ]; then
  modpath=`$(cat "$cache")`
fi

newpath="$(dirname $modpath)/x$(basename $modpath)"

mv "$modpath" "$newpath"

echo "$newpath" > "$cache"
./commit.sh $newpath "script: AC $newpath"
