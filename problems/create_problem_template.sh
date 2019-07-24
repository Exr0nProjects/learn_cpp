dateformat="+%a %d %b %Y @ %R %Z";

git pull

cd $1
mkdir $2
cd $2

#cat ../../meta/template.cpp | sed -E "s/\[meta\:pid\]$/$2/g" | sed -E "s/\[meta\:date\]$/$(date "$dateformat")">> main.cpp

cat ../../meta/template.cpp >> main.cpp

cd ../..

./git_push.sh "script: creating new problem folder: $1 $2"
