# Contest contests/standard-xjoi/1630 aka Gold Weekly Contest #9 - played 23 Sep 2020

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:57 | start | reading problems
18:05 | have ideas for 3, 2; 2, 1 need more analysis | psudocoding #3
18:11 | plan for #3 should work | coding #3
18:18 | WA #3 ?? | analysing #2
18:49 | not sure how to store dependencies, also my brain feels unfocused | analysing #1
19:18 | might it be just numbers w/ inversions greater than 1?? | coding #1
19:30 | didn't work, WA 12/100 | debugging #3
19:40 | WA #3 45/100, maybe time to code the LIS for #1 | coding #1
20:06 | WA and wayy TLE #1, got cases 1, 9 instead of 1, 2 this time | planning
20:09 | might as well code the brute force at this ponit | coding #1
20:13 | tilted, brute force gets 45 points | analysing #2
20:19 | no inspiration | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

Didn't really get the analysis I guess.

I don't know how I would've seen the line crossings analysis other than some kind of strike of inspiration. Maybe there's a limited number for inversion-type problems: counting inversions, counting participated inversions (haircut), flow across a line (out of sorts), pointers monotonically moving? (I remember that from somewhere).

#takeaway see above for inversion type analysis methods

also, the descretization gave me some trouble becasue I was trying not to copy the code. I don't know that I fully understand it but I think you have to use sort desc instead of map or ranked because we are working with indices and don't expect to have duplicates.

#### Problem 2:

Wait you just binary search? I thought there was a better way because you have to use all the previous ones if you do a binary search. I guess I should've seen that because checking the previous was requiring a rescan of the entire thing... I should've went back to binary search instead of assuming against it.

#### Problem 3:

I had thought that this was just a knapsack, because given any weight of cows the maximum value is obviously going to be best. So, you just calculate that for all weights and take the max ratio. But, because the max value may be too high, I decided to de the switch thing where you take the minimum weight for any value. However, this actually doesn't work because the minimum weight might not be the best, because it might be below the limit. That's why you have to binary search.

#takeaway make sure the dp subproblem structure is correct
#takeaway knapsack state compress weights if you dont care about exact weight

#### Summary

I feel like I should be able to do these problems, although I keep going off on the wrong track. I thought some problems were ad-hoc when they weren't and didn't try to combine algorithms well enough.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
