# Contest contest/dated/2020_05_15 - played Sun 24 May 2020 @ 10:16 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
10:17 | start | reading problems
10:36 | have plans for 2, 3, need analyze 1, 4, don't understand 5 | analysing #1
10:39 | spent ten minutes sitting there confused | analysing #1
10:54 | at each index, go to end inserting into treap, getting difference between inserted and start. hard to code. | analysing #5
11:03 | sweep each range? memoize ranges to reduce computation? prolly too slow | analysing #5
11:13 | range sweep would be too slow.. not sure how to precompute. feels like a segtree problem but not sure how | analysing #5
11:16 | could be a segtree if I knew whether to expand into a range or not..? seems impossible tho | analysing #5
11:22 | each segtree node could store a "range best" and a "full range sum". how to calculate range best of a segtree node based on it's children? | analysing #5
11:27 | could do the linear sweep from the center outwards, but that makes the time complexity to build the segtree high: each layer needs O(N) so total becomes N+NlogN aka NlogN | analysing #5
11:31 | actually that might be fine | coding #1
11:45 | still not good at coding treap, segfaultt | coding #1
12:02 | submit #1, in judge queue | testing #1
12:05 | TLE #1 | idle
12:07 | basically trying to figure out what to do next | analysing #4
12:15 | idk how to do #4 | analysing #1 (alexd method)
12:34 | key: use less left and greater right to find how many pairs i can ref, can do that with 2 treap sweeps | analyzing how to do that with segtree
12:40 | confusion | walk
12:43 | walk | analysing #3
12:50 | dunno | end 2h 33m

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: [uva1428](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=4174&mosmsg=Submission+received+with+ID+25063553)
I was thinking about it as counting the number of refs for any given pair of players, but it's much easier to think of it as how many pairs can a player ref.
Using my first thinking I came up with an N^2 log N solution, but that TLE'd. After talking to AlexD I realized second method. Two treap sweeps shoud be enough, needs to be coded.

#### Problem 2: [uva1160](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3601)
connected components. Didn't code because I was supposed to do problems 1, 5 first

#### Problem 3: [uva11997](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3148)
I thought you could just sort and then bfs, but storing the state requires an array[k] which makes the entire thing K^3, too slow.
Not sure how to do this one...

#### Problem 4: [uva1328](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4074)
Not sure how to do this, smells like a trie though.

#### Problem 5: [uva1400](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4146)
Segment tree that stores best internal, left, right, and full segment sum.
Key insight is that you shouldn't even try taking a negative number unless the left of it is bigger (when sweeping left to right), because otherwise you'd be better off just cutting there.
Same can be applied right to left.
Might be annoying to code, but there's no range update so that's good.

### Strategy
I didn't really spend time coding during this contest, mostly because I wanted to figure out how to do the problems. I think I could've gotten #2 accepted and maybe #1, although not before I talked to alexd.

### Action item
Get better at analyzing for segtree. More segtree problems!

