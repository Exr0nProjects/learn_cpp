# Contest contests/algo/treap - played Tue 19 May 2020 @ 16:48 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:48 | start | reading problems
16:57 | 1, 3, 4 are directly mappable to treap, idk about 2 tho | analysing #2
17:04 | can do #2 as array of lists + treap, each maintaining a global min, but how get k-rank w/o traversing a linked list? | analysing others
17:09 | dunno | coding #2
17:42 | hecka scuffed | debugging #2
19:14 | passed sample case, typos in treap :/
19:17 | WA #2 | debugging
19:46 | submit broken code in desperation and AC | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

http://115.236.49.52:83/contest/1370
#### Problem 1:

I thought this would be easy, but I have no good way of finding the entry of a certain rank.
This is the same problem as pretty much everyo ther problem on the contest.

#### Problem 2:

This was the only problem that I thought I didn't know how to do, but I realized that the MIN_SORT_GAP was easily treapable and that the other thing didn't even need any fancy data structure, just store the beginning and end of each column.
However, halfway through I realized that having a global min wouldn't work because sometimes you need to update the min to make it go up (if you insert into the min gap). So, I decided to use another treap to store the min_gap values which I could erase from.
Then, I realized that I had the same problem for MIN_SORT_GAP so I added yet another treap.
After debugging that for way too long (but continuing because I felt I was close and I couldn't really figure out how to do k-th rank query during the contest and code it) I finally got it mostly working.
The code currently breaks if the first number is 0, but it got accepted anyways.

One fundamental issue I found with my treap code was that in insert, `ins` can't be a reference because it might get yeeted during rotation.

#### Problem 3:

Same as problem 1, needed k-th rank so I didn't really do it.

#### Problem 4:

Same as problem 1 and 3.

### Strategy
I spent all of my time debugging problem 2. I didn't think I would have time to figure out how to do another one. I ended up getting it accepted so I think that was the right move.

### Action item

From earlier: "One fundamental issue I found with my treap code was that in insert, `ins` can't be a reference because it might get yeeted during rotation."
