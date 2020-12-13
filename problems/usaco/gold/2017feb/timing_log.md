# Contest usaco/gold/2017feb - played Sat 12 Dec 2020 @ 15:47 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:50 | start | reading problems
15:57 | read problems, 1, 3 seem doable | analyzing #1
16:01 | weird dijkstra should work | coding #1
16:23 | AC #1 | analyzing #3
16:28 | can I not just count them like inversions? | coding #3
16:43 | oh.. doesn't account for 1, 4, 4, 1 | analyzing #3
17:06 | WA 6/10 #3 | debugging
17:11 | increasing bounds AC #3 | analyzing #2
17:21 | should be dp-able | coding #2
17:24 | AC #2 | end

## Contest Reflection

### Knowledge

#### Problem 1:

dijkstra, but you have to store the modulo in the state. forgot that first path to end might not be best, so you have to get all three and then take the min.

#### Problem 2:

thought it was bipartite matching, but then I drew out the test case and realized it was basically LCS. lcs would get every possibility, because each possibility can be reduced by taking the most recent crosswalk out, and it will return a possibility, because only having one active path at a time ensures no crossings.

#### Problem 3:

did the bronze version before, so I knew to just count the number of interspaced pairs. Counted against numbers less than current with a bit. Because I wanted to count the change in cows over time, i needed to re-number the numbers to be increasing or some deltas would cancel eachother out (see notes).

### Strategy
I think my time strategy was pretty good, although I should have done more paperwork for #2.

### Action item
Practice coding dijkstra. Remember to do more paperwork, try actual algorithm on test cases. Code brute force (but I didn't need to here).

