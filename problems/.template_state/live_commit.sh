pwd

for file in $1; do
    git add $file
done

git add ".template_state/last.txt"
git commit -m "$2"