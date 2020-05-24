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

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

-

#### Problem 2:

-

#### Problem 3:

-

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
