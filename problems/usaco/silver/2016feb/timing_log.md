# Contest usaco/silver/2016feb - played Mon 13 Jan 2020 @ 19:38 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
19:40 | start | reading problems
19:46 | have plans for all, but 2, 3 vauge | coding #1
19:50 | actually, #1 plan doesn't work | analysing #1
19:57 | have bashy plan for #1 | coding #1
20:10 | #1 is hard to code | analysing #2
20:14 | should have a plan for #2 (same as bronze) | coding #2
20:30 | 9/10 balancing (last one WA) | debugging using set
20:37 | nvm, fixing it with sets is too difficult for now (not a random access iterator, so I would need to sort by values in an array and grab the value at the start index, then search the set for it.) | analysing #3
20:54 | give up on dp equation writing, just going to dfs #3 | pause for sleep 
14 Jan 2020 @ 7:10 | woke up | coding #3
7:36 | 6/10 #3 (RE and WA others) | debugging #2
7:38 | thought maybe INT16_MAX wasn't big enough, but still WA #10 | debugging #3
7:52 | AC #3 | done


## Purify Notes

### Problem 1: cbarn

Didn't know how to use the key insight that we want all cows to walk as little as possible, rathar than having one cow walk really far.
new_cbarn was based off [thecodingwizard's solution](https://github.com/thecodingwizard/competitive-programming/blob/master/USACO/2016feb/gold/cbarn.cpp), which runs in N^2 (instead of O(N)like the usaco soln), but doesn't use fancy math and is easier to reason about. It's still plenty fast.  
The way it works is first, it finds a suitable starting location by looping through the barn twice and finding a proper ending location, and then adding one. Then, it starts going around the rooms from that starting location and puts all cows it encounters in a queue, where each cow in the queue started in the same or an earlier room than the previous one. Then, at each new room it drops off the first cow and picks up the cows that were there already, thus gaurenteeing that the cow that walked furthest stays in each new room. Time: `O(N)`, space: `O(N)`.

### Problem 2: balancing

Didn't know how to write O(n) single fence sweep, so my soln was N^3 which is too slow, while using a little more logic we can get that down to N^2.
Basically, in the usaco soln, for each possible y value of the fence, we count how many cows are above and below. Then, we jump the x fence from left to right, adding the number of cows jumped over at each jump to the left quadrant of top or bottom. Then, the number of cows in the top right quadrant at that x fence position is the number of total cows above the horizontal fence minus the number of cows on the top left, and similarly for the bottom. (In my code I used `above_idx` for top left and `below_idx` for bottom left).

### Problem 3: pails

This problem was written with top down dp while the usaco soln used bottom up DP. It defined the problem as `bool dp[i][j] = whether or not we can end up with i milk in a and j milk in b`, while I defined it as `int dp[k][i][j] = best soln if after k steps we have i milk in a and j milk in b`. These definitions yield the same time complexity (n^3).
