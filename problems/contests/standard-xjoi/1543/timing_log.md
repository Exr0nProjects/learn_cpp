# Contest [!meta:srcpath!] - played [!meta:beg!]

## Contest Timeline

| Time | Note | Next |
|----|----|----|
14:54 | start | reading problems 
15:05 | problems read, plans for 1, 3, 2, 5, 4 needs analysis | coding #1
15:08 | AC #1 | coding #3
15:18 | bad at writing mst :/ | coding #3
15:21 | AC #3 | coding #2
15:28 | AC #2 | analysing #4
15:34 | not sure about #4 | coding #5
15:58 | parens are toxic | coding #5
16:03 | WA 50 #5 | analysing #4
16:24 | have plan for #4, maybe? | coding #4
16:37 | plm #4 | testing cases
16:48 | AC #4 | casegen #5
16:55 | sample test case was broke lol, now wa 70 | actually casegen #5 this time
17:12 | the parenthesis checker is really bad | fixing #5
17:16 | AC #5, casegen ftw | AK, end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

dsu

#### Problem 2:

looked scary at first but basically just casework.
I originally thought you had to make a parent array and go through afterwards to decide whether to make it left or right child, but after coding that I realized you could directly set it.

#### Problem 3:

mst, although originally I tried to code prim with dsu and had a bunch of debugging (tried to merge directly instead of setting weight of already built edges to zero, init djs, weird stuff). I need to be more familiar with MST algorithms.

#### Problem 4:

This one was an interesting one. I originally just played around with the sample input, thinking about binary search or some kind of segtree thing. But I figured that that wouldn't appear on this test, so I kept thinking.
I noticed that while N was massive, M was only 1e4, so I figured I could descritize over M and preserve the relative ordering.
At this point, I was wondering how to store that some numbers needed to be next to eachother after descretization, like 1..2 affects 3..4 directly because there's no "maybe" between them, while 1..2 doesn't connect with 3..5.
I noticed that you can redo the entire problem but with include left exclude right, and then the descritization would work like normal.
At this point, I started searching for some kind of M^2 sweep solution, where you mark a range as even or odd directly on an array and then loop over a range to check. But I realized that the only way for a range to be locked in is for it to be connected directly, like a range that goes between others but doesn't share both endpoints will be able to be either one.
At this point, I realized I could just store a graph of some sort where the edges connected. I had been thinking about how the input reminded me of some other inputs, either a tree or graph input. I thought the tree would've been a binary tree, where each row was the left and right child of a node, but I didn't think that it might be an edgelist representation. Anyways, eventually I noticed it and pretty quickly realized that that could work.
I tested a small test case, coded it quickly, and got it with minimal debugging.

#### Problem 5:
Expression tree is kind of toxic. It wasn't that bad, except the first time around I forgot I had to go from the back to ensure proper order of operations, and parenthesis unwrapping was problematic multiple times:
First, I just `++l, --r` if the first and last characters were parens, but that didn't work for `((a))` because there were still parens.
Then, I stuck it in a while loop, which was fine until `(a)+(b)` broke.
Then, I first checked if first and last were parens, and if so I unwraveled them if there were no parens in between. That was fine for a while, until `((a))` came back and broke again.
Finally, I checked the edges and then looped through the center making sure that the paren count didn't go negative and all parens canceled eachother out before unwraveling. That worked.

I had to casegen for this problem because I couldn't figure out what was wrong with the last paren checking bug, but that wasn't so bad because I had casegen'd it before. I used python eval to check, which was nice and simple and wouldn't break.

### Strategy

I think time allocation was pretty good. Got the first three problems done quick, and I tried problem 4 for a bitbut decided to get the points for problem 5 before spending too much time there.

### Action item

- [ ] Code MST algorithms more, especially with different graph representations like adjacency matrix.
- [ ] Figure out a proper way to unwrap parenthesis.
- **Remember test cases that I tested previously, even if I think I already fixed th problem, even if its such a simple mistake that I shouldn't make while debugging later.** This would've helped me do #5 faster
