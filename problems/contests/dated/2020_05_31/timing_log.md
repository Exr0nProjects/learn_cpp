# Contest contests/dated/2020_05_31 - played Sun 31 May 2020 @ 14:15 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
14:15 | start | reading problems
14:22 | have plans for 1, 3, need to analyse 2 | coding #1
14:37 | AC #1 | coding #3
14:58 | WA #3 | debugging
15:07 | uhm, brute force AC'd #3?? | analysing #2
15:10 | wait, the cows already want the entire range? huh. | walk
15:16 | walk, binary search on answer, check in O(N)? | analysing #2
15:29 | can actually check each by initing segtree with negative capacity, now just need to check if sorting greedy works | analysing #2
15:32 | dunno if it works, lets just try it | coding #2
16:04 | submitted, still RE and WA #2 | debugging
16:09 | maybe sorting like that doesn't work, is there a diff way? what about that meeting room dp problem? and there was something else that i thought but forgot | analysing #2
16:19 | if meeting room can be solved in N^2, then I can do this in N^2 log N by using the segtree to check overlap | analysing #2
16:27 | i don't know | flop break

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

[Link to the contest](http://115.236.49.52:83/contest/1399)

#### Problem 1:
min/max segtree, no update. easy enough

#### Problem 2:
First I tried sorting the segments and greedy counting, using the segtree to check if each step was legal. It didn't work, and I later found a test case that broke my greedy algorithm.

Then, I thought about how to do it like the meeting rooms dp problem, but that just TLE's (N^2 log N) and also probably MLEs (different segtrees for each index?) so thats where I gave up. I'll work on it more later.

#### Problem 3:
Segtree range update and max query to check if each segment of the ride is at capacity, but that got WA. I wrote a brute force quickly, which accepted.

### Strategy

Timing on this test was good, I guess, since I was able to get two problems out of the way pretty quickly. I'm not sure how to spend more time analysing the third one though, because it feels like i'm just sitting there idly spinning my mind.

### Action item
I think my segtree is decently strong. Mostly need to work on other stuff, like DP.

