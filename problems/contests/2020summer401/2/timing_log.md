# Contest contests/2020summer401/2 - played Fri 19 Jun 2020 @ 10:00 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
10:00 | start | reading problems
10:12 | basically know all but #2 | psudocoding #0
10:26 | leetcode being bad | debugging #0
10:31 | too much time on this | coding #1
10:44 | stack going everywhere badness | debugging #1
10:56 | finally works for sample, AC #1 | coding #3
11:05 | #3 works for sample, RE | debugging #3
11:15 | AC #3, apparently #3 is maaasive | coding #4
11:26 | WA #4 ?? | debugging #4
11:30 | AC #4, had to guess the right max number smah | analysing #2
11:45 | go backwards, construct tree, output preorder, collapse deepest | psudocoding #2
11:57 | looks fine | coding #2
12:13 | buildtree bad... | debugging #2
12:20 | buildtree seems to work on sample | coding #2
12:33 | WA #2 10 points :( | debugging #2
12:49 | parens assumption was broke, do the first op now, WA 30pts | debugging #2
12:57 | maybe I have to do the deepest first | debugging #2
13:06 | that's not it, only gets 10 pts | debugging #2
13:13 | i don't know whats wrong | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 0: LeetCode 105

Kept getting RE, didn't really debug. I've done this problem before on XJOI so I'm not worried, will fix at some point

#### Problem 1:

Just a stack. Easy enough.
I had to make sure that a bunch of edge cases were handled with the input because chars and stuff which was kind of annoying.

#### Problem 2:

I vaugley knew how to do it at the beginning but I remember failing a problem like this in hangzhou so I saved it for last. I just needed to figure out how to build the tree, because once the tree was done then you could just solve it like problem 1.

I ended up only getting 30 points on this (WA), but I don't know what's wrong yet. Will fix when I can see other people's codes.

Theres a power operator. Bruh text.
So that was a quick fix, I just needed to add the power operation in (in the right place, mind you. after multiplication checking)

I'm going to clean up the code a little and resubmit to look cool.

#### Problem 3:

Lazy add and then traverse the tree, simple enough. Felt like segment tree almost, but without the range update/query.
Was getting RE and I didn't know why, I guess manual edgelist with long longs takes up too much space.

#### Problem 4:

Binary search on the answer, easy enough. The bounds on the binary search were kind of scuffed though, the right bound initial value had to be exactly 1<<31 or so, because 1<<30 didn't work and neither did bigger ones like 1<<40 or 1<<60.

### Strategy

I probably should've spent more time on problem 0, but I really don't like leetcode. I don't know whats wrong with #2.

### Action item

READ THE PROBLEM!

This test was pretty good I guess. I don't know why the leetcode thing kept getting RE, and was kind of tired of it.
