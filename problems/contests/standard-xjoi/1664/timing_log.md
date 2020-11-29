# Contest contests/standard-xjoi/1664 - played Sun 29 Nov 2020 @ 11:20 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:20 | start | reading problems
11:31 | read problems, 1 seems doable, 2 is just euler path right? | analyzing #2
11:41 | this is not maxflow.. but isn't it really easy | quick coding #2
11:48 | wait how does this problem even work | analyzing #2
11:55 | okay i don't understand how the problem works | debugging #2
12:02 | I dont understand | analyzing #1
12:29 | don't really have inspiration for chain case | coding brute #1
12:59 | WA 0 ..? | debugging brute #1
13:01 | debug output noises | analyzing #1
13:23 | have plan for chain that should work on the tree two (merge sort complexity) | coding #1
14:01 | coding is hecka scuffed | coding #1
14:12 | submission check shows that my method TLEs anyways.. but i should probably still code it | coding #1
14:22 | whole problem was because input was bad format | coding #1
14:27 | got those three test cases (TLE 40), now its time to figure out the real tree | analyzing #1
14:40 | oh thats the end of the contest, welp didn't have time to finish coding the tree method | end

## Contest Reflection

### Knowledge

#### Problem 1:

I thought it was some kind of binary lifting problem, but then while thinking about brute force I realized it was easier to see it as a vertical path to the LCA and a vpath from the LCA.
The chain subtask suggested this was the right track, so I thought about how to avoid updating every index in the array individualy. I thought because it was just one number that slid up (as time passed), I could simulate that by querying based on a 2d array. The method seemed to work and using smaller map merge heuristic it should work on the tree as well.

#### Problem 2:

The problem statement was confusing.. I didn't understand the test cases. The second and third seemed to be able to greedily take the smallest node, so I coded that up quickly and got a few points.

#### Problem 3:

I did not really work on this problem because it looked hard.

### Strategy
Because I could not understand #2 and was intimidated by #3, I think my strategy was decent. I was making progress the entire time so that was good for motivation.

### Action item
Implement things faster. (Still have not gotten a chance to do the classical algorithm items).

