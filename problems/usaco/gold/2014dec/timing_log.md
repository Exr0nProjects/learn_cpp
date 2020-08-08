# Contest usaco/gold/2014dec - played Fri 7 Aug 2020 @ 13:38 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
13:38 | start | reading problems
13:45 | read problems, probably dp for 1, maybe binsearch or inversions or longest increasing subseq for 3, some rmq for 2 | analysing #1
14:05 | not sure how to do #1 | analysing #3
14:27 | can count inversions but not sure how to count lanes needed | analysing
14:44 | still dunno how to actually count lanes w/ inversions method | analysing #2
15:04 | have plan for #2 w/ segtree and bit | coding #2
15:38 | mostly works but query is all broke | coding #2
15:43 | time limit and wa on #2 ?? | debugging
15:55 | bit will tle if index is zero... now WA 3/10 | debugging
16:03 | what increasing the limits just AC'd? | analysing #3
16:07 | thinking about brute force w/ max clique counting, forgot how bron kerbosch works... | analysing #3
16:15 | brain isn't working so well anymore | analysing #1
16:19 | brain broke | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: gaurd

Pretty clearly a DP problem, and I did see that N was small as the solution stated. I was thinking how to DP out the best permutation after deciding on a subset to take, but didn't think of bitmasking the whole thing and directly DP-ing on subsets.

#### Problem 2: marathon

I figured it was some kind of range query, and realized that you could just take a sum and a max over the most you can save by not going to a point. Then, it was relatievly easy to figure out what needed to be updated to maintain the structures.

This took longer than I hoped to code, but atleast I was still able to code it. Haven't written segment tree or BIT in a while.

#### Problem 3: cowjog

I thought about running LIS repeatedly, but I thought that the complexity would be N^2 log N because you have to run LIS for O(N) up to N times. so, I didn't code it. I don't yet understand how the solution runs LIS only once
I guess i was missing the greedy analysis figuring out a property of the important chain of cows that decides how many rows there are. Also such clean LIS code! Should be good to recode this problem.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
