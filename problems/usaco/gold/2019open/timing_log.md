# Contest usaco/gold/2019open - played Tue 24 Mar 2020 @ 15:44 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:44 | start | reading problems
15:56 | have vauge plans for 1, 2 | analysing #3
16:13 | did some thinking on #3, some insights but still no plan | psudo-coding #1
16:17 | finish `op` psudocoding for #1 | coding #1
16:56 | TLE #1 4/12 (really bad) | psudo #2
17:00 | may have a hard time writing N^2 check function | analysing #2
17:08 | actually works as long as each cow can be put into a group in O(N), which happens as long as one group is incompatible with the cow given some min dist, but what to do if no groups "collide"? | analysing #2
17:17 | have idea for n^2 checking with disjoint set | psudo #2
17:22 | psudocode should work | coding #2
17:44 | #2 doesn't work for sample test case, I think the binary search is broken.. | debugging #2
17:58 | realize that order of `x` and `y` in dist matters, you have to take max, TLE (got 9/15) | debugging #2
18:03 | #2 still TLE | analysing #3
18:33 | Not sure how to do #3 | Giving up

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

While reading the problem, it sounded similar to knapsack so I immedietly tried framing the problem with `dp[i][j] = best by index i and using j changes` or something.  
Then, I realized that I also had to store the current size of the net `s` in the state, so I added that to the problem frame.  
The next DP equation I came up with called for trying all values of `s : group[i] <= s <= max_after[i]`, but I realized that I only needed to check values of `s` that would make a difference, so I check every `s` that is the size of a future group.  
This brings the total time complexity down to N^4, and I was unable to get it any faster.

#### Problem 2:

While reading the problem, it reminded me of the cow barn binary search problem from the xj contest, and I saw that a sorting property was that as the min distance goes up, it gets harder to fit all cows into a certain number of groups.
I then set out to write an N^2 check function for that sorting property, by going through the list and assigning each cow a group, but I couldn't figure out how to decide which group to put a cow in if it could go into any group.  
After thinking for a while, I realized that I could change the sorting property into "the higher the minimum distance, the fewer groups you need" and use disjoint set to count the number of groups.  
For a while, my code wasn't working on the sample test case and I thought that I had written binary search or djs wrong somehow, but actually it was because the distance operator is `max(dist(x, y), dist(y, x))` which wasn't clear in the problem description. In fact, the way the problem is worded I think it should've been `min`, but it was `max`.  
I thought the djs strategy was going to work, although the time was a little risky. I still ended up getting TLE.

#### Problem 3:

I didn't have any immediete idea of what to do after reading this problem, although I had a suspicion that it was a graph problem, framed similarly to edit distance.  
However, I couldn't figure out how to represent states (2^10^5 possibilities??) so I started just playing around with the problem and seeing what comes out. I came up with some insights:
- The number of inversions that involve any `1` is the number of `0`s before it.
- A sorted string has no inversions.
- Swapping two elements that are the same value has no effect.
- An internal swap (not crossing from half to the other) can only increase/decrease the number of inversions by 1.
- If counting inversions by the `0`s before method and a prefix count, updating the prefix count after a swap is O(1).
- Swapping across the boundary either has no effect or adds/removes:
    - # of `1`s before the end on the left
    - # of `0`s before the begining on the right
- Doing `x` useful boundary swaps (with the swapping to get new useful numbers at the bounds) creates/removes `x*pre-x` inversions on the left and `x*post-x` inversions on the right, where `pre` is the number added/removed in the original boundary swap on the left and `post` is the same for the right. (See above bullet.)

I also tried to think about this problem as:
- a binary search problem (allowing more swaps makes it easier to obtain a tie)
- divide and conquer (because the largest possible time complexity was around O(n log n))
- segment DP, where `dp[i][j]` is something...

The second two attempts didn't work because of this problem's unique structure: the evaluation is done in two seperate parts that don't interact with eachother, but the numbers can still move around and between the two halves.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

I think my strategy for this contest was pretty good, I didn't spend too much time thinking about any problem in particular, and I spent enough time debugging #2 to get some points but didn't try to optimize it too much.  
This time around both the first and second problems were TLE, which means my paper work wasn't so good, I might have screwwed up my time complexity analysis for them.  
I was kind of tired today so maybe I didn't think something through.

I did remember to write psudocode during this contest, which was pretty detailed and allowed me to realize that my original plan for problem 1 was going to be too slow. That was very helpful.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

I need to remember to write good psudocode to catch errors, and especially to make sure that my algorithm runs fast enough.
I thought I did this, but then caught myself not doing it during the contest and both problems that I ended up writing TLE'd anyways.

I still don't know how to do any of these problems or why I didn't know how to do them, (I thought I knew how to do the first two but both are too slow apparently).
