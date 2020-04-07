# Contest usaco/silver/2020open - played Mon 6 Apr 2020 @ 15:58 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:58 | start | reading problems
16:06 | have plans for 1, 3, 2 needs analysis | coding #1
16:08 | hold up, how to tell if num is in interval? | analysing #1
16:10 | no intervals overlap, so can binary search | coding #1
16:25 | wait, i don't need to check, just iterate, WA (9/10) #1 | coding #3
16:29 | how to remove "all with lower y" in log(n)? | analysing #3
16:45 | just sweep backwards | coding #3
16:51 | didn't understand problem | analysing #3
17:08 | time to move on (djs?? sweep??, binary somehow????) | analysing #2
17:17 | have jank plan for #2 | coding #2 quickly
17:24 | jank plan for #2 was too jank (WA 1/10) | analysing #2
17:43 | still dunno how to do #2 | analysing #3
18:09 | and I don't know how to do #3 | debugging #1
18:20 | AC #1 (don't assume that the first grass patch is at 0) | break
18:23 | break | coding brute force #2
18:33 | somehow its still WA?? | coding brute force #3
18:43 | wrote brute force #3 (INIT DJS!!) | analysing #3
18:50 | still dunno | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

This was pretty clearly a binary search problem, similar to the cow huts thing.  
I originally thought that I needed to be able to check whether a position was in a range, so I was confused about that until I realized I could binary search to check.  
But then it turned out that I actually didn't need to check so the final solution time was N log N.

#### Problem 2:

I was thinking about the chain of cows kicking eachother off the cereal list as being O(N^2), and I don't understand why they say it is faster...

#### Problem 3:

I thought of it as sweep line at first, but I couldn't figure out a way to mark all "lower than active" nodes in log N. Also, that plan was flawed because I thought that the problem was equivelent to only the smaller particle gets removed but actually either one can, so it's more of an SCC type thing.  
(While thinking about sweepline, I realized that you could do it backwards and just track the highest as a way of doing one quarter of convex hull, but much easier to understand).

I was considering how to do it as DJS but couldn't figure out how to connect components in faster than N^2.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

Seems normal..

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

How does time complexity analysis for #2 work?

How does the analysis for #3 work?

Remember to INIT DJS!!!

Remember to check understanding with the test case!
