# Contest contests/dated/2020_05_04 - played Sat 16 May 2020 @ 11:38 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:38 | start | reading problems
12:00 | seems hard... | coding #2
12:11 | AC #2 | analysing #1
12:26 | sort by each and sweep, equal values will be cancer to deal w/ | coding #1
12:41 | AC #1 | analysing #6
12:49 | maybe can do #6 in N^2, manual cache-local linked list? | coding #6
13:16 | this is taking so long to debug | coding #6
13:19 | AC #6 | psudocoding #3
13:27 | seems legit | coding #3
13:45 | AC #3 finally, what to do with one hour? | analysing #4
13:53 | weighted trie? | psudocoding #4
13:59 | probs many edge cases | coding #4
14:10 | feels hella slow, passes sample test case but not text example | submitting #4
14:12 | TLE #4 | debugging
14:17 | ig memsetting 10^8 ints is slow | debugging
14:22 | memset optimization: only reset what we used before | debugging
14:24 | WA #4, now what | debugging #4
14:32 | `the there than` is diff from `the than there`, this is bad news bears | debugging
14:38 | couldn't get it | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: poj2726
I thought this was a counting inversions problem where you sort by cost and distance, but then realized that a prefix sweep was good enough.
I was worried that I would have to deal with checking whether to `min` each time because the next hotel might have the same dist/cost, but it got AC'd.

#### Problem 2: poj2013
This was just a simple rearrange, so I just inputted the names while swapping and outputted. Easy enough, although I did spend more time than I thought I would need to on getting the numbers to work out right.

#### Problem 3: poj2255
I'd done tree pre/in/post order conversion in hangzhou, so I knew I could do this one. It wasn't that bad, I just did the sample cases by hand to figure out what the logic was.

#### Problem 4: uva11732
This problem looked scary for a while until I tried to think about how to add more than one to the counter at a time, aka overlap.
The trie structure naturally popped into my head at this point, and I figured a weighted trie with a bunch of edge case checks should work. Didn't get it debugged in time though.

#### Problem 5: uva10652
Convex hull then heron's formula to calculate area. It should work if you construct triangles by stepping one to the left from start, then right, then 2 left, 2 right, etc. Haven't coded it yet.

#### Problem 6: uva 1394
I thought I would have to do some math analysis, but then I realized that just simulating was fast enough after taking the remainder on steps. It technically could've TLE'd (10^10), but I guess 2 seconds was enough time?
I wrote my own linked list simulation who's edge cases took too long to debug, but the idea was to force the list in as little space as possible to improve cache locality. I don't know if it actually worked (didn't benchmark) but it got AC'd so that's good enough.

### Strategy
Time strategy was okay during this contest, although I don't know if I should have tried to code #5 in the remaining hour instead of #4. I was able to come up with a way to do #4 pretty quickly, but didn't write/debug the actual code fast enough.

### Action item
Recode treap, weighted treap. Recode convex hull because I feel like that would take way to long to debug.
