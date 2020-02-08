# usaco/silver/overview.md

## Sector summary

The values in the confidence column below are internally relative, meaning that I feel twice as confident with something labeled `2` as with something labeled `1`. Note: **100 is not the maximum possible value.**

| Approach | Confidence (points) | Problems |
|----------|------------|----------|
Binary Search | 80 | [2016dec/haybales](2016dec/xhaybales/xmain_haybales.cpp), [2016dec/citystate](2016dec/xcitystate/xmain_citystate.cpp), [2017jan/cowdance](2017jan/xcowdance/xmain_cowdance.cpp)
Flood Fill | 100 | [2015dec/lightson](2015dec/xlightson/xmain_lightson.cpp), [2017feb/countcross](2017feb/xcountcross/xmain_countcross.cpp)
Basic Greedy | 95 | [2015dec/highcard](2015dec/xhighcard/xmain_highcard.cpp), [2016feb/cbarn](2016feb/xcbarn/xnew_cbarn.cpp), [2017feb/helpcross](2017feb/helpcross/main_helpcross.cpp)
Prefix Sums | 80 | [2015dec/bcount](2015dec/xbcount/xmain_bcount.cpp), [2016jan/div7](2016jan/xdiv7/xnew_div7.cpp), [2017jan/hps](2017jan/xhps/xmain_hps.cpp), [2017feb/maxcross](2017feb/xmaxcross/xmain_maxcross.cpp)
Generic DP | 95 | [2016feb/pails](2016feb/xpails/xmain_pails.cpp)
Graph Traversal | 100 | [2016dec/moocast](2016dec/xmoocast/xpurify_moocast.cpp)
Ad hoc/Simulation | 100 | [2016jan/angry](2016jan/xangry/xnew_angry.cpp), [2016jan/gates](2016jan/xgates/xmain_gates.cpp), [2016feb/balancing](2016jan/../2016feb/xbalancing/xnew_balancing.cpp), [2017jan/cowcode](2017jan/xcowcode/xmain_cowcode.cpp)

## Still unsolved

**These problems have yet to be solved.**

- [2016open diamond](./2016open/diamond/main_diamond.cpp)
- [2017feb helpcross](./2017feb/helpcross/main_helpcross.cpp)
- [2019dec meetings](./2019dec/meetings/main_meetings.cpp)
- [2020jan berries](./2020jan/berries/main_berries.cpp)
- [2020jan loan](./2020jan/loan/main_loan.cpp)

## Badly needs purification

Nothing here yet.

## Takeaways and Rewrites

**These problems were examples of things that can go wrong and what to take away it.**

| Problem | Notes |
|----|----|
[2015dec lightson](./2015dec/xlightson/xmain_lightson.cpp) | Didn't know how to search while gaurenteeing visiting all locations. Soln checks each location when first switched on, and visits chains so that connecting a new lighted reigon gets visited by chaining. **When it doubt, try it.**
[2016jan angry](./2016jan/xangry/xnew_angry.cpp) | Didn't think of **binary search**ing for `R`
[2016jan div7](./2016jan/xdiv7/xmain_div7.cpp) | Didn't understand how to use prefix sums with modulo, or notice that two prefixes with same mod 7 meant interval between them was a multiple of 7.
[2016feb balancing](./2016feb/xbalancing/xnew_balancing.cpp) | Didn't know how to count cows in each quadrant given a fence crossing, but the Usaco soln uses a **running count** as it sweeps the vertical fence across, thus obtaining `O(n^2)` complexity instead of my original `O(n^3)`.
[2016feb cbarn](./2016feb/xcbarn/xnew_cbarn.cpp) | Wrote based on [thecodingwizard's soln](https://github.com/thecodingwizard/competitive-programming/blob/master/USACO/2016feb/gold/cbarn.cpp), which uses a queue and is **more understandable** than [the usaco soln by Mark Gordon](http://usaco.org/current/data/sol_cbarn_gold_feb16.html).
[2016dec moocast](./2016dec/xmoocast/xmain_moocast.cpp) | All the test cases (except sample) were RE when grading due to a faulty base case in the `dfs`. The problem was setting the `vis[s]` to true _after_ the recursive calls, but did not appear with the small test cases I was using. **If many REs: check base case, try larger test cases**.
[2019dec milkvisits](./2019dec/xmilkvisits/xnew_milkvisits.cpp) | Didn't think of using simple disjoint set (dfs)
[2020jan wormsort](./2020jan/xwormsort/xmain_wormsort.cpp) | Didn't see as a disjoint set problem, the key realization is any cow can be sorted (through a series of swaps) if it is in the same disjoint set as its target position.
