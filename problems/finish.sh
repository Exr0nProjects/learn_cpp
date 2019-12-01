dateformat="+%a %d %b %Y @ %R (%Z)"
cache="./.template_state/last.txt"
modpath=$1

if [[ -z "$1" || "$1" == "_last" ]]; then
  modpath=$(< "$cache")
fi

echo "Marking $modpath as AC..."

newpath="$(dirname $modpath)/x$(basename $modpath)"
mv $modpath $newpath

cat "$modpath/main_$(basename $modpath).cpp"\
    | sed "s/\[\!meta\:end\!\]$/$(date "$dateformat")/g"\
    > "$newpath/main_$(basename $modpath).cpp"

rm -rf "$modpath"

./list_completed.sh

"$(dirname $cache)/live_commit.sh" "./$modpath ./$newpath working.txt completed.txt" "AC $modpath (script)"