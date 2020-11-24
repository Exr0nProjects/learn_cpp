# Contest contests/standard-xjoi/1636 - played Mon 23 Nov 2020 @ 9:27 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
09:30 | start | reading problems
09:39 | seem doable, have plan for 3 | coding #3
09:50 | implementing wasn't as trivial as i thought | coding #3
09:54 | WA one test case.. misread problem? | analyzing #3
09:59 | AC #3 forgot that I changed the binary search upper bound to 18 instead of 1e18 | analyzing #1
10:20 | Have plan for #1 | coding #1
10:43 | again, implementation takes a while apparently | coding #1
11:04 | WA/RE 34 #1 | regrouping (planning what to do next)
11:08 | - | debugging #1 
11:42 | too scuffed | analyzing #2
11:47 | seems like simple enough tree dp | coding #2
12:03 | hold up, does simple tree dp work? | analyzing #2
12:23 | new equation seems to work with previous breaking cases.. | coding #2
12:35 | new equation WA 34 | debugging.. (not much time left)
12:44 | dunno why 2 wa 34 | debugging #1
12:53 | i thought it was wrong bc i typed the test case wrong, now WA 67 | debugging #1
12:56 | yeah i don't know why its broke | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

I thought it was a bipartite matching problem because it felt weird that there were two cows. I realized that it didn't actually work like that, because the edges were directed. Then I figured it was DAG-like and that I could just bfs it, which seemed to work. Implementation was tricky (still not correct) because the numbers are big but can't be descritized.

#### Problem 2:

Should be simple tree dp... I had one frame (`dp[i][j]` = number of ways for subtree at `i` with `color[i] = j`) but that ended up breaking when a child was colored. I tried to casework it a bit but realized that actually I should be multplying and adding, and came up with another equation `dp[i][j]` = number of ways for subtree at `i` if it's parent is color `j`, but it was WA 34. Need to revisit.

#### Problem 3:

At first I thought of a sparse table but then I realized that you could just binary search it. I was going to use a prefix sum to query the sum of flavors, but it was easier to just loop over and take another sum. Didn't take too long to implement, but it could've been faster.

### Strategy
I was not clear in the head with how the input worked for #1 so I spent a while trying to debug a misunderstanding of the sample input. It still had the same answer, but made the intermediate checking weird. I also could have saved some time on #2 if I had been more clear about how multiplication and addition work when counting possibilities.

### Action item
Practice math, counting, probability.
Understand the input better, check with test cases more **carefully** before jumping into code. (Sometimes I think that something will work when it doesn't even work for the sample case.. or one of the test cases that I generated already. Because I am blinded by me wanting the algorithm to be correct.)
Fix the two problems, work through math on #3 for previous contest (xjc1634), combo homework.

