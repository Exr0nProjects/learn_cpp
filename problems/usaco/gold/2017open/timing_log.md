# Contest usaco/gold/2017open - played Wed 16 Dec 2020 @ 17:05 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:05 | start | reading problems
17:10 | read problems (only two, #2 got yeeted), 3 seems doable | analyzing #3
17:25 | have stack plan for #3 | checking soln
17:27 | slightly diff method, I think mine still works? will code later | analyzing #1
17:35 | can I not just N^2 hash and N log^2 N binary search? | checking soln
17:39 | Apparently you don't even need to bins | coding #1
18:34 | implementation got MLE + binary search still sketchy | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

thought it was interval DP but that didn't make much sense becasue the dp would store only binary, not very helpful for constructing larger subproblems. Realized that binary search check was fast enough with hashing.

#### Problem 2:

Doesn't Exist

#### Problem 3:

Longest path in a DAG for fully covered intervals. Got confused in the middle about what makes a painting impossible, but anything that is `a.*b.*a.*b` is impossible so we can just think about a stack. (layers of paint are stacked on top of each other anyway).

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
