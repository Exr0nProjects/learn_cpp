# Contest contests/standard-xjoi/1613 - played Tue 25 Aug 2020 @ 16:00 (PDT)

The problems are from Gold 2020 Open.

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:03 | start | reading problems
16:08 | vaugley remember problems | analysing #1
16:21 | I think I understand how to do it | coding #1
16:27 | plm #1 coded, segfault?? | debugging
16:38 | AC #1 | analysing #2
16:50 | just make a tree, amortized O(N)? | analysing #2
17:02 | how to update sublinks when coming from a higher node? what if there is a cycle? | analysing #2
17:05 | what if a cow admires two colors? then link both colors? can we just set a group for each admired color? | analysing #2
17:15 | wait I don't understand the question, can a cow admire two cows who have diff colors?? | analysing #2
17:19 | their diagram just confuses me | coding #2
17:29 | I think I still need that amortized tree thing for dist > 2 | analysing #2
17:39 | Patch dsu merge somehow? store a cow who admires each dummy? | coding #2
17:56 | somewhere the merge is finicky | debugging #2
18:09 | finally works for sample | submitting #2
18:12 | WA 1/100? | debugging #2
18:33 | i'm not sure why its only getting one case, reread the problem | reading #2
18:37 | I should look at another problem | analysing #3
18:57 | N^2 DP? | analysing #1
19:00 | maybe just write it as a brute force? I'm running out of time anyways | coding #1
19:11 | not sure how to calculate LCM well, should I just keep thinking? | analysing #1
19:19 | I have to add them... maybe this is the right solution | coding #1
19:27 | Idk if I should go back to coding #2 brute force but this one can get me more cases | coding #1
19:50 | brute force #1 still has WA 1 | debugging #1
19:54 | i can try to code brute #2 ig | coding #2 brute force
20:00 | what if there are loops? | end

## Contest Reflection

### Knowledge

#### Problem 1:

We had talked alot about haircut, so I knew that it was solved with counting inversions. I also remember from the past that it was something about prefix sums, so I just looked for how you can figure out when a hair pair stops mattering.
It turns out that this happens when both have been cut to the same length, aka the global len is the minimum in the pair or less. Thus, you can store how many inversion pairs have a minimum at a_i, and prefix sum over that for the answer.
For a moment, I couldn't figure out how to gaurentee the minimum, but later I realized that when using the BIT method you always have either the minimum or maximum in the pair. Thus, you just have to sweep forwards and use range query, or in my case use one query and subtract it from the running total.

#### Problem 2:

I quickly realized that if you start at a node, then all layers in the tree going off that node must be the same color. I'm not sure why I didn't understand this when I previously saw the problem. However, I couldn't figure out how to merge all the sets right without N^2, because when you merge two sets you have to merge the sets that admire them as well.
I had a sketchy recursive DSU which I think should work, but I don't know why it only gets one test case.

#### Problem 3:

We need to sum the LCMs of all sets S such that the sum of S is = N. I didn't realize this last time I saw the problem, but I now see that it comes from splitting cows into groups that have period of length (size of group). I think this gaurentees that you find all possible periods, but I don't have a rigerous proof for it.
However, I couldn't figure out a math way to sum the LCMs, and I couldn't figure out how to generate the groups quickly to calculate LCM. Besides, it was WA on all but 1 test case. Not sure how to do this problem.

### Strategy

I started with doing #1 because I was pretty sure I could figure it out quickly. That worked out. However, afterwards I spent a lot of time on #2 before moving on to #3. Although I don't think I'm close to solving #3, if it had been easier then that might have been a misplay.

### Action item
Math with LCM? Practice writing recursion because I struggled with that on #3
