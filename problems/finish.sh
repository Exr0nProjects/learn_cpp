dateformat="+%a %d %b %Y @ %R (%Z)"
cache="./.template_state/last.txt"
modpath=$1

if [[ -z "$1" || "$1" == "_last" ]]; then
  modpath=$(< "$cache")
fi

echo "Marking $modpath as AC..."

newpath="$(dirname $modpath)/x$(basename $modpath)"
mkdir -p "$newpath";

cat "$modpath/main.cpp"\
    | sed "s/\[\!meta\:end\!\]$/$(date "$dateformat")/g"\
    > "$newpath/main.cpp"

# < "$modpath/main.cpp" > "$newpath/main.cpp"

#mv "$modpath" "$newpath"
rm -rf "$modpath"

echo "$newpath $cache"

./list_completed.sh

"$(dirname $cache)/live_commit.sh" "$modpath $newpath working.txt completed.txt" "AC $modpath (script)"