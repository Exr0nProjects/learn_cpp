# Test treap codes

Compile codes into `auto` and `answer`.

## Basic: insert, remove, query

Use `gen_basic.py`:
```
py gen_basic.py | pbcopy							# get test case
cat | tee >(./auto > a.diff) >(./answer > b.diff)	# run test case
v -d *.diff 										# compare results
rm answer auto *.dif 								# clean up
```

