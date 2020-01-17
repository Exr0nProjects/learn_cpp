# Unsolved Problems

## Still unsolved

**These problems have yet to be solved.**

There's nothing here right now! (That probably means I should do another contest.)

## Badly needs purification

Nothing here yet.

## Takeaways and Rewrites

**These problems were examples of things that can go wrong and what to take away it.**

| Problem | Notes |
|----|----|
[2015dec lightson](./2015dec/xlightson/xmain_lightson.cpp) | Didn't know how to search while gaurenteeing visiting all locations. Soln checks each location when first switched on, and visits chains so that connecting a new lighted reigon gets visited by chaining.
[2016jan angry](./2016jan/xangry/xnew_angry.cpp) | Didn't think of binary searching for `R`
[2016jan div7](./2016jan/xdiv7/xmain_div7.cpp) | Didn't understand how to use prefix trees with modulo, or notice that two prefixes with same mod 7 meant interval between them was a multiple of 7.
[2016feb balancing](./2016feb/xbalancing/xnew_balancing.cpp) | Didn't know how to count cows in each quadrant given a fence crossing, but the Usaco soln uses a running count as it sweeps the vertical fence across, thus obtaining `O(n^2)` complexity instead of my original `O(n^3)`.
[2016feb cbarn](./2016feb/xcbarn/xnew_cbarn.cpp) | Wrote based on [thecodingwizard's soln](https://github.com/thecodingwizard/competitive-programming/blob/master/USACO/2016feb/gold/cbarn.cpp), which uses a queue and is more understandable than [the usaco soln by Mark Gordon](http://usaco.org/current/data/sol_cbarn_gold_feb16.html).
[2016dec moocast](./2016dec/xmoocast/xmain_moocast.cpp) | All the test cases (except sample) were RE when grading due to a faulty base case in the `dfs`. The problem was setting the `vis[s]` to true _after_ the recursive calls, but did not appear with the small test cases I was using. **If many REs: check base case, try larger test cases**.
