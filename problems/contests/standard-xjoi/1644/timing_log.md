# Contest contests/standard-xjoi/1644 - played Tue 24 Nov 2020 @ 10:45 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
10:45 | start | reading problems
10:54 | th are these problem statements lol | analyzing #2
11:19 | well I graphed it.. still unsure how to find an integer solution | analyzing #2
11:46 | probably can't come up with a closed form equation | analyzing #2
11:51 | okay yeah I don't even know how to deal with this equation | analyzing #1
12:22 | maybe try optimizing a brute force | analyzing brute #1
12:29 | with such low limits on $x_i$.. this might actually work | coding #1
12:40 | works except how to deal with reuse of numbers.. | coding #1
12:58 | picking order doesn't matter apparently, TLE 60 | optimizing #1
13:13 | removing map still got TLE 60 | analyzing brute #2
13:18 | buckets | coding brute #2
13:29 | brute force got WA 92, no TLE? | debugging
13:32 | forgot -1 case, now WA 96 | debugging

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

I was thinking it was some kind of fancy math, or prefix sum/sparse table, but then i realized that with such a small limit on X and because you are only allowed to choose three numbers, i could probably just brute force it. I forgot that there were multiple queries.
At first I had a map to deduplicate but then I realized that I could just stick everything in an array. Still TLE though.

#### Problem 2:

I spent a really long time on this problem, at first working out the algebra and then failing to do so on the final equation of $\frac{m-xL}{x+1} = \frac{n-yL}{y+1}$. I desmosed it and realized it was a straight line (is that legal?) and figured I could monotonically find points where it intersects a lattice point. This ended up not TLE-ing, (probably because there weren't any test cases with big N,M and small L?) and there is only one edge case that is wrong.

#### Problem 3:

I have no idea what this problem even means or how to do it.

### Strategy
I spent a lot of time on the second problem, mostly because I thought the first one was hard and that the second one was more approachable. After switching to the first one, I was able to find a brute force approach relatively quickly, and going back to the second one was even faster. I think it was an okay strategy, because I didn't really know what else to do at the time.

### Action item
Learn chinese? These problems were very difficult to understand, and I had trouble focusing on the problem solving because they were confusing.

