BIT Small Essay Questions

Please answer the following questions after you go through the homeworks and class videos we recently had. Please think very carefully about the following questions. You should try to summarize the principles behind topics.

**What's binary indexed tree?**

It's a way of grouping ranges together (like segment tree or sparse table) that stores the groups directly instead of different layers with progressively smaller ranges. That means its better suited for combining operations that you can "undo", like addition or xor, and not min or max because you cannot "undo" them as easily so you can't get a min range or max range from a prefix min/max array.

**What's the idea behind it?**

The idea is to group ranges together so that a range query can take advantage of contiguous segments without having to go into each one seperately.

**How does binary indexed trees help with problem solving? What type of questions can be solved by BIT?**

BIT directly solves range update and query questions, such as "how many before" or counting inversions. It is basically dynamic prefix sum--you have a prefix sum that you can query before you finish building. Thus, it can be used in all prefix sum problems.

**What's the most important operations that BIT supports? How to do each of them with BIT? Please write equations, and be as specific as possible.**

Query: `prefix[i] = rangesum[i] + prefix[i&-i]`  
Update: we need to update the ranges that cover `i`, so that's `for (j=i; j<=N; j+=j&-j)`

Range update point query: instead of storing a prefix sum of the array, we store a prefix sum of all the points. Similar to taking the integral (prefix sum) of the derivitive (delta array that is stored in a BIT).  
Query is the same as normal range query point update BIT, but with the `delta` array instead of the normal `bidx` one. (same logic, different semantics).  
Update is slightly different: `update(l, r)` preforms point update at `l` with `+=v` and point update at `r+1` with `-=v`.

Range update range query:  
Relies on algebraic transformations to derive, although there should be a geometric proof...

Given arrays `a[MX]` (original input array), we create new arrays `d[MX]` (delta array, `d[i] = a[i] - a[i-1]`) and `p[i]` (helper array, stores `p[i] = i*d[i]`). Query operations query the imaginary `s[i]` (prefix sums, `s[i] = a[i] + a[i-1] + a[i-2] + ... + a[1]`).  
We see that `a[i]` = `d[1] + d[2] + d[3] + ... + d[i]`. Thus,  
```
s[i] = a[1] + a[2]          + a[3]                 + ... + a[i]
     = d[1] + (d[1] + d[2]) + (d[1] + d[2] + d[3]) + ... + (d[1] + d[2] + d[3] + ... + d[i])
	 = i*d[1] + (i-1)*d[2] + (i-2)*d[3] + ... + (i-(i-1))*d[i]
	 = (i+1)*(d[1] + d[2] + d[3] + ... + d[i]) - (1*d[1] + 2*d[2] + 3*d[3] + ... + i*d[i])
```  
Notice that the last equation is comprised of two prefix sums from `1..i` over the two arrays we defined earlier. Thus, we can do this query as `(i+1)*prefix(d, i) - prefix(p, i)`, which our normal BIT already supports.

To do range update, we just have to update the `d` and `p` array/BITs, and we already know how to update `d`:
`update(l, r): d[l] += v, d[r+1] -= v;`  
Because `p[i] = i*d[i]`, when we update `d[i]` by `v` we have to update `p[i]` by `i*v`. Thus, we stick an extra `; p[l] += l*v; p[r+1] += (r+1)*-v` onto `update(l, r)` and we're done.

For each range update/query combo in higher dimensions, you have to use PIE to make sure you only update the range that you want.
Additionally, higher dimensional BITs are kind of just a bunch of BITs stacked on top of eachother and rotated, so that each dimensional is a normal 1d BIT.

**How many different types of usages have you seen for BIT? For example, ping pong problem is a very typical usage of BIT, but not the most trivial one.**

1. Range update/query problems
1. Rolling less than/greater than (counting inversions, can also use `getRank` treap)
1. Assigning indicies (binary search over the BIT, see poj2182 Lost Cows)

