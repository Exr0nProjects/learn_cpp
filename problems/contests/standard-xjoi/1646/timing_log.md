# Contest contests/standard-xjoi/1646 - played Wed 25 Nov 2020 @ 11:30 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:30 | start | reading problems
11:45 | read problems, have idea for #2 | analyzing #2
11:53 | can't you just dijkstras this | coding #2
12:08 | WA 0? | debugging #2
12:20 | WA 90.. good enough for now | analyzing #1
12:48 | paperless don't know how to tell if two sets are connected | analyzing #3
13:00 | feels like i don't have any ideas.. no inspiration | debugging #2
13:17 | stuck and don't know where to go next | walk

## Contest Reflection

### Knowledge
jello brain

Remainder is filled in 2 days after:

#### Problem 1:

problem statement was a little confusing, but eventually I settled on "given a spanning tree and some extra black edges, remove one tree edge and one black edge to split the graph". Removing an edge can only split the graph into two, and for each tree edge there are either zero, one, or more black edges in parallel. Casework -> zero means you can remove any black edge and it conuts, 1 -> remove that one (one option), two -> zero options. **couldn't figure out how to count the number of parallel edges.**

#### Problem 2:

I thought it was an MST problem, but then that didn't work. I thought multi-start dijkstra, which worked but had an edge case. Took a while to code too.

#### Problem 3:

I thought you might be able to sort increasing and decreasing, but that didn't really go anywhere. Didn't know what direction to think it in so I ended up giving up.

### Strategy
I am filling after doing 1649, and I think the strategy comments are the same. Basically, when I don't know what direction to think something in I kind of give up.

### Action item
classic algorithms, improve grit.. how?

