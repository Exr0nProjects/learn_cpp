# Contest usaco/gold/2017jan - played Sun 6 Dec 2020 @ 12:55 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
12:55 | start | reading problems
12:58 | have general plans | analyzing #1
13:01 | can i not just straight up count inversions? | coding #1
13:16 | AC #1 | analyzing #2
13:23 | dp plan should work? | coding #2
13:39 | dp coded but seems broken.. typo probably | coding #2
13:43 | AC #2 dp equation was slightly wrong | analyzing #3
13:49 | Method should work for #3 | coding #3
14:35 | heck scuffed to code well | coding #3
14:41 | AC #3 | end

## Contest Reflection

### Knowledge

#### Problem 1:

just counting inversions.. I could have did a normal BIT, sorted, and counted complements that way but it was easier to just use the BIT twice.

#### Problem 2:

pretty clearly dp, although at first I thought I only needed two dimensions. However, `dp[i][j]` = best score after `i` games changing `j` times requires enumerating the time of the previous change, which would be N^2. Seems to be a common theme..

#### Problem 3:

morning after halloween, probably coded it too well. But I had time so it ended up being okay.

### Strategy
Strategy was pretty good. Spent more time than needed coding #3 because I had some extra time left.

### Action item
Think about how the end-of-interval splitting dp works: what exactly is the trade off between looping over `i` to enumerate the optimal length of the last segment, vs using a constant time decision but with more states stored?

