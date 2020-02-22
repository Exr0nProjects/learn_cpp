# usaco/silver/overview.md

## Sector summary

The values in the confidence column below are internally relative, meaning that I feel twice as confident with something labeled `2` as with something labeled `1`. Note: **100 is not the maximum possible value.**

| Approach | Confidence (points) | Problems |
|----------|------------|----------|
Binary Search | 80 | [2016dec/haybales](x2016dec/xhaybales/xmain_haybales.cpp), [2016dec/citystate](x2016dec/xcitystate/xmain_citystate.cpp), [2017jan/cowdance](x2017jan/xcowdance/xmain_cowdance.cpp)
Flood Fill | 100 | [2015dec/lightson](x2015dec/xlightson/xmain_lightson.cpp), [2017feb/countcross](x2017feb/xcountcross/xmain_countcross.cpp)
Basic Greedy | 95 | [2015dec/highcard](x2015dec/xhighcard/xmain_highcard.cpp), [2016feb/cbarn](x2016feb/xcbarn/xnew_cbarn.cpp), [2017feb/helpcross](x2017feb/xhelpcross/xnew_helpcross.cpp)
Prefix Sums | 80 | [2015dec/bcount](x2015dec/xbcount/xmain_bcount.cpp), [2016jan/div7](x2016jan/xdiv7/xnew_div7.cpp), [2017jan/hps](x2017jan/xhps/xmain_hps.cpp), [2017feb/maxcross](x2017feb/xmaxcross/xmain_maxcross.cpp)
Generic DP | 95 | [2016feb/pails](x2016feb/xpails/xmain_pails.cpp), [2019feb paintbarn](./x2019feb/xpaintbarn/xmain_paintbarn.cpp), [2016open diamond](./x2016open/xdiamond/xmain_diamond.cpp)
Graph Traversal | 100 | [2016dec/moocast](x2016dec/xmoocast/xpurify_moocast.cpp)
Ad hoc/Simulation | 100 | [2016jan/angry](x2016jan/xangry/xnew_angry.cpp), [2016jan/gates](x2016jan/xgates/xmain_gates.cpp), [2016feb/balancing](x2016feb/xbalancing/xnew_balancing.cpp), [2017jan/cowcode](x2017jan/xcowcode/xmain_cowcode.cpp)

## Still unsolved

**These problems have yet to be solved.**

Bold means that I don't yet understand the given solution.

- [2018feb teleport](./2018feb/teleport/main_teleport.cpp)

## Badly needs purification

Nothing here yet.

## Takeaways and Rewrites

**These problems were examples of things that can go wrong and what to take away it.**

| Problem | Notes |
|----|----|
[2015dec lightson](./x2015dec/xlightson/xmain_lightson.cpp) | Didn't know how to search while gaurenteeing visiting all locations. Soln checks each location when first switched on, and visits chains so that connecting a new lighted reigon gets visited by chaining. **When it doubt, try it.**
[2016jan angry](./x2016jan/xangry/xnew_angry.cpp) | Didn't think of **binary search**ing for `R`
[2016jan div7](./x2016jan/xdiv7/xmain_div7.cpp) | Didn't understand how to use prefix sums with modulo, or notice that two prefixes with same mod 7 meant interval between them was a multiple of 7.
[2016feb balancing](./x2016feb/xbalancing/xnew_balancing.cpp) | Didn't know how to count cows in each quadrant given a fence crossing, but the Usaco soln uses a **running count** as it sweeps the vertical fence across, thus obtaining `O(n^2)` complexity instead of my original `O(n^3)`.
[2016feb cbarn](./x2016feb/xcbarn/xnew_cbarn.cpp) | Wrote based on [thecodingwizard's soln](https://github.com/thecodingwizard/competitive-programming/blob/master/USACO/2016feb/gold/cbarn.cpp), which uses a queue and is **more understandable** than [the usaco soln by Mark Gordon](http://usaco.org/current/data/sol_cbarn_gold_feb16.html).
[2016open diamond](./x2016open/xdiamond/xmain_diamond.cpp) | Didn't realize why greedy wouldn't work
[2016dec moocast](./x2016dec/xmoocast/xmain_moocast.cpp) | All the test cases (except sample) were RE when grading due to a faulty base case in the `dfs`. The problem was setting the `vis[s]` to true _after_ the recursive calls, but did not appear with the small test cases I was using. **If many REs: check base case, try larger test cases**.
[2017feb helpcross](./x2017feb/xhelpcross/xmain_helpcross.cpp) | Don't try to math it, just use **multiset.lower_bound()**.
[2017open where](./x2017open/xwhere/xmain_where.cpp) | Didn't realize such a brute forcey solution would work, debugging failed because I was checking the wrong PCL conditions, so **Read the problem**
[2017open cownomics](./x2017open/xcownomics/xmain_cownomics.cpp) | Didn't understand what the problem meant by "sufficient to explain", but I just coded it so that it counts if there isn't the same triplet in a spotty and a non-spotty.
[2018jan lifeguards](./x2018jan/xlifegaurds/xmain_lifegaurds.cpp) | Didn't think of storing life guard alone times seperately and processing events one at a time (instead of as segments). Some things need to stay together, but the events in this problem were easier to work with when split apart and reorganized.
[2018jan rental](./x2018jan/xrental/xmain_rental.cpp) | Didn't realize simple dp/scan approach, debug: dp increased check space by one, so we actually have to max from `[0, N+1)` instead of `[0, N)`.
[2018jan mootube](./x2018jan/xmootube/xmain_mootube.cpp) | My edgelist impl was flawwed, **use stl list<int>[MX] instead** to reduce chance of error.
[2018feb reststops](./x2018feb/xreststops/xmain_reststops.cpp) | Didn't use **long long**
[2018feb snowboots](./x2018feb/xsnowboots/xnew_snowboots.cpp) | Didn't use DP, debug: missing **recursive base case**, sometimes you need more than one.
[2019feb paintbarn](./x2019feb/xpaintbarn/xmain_paintbarn.cpp) | Didn't think of using dp
[2019feb herding](./x2019feb/xherding/xmain_herding.cpp) | Didn't understand basic range based approach, and didn't realize that which cow is which doesn't matter. Insight: we want to eliminate as many/few "gaps" in the range as possible.
[2019feb revegetate](./x2019feb/xrevegetate/xmain_revegetate.cpp) | Didn't realize that I had to check whether it was even possible, that check made it hard to use disjoint sets so I ended up having to rewrite it with flood fill.
[2019dec milkvisits](./x2019dec/xmilkvisits/xnew_milkvisits.cpp) | Didn't think of using simple disjoint set (dfs)
[2019dec meetings](./x2019dec/xmeetings/xmain_meetings.cpp) | So many transformations
[2020jan berries](./x2020jan/xberries/xmain_berries.cpp) | Didn't realize a simple greedy approach would work, debugging: was sorting by increasing instead of decreasing oops
[2020jan wormsort](./x2020jan/xwormsort/xmain_wormsort.cpp) | Didn't see as a disjoint set problem, the key realization is any cow can be sorted (through a series of swaps) if it is in the same disjoint set as its target position.
[2020jan loan](./x2020jan/xloan/xmain_loan.cpp) | Didn't understand the math to figure out how many days in a row give y milk
