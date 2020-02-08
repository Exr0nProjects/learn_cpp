# Contest usaco/silver/2016open - played Fri 7 Feb 2020 @ 16:53 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:54 | start | reading problems
17:08 | have plans for 2, 3 | coding #3
17:26 | 1/10 #3 | coding #2
17:49 | 2/10 #2 | debugging #2
17:56 | 7/10 #2 | debugging #3
18:03 | AC #3 | analysing #1
18:14 | planning to write a bashy N^3 #1 | analysing #1
18:16 | have backtracking bash plan | coding #1
18:44 | it says `sizeof(long long)` is 8 but setting one to `1<<31` gets a negative?? | coding #1
18:54 | variable name typo, 6/10 #1, others WA not TLE | debugging #1
18:59 | AC #1, was shifting implicit `int(1)` instead of `(long long)(1)` | debugging #2
19:10 | I still don't know whats wrong | end

## Purify Notes

### Problem 1: reduce

The [USACO soln](http://usaco.org/current/data/sol_reduce_silver_open16.html) tests each of the 256 possible cow reductions to see if it works, which has a lower complexity than my backtracking DFS. Technically, I think my backtracking DFS would fail if all the cows were on a line paralell to an axis, but it still got accepted within the time limit.

### Problem 2: diamond

The only method I could come up with, where you first fill one case and then the second in O(N) each, is different from the [USACO soln](http://usaco.org/current/data/sol_diamond_silver_open16.html) on a fundamental level. **Needs Work**

### Problem 3: closing

I wrote basic disjoint set union with combine minimum, with a final complexity of `N*(M+N)`. By going backwards and adding to the disjoint set intsead of rebuilding it, the [USACO soln](http://usaco.org/current/data/sol_closing_silver_open16.html) achieves a complexity of only `M+N`.
