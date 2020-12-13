# Contest usaco/plat/2018jan - played Sun 13 Dec 2020 @ 13:15 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
13:15 | start | reading problems
13:23 | read problems, need analysis | analyzing #1
13:37 | feels like DP but I'm not sure how to split the states | analyzing #2
13:46 | ig it's brute force time | coding brute force #1
14:07 | WA/TLE 1/11 #1 :/ | analyzing #1
14:29 | tree dp broken, TLE #1 6/11 | analyzing #2
14:44 | maybe I can use small to large merging on segtrees as maps? | analyzing #2
14:50 | not sure if it would work | what other brute forces?
15:05 | I can know that the sides will be monotonically increasing, but how to count rectangles within? not sure how to do the math | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

feels like DP, but I don't know how to split states.
By removing lifegaurds that are entirely contained within other shifts, shifts become monotonic (start before implies end before). Then somehow the DP works.

#### Problem 2:

coded N^2 brute force, could maybe optimize using small to large merging on sparse segtrees, but not sure if it would work or the time complexity
Apparently it's centroid decomposition.. not quite sure how the chains work.

#### Problem 3:

not sure how to count rectangles
Some kind of math. Leave it for now?

### Strategy
took a long time to code the brute force, but I didn't really know what else to do anyways.

### Action item
get good.? #1 was doable, needed to figure out how to modify the input to make the DP work. fix these problems and look at more.
