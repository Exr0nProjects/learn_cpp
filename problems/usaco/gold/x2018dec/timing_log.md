# Contest usaco/gold/2018dec - played Wed 25 Mar 2020 @ 17:30 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:30 | start | reading problems
18:03 | don't know how to do #1, have plans for 2, 3 | coding #2
18:17 | TLE #2 (1/11) | coding #3
18:39 | keep getting inc left and exclude rights messed up on #3 | debugging #2
18:48 | using sets is too slow | attempting #2 with bitset
18:53 | bitset's don't work the way I thought they did | analysing #2
19:07 | binsearch, djs wouldn't work, can't think of how to make it a graph | debugging #3
19:18 | conditional memoization? | optimizing #3
19:25 | TLE #3 8/10 | end 1h 55m

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: dining

I don't know how to do this problem -- I thought of dijikstra from the destination and from all the haybales, but all of it is too slow. I also thought it might be some kind of per node DP, but I couldn't figure out how to frame the question, as there are cows starting from each field.

#### Problem 2: cowpatability

I first noticed that instead of counting cows that aren't compatible, it's much easier to count cows that are. We can do this by counting how many cows before each cow comes in like the same icecream. This was my original O(N) plan.  
However, after testing it on the sample test case, I realized that simply prefix counting each icecream flavor didn't work because you could overcount some cow compatibilities. So I decided to use a set to track the specific cows but didn't recheck the time complexity.
After coding it, I realized that using a set to keep track of specifics is too slow. (n^2 log n)  
The bottle neck is the n log n merge of two sets, which is essentially disjoint set union except both sets need to be preserved after the operation. I couldn't figure out how to do this.  
I also tried thinking about this problem as binary search, but couldn't find a O(n) way of testing whether you could find x cows that weren't compatible, so that didn't end up working either.

#### Problem 3: teamwork

I originally thought of a two stage DP, which would've worked except it MLEs. Then I removed one stage and got a linear function to do it instead, but that was still too slow (N^3).  
I tried doing "conditional memoization", where you stick the answer in a map if the search takes long enough, but that didn't seem to speed it up either. Maybe there is a better way to frame the DP equation.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

Again, I don't think there's much to talk about on the strategy side. I mostly need to look at more problems and get better at doing them.  
Although I did forget to recheck the time complexity with sets for #2, and I didn't really write psudocode for any of the problems.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

Always recheck time complexity. Get gud at DP, graphs, adhoc, everything else.

Continue practicing DP and graph problems.
