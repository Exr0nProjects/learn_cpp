# Contest contests/dated/2020_04_29 - played Thu 30 Apr 2020 @ 15:53 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:53 | start | reading problems
16:09 | have plans for 1-4, 5 and 6 need analysis | walk
16:15 | walk | coding #2
16:27 | TLE #2 | coding #3
17:07 | how to write #3 ? iterators are whack | coding #4
17:23 | AC #4 | analysing #5
17:32 | I think it works, we can code it quickly to check | coding #5
17:41 | WA #5, I guess you have to dp it | analysing #6
17:53 | linear DP with suffix trie is O(W*L), should be ok | psudocoding #6
18:02 | should be fine | coding #6
18:20 | trie is bug | coding #6
18:43 | WA #6 | debugging
18:49 | dunno what's wrong | debugging #5
19:03 | casegen bad | analysing #5
19:15 | so greedy doesn't work | analysing #5
19:21 | and I don't know how to split states for DP | psudo KMP #2
19:38 | I don't actually know how KMP works.. | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:
http://poj.org/problem?id=2299

This bubble sort thing seems to come up all the time, I never learned what the formula is. I should do that..

After [looking it up](https://www.geeksforgeeks.org/number-swaps-sort-adjacent-swapping-allowed/), it turns out to be the number of inversions which was my first guess that I assumed was wrong. This problem should've been doable.

#### Problem 2:
http://poj.org/problem?id=3461

I should know how to do this, apparently c++ string::find isn't even KMP. I don't know how to write KMP so I need to practice that.

#### Problem 3:
http://poj.org/problem?id=2003

I tried to write this but got confused by vector iterators, especially since c++11 isn't allowed. I also should practice coding trees in general.

#### Problem 4:
http://poj.org/problem?id=2253

Similar problem to one from the test on april 27th. Binary search + disjoint set, although I thought it was djikstra at first. Half way through coding I realized that I didn't care what the source and destination were, just needed to check if they could be connected.
Atleast I now know how to code this style of problem.

#### Problem 5:
http://poj.org/problem?id=1014

I thought that a greedy approach would work at first, but when I submitted it it was WA. It took me a while to find a counter example, but basically any pair of relatively prime numbers (like 5 3s and 3 5s) would break the greedy approach.  
That means that I'm pretty sure this is a DP problem, but I don't know how to do the states. Needs work.

#### Problem 6:
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=1943&mosmsg=Submission+received+with+ID+2635048

I see this as DP with a trie, and my code should work. I didn't find a wrong answer case, although I also didn't test it too extensively.  
I had some trouble coding basic trie for this problem for a bit, so I should work on that too.

### Strategy
Timing wise I think I did okay, although I spent a lot of time at the beginning failing to code the tree. However, I don't think there's much more analysis I could've done with extra time (although that might just be a mindset thing).

### Action item

Practice coding KMP, trees and trie. Learn the formula for bubble sort step count.
