# Unsolved Problems

## Still unsolved

**These problems have yet to be solved.**

- [bronze15open palpath](./2015open/palpath/new_palpath.cpp)
- [bronze18open family](./2018open/family/main_family.cpp)
- [bronze18open milkorder] (not started)

## Badly needs purification
- [bronze19open evolution](./2019open/xevolution/xstash_evolution_wip.cpp)
- [bronze19open factory](./2019open/xfactory/xmain_factory.cpp)

## Unsolved during contest

**These problems were either not solved during the course of the contest due to lack of skill or were poorly written and needed significant purification.**

| Problem | Notes |
|----|----|
[bronze2014dec cowjog](./2014dec/xcowjog/purify_cowjog.cpp) | Read the problem wrong, had cows moving backwards
[bronze14dec learning](./2014dec/learning/main-learning.cpp) | Added an edge case wrong, should only increment `b` on upper half. See [dfd231d](dfd231d) Exr0n@dfd231d.
[bronze2015jan meeting](./2015jan/xmeeting/purify_meeting.cpp) | Was written with two dfs functions, consolodated and purified to use less storage and code
[bronze2015feb cow](./2015feb/xcow/new_cow.cpp) | Misunderstood dp dimensions
[bronze15feb censor](./2015feb/xcensor/xnew_censor.cpp) | Didn't remember to just look back a few chars simply instead of from beginning or with fancy KMP stuff
[bronze15open geteven](./2015open/xgeteven/xbashy_geteven.cpp) | Bashy method works if you only pay attention to even or odd.
[bronze15open trapped](./2015open/xtrapped/xnew_trapped.cpp) | Bashy recursive simulation is fast enough
[bronze15open moocrypt](./2015open/xmoocrypt/xmain_moocrypt.cpp) | Didn't read problem fully: I had 'M' and 'O' mapping to itself.
[bronze2015dec paint](./2015dec/xpaint/xpurify_paint.cpp) | Used bashy method instead of mathy one
[bronze2016jan angry](./2016jan/xangry/xpurify_angry.cpp) | Purify to simulate only furthest explosion instead of all of them, then subtract indicies
[bronze2016feb balancing](./2016feb/xbalancing/bash_balancing.cpp) | Didn't realize that I could take advantage of only checking around places that matter
[bronze2016open bcs](./2016open/xbcs/new_bcs.cpp) | **WIP** rewriting with less logic (practical longer runtime, same complexity) based on USACO soln
[bronze2017jan cowtip](./2017jan/xcowtip/xpurify_cowtip.cpp) | Didn't realize that any of the "furthest" ones (only one rectangle can toggle) would work, originally written with diagonal traverse but rewritten with simpler horizontal traverse
[bronze2017jan hps](./2017jan/xhps/xpurify_hps.cpp) | Didn't realize that I only need to check two posibilities instead of all permutations of three elements
[bronze2017dec billboard](./2017dec/xbillboard/xmain_billboard.cpp) | Used bashy method instead of mathy one
[bronze2017dec measurement](./2017dec/xmeasurement/purify_measurement.cpp) | Rewrote to use less varibables and no bitwise
[bronze18open tttt](./2018open/tttt/main_tttt.cpp) | Needed to ensure that both cows in the pair contribute to a pair win
[bronze19open buckets](./2019open/xbuckets/xmain_buckets.cpp) | Rewrote to use math (only one rock) instead of bfs
