# Contest contests/dated/2020_07_07 - played Tue 07 Jul 2020 @ 13:50 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
13:50 | start | reading problems
14:17 | have plans for 1, 3, 4, maybe 6. 2 needs a little work and 5 needs heavy | coding #4
14:27 | presentation error but ac'd. | coding #3
14:55 | input for #3 is too toxic | psudocoding #1
14:59 | seems legit | coding #1
15:11 | wait, currently it puts based on character after not before | coding #1
15:17 | works for sample | inning judge queue
15:19 | WA #1 | debugging
15:24 | found no wrong simple path cases, AC'd by increasing data limit | analysing #2
15:27 | can you just bitmask it? seems legit.. | coding #2
15:35 | works for sample, uva crashed my browser, AC #2 | psudocoding #6
15:46 | seems legit | coding #6
16:05 | finally works for sample, some minor fenceposts and stuff | submitting 
16:07 | AC #6 (first try lets go) | code/debugging #3
16:24 | had to use stringstream; TLE #3 | analysing #3
16:32 | not sure how to speed it up | analysing #5
16:45 | many interesting properties, but still dunno how to do it | analysing #5
16:48 | idk | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: [uva11988](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3139)
Quickly realized that you just need to insert at the beginning and the end. At first I was thinking I could just have an array and copy the segments around, starting in the middle and allocating enough space on either end, but then I realized i could leave the segments in place and just use a linked list of indicies.

Another nice thing was I could replace the input control characters with null characters and print on the string directly, no need to store a beginning and end index of each segment.

#### Problem 2: [uva679](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=620)
When first looking at the problem I thought that there might be a way to avoid simulating previous drops, since at the root the even/odd ness of the number was enough to determine which way it would go. I could then divide by two and continue recursively.

However, after taking another look at the problem later I realized that the coding of the modulo then divide was very similar to the binary representation, and then I found that the binary rep method worked for the sample so I just coded it up quickly to see if it would work.

There were many fenceposts but it wasn't too hard to do, and it ended up working which I would say was worth the gamble. It didn't take too long anyways.

#### Problem 3: [uva122](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=58)
The problem itself should be simple, just remember the path that you went down and check if all nodes were given on all paths. The input to this problem was kind of toxic for scanf, and I spent a good amount of time trying to figure it out during the beginning of the competition. So, I left it behind to work on other things.

Later, I came back and decided to use stringstream which was really easy to get working. I didn't expect that and I will probably use stringstream more in the future for this kind of dynamic or weirdly shaped input. Anyways, it TLE'd so I need to fix this problem.

UPDATE: my input was TLE because it was trying to getline all the time. I switched it out for a while cin on blobs, so that I could process each node one at a time but forgot to move that into main. It worked after doing so, so it was just an input TLE.

#### Problem 4: [uva839](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=780)
A simple dfs, not much more to say here. Didn't take long to come up with a plan or implement it.

#### Problem 5: [uva1331](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4077)
I've never done a problem about triangulation so I didn't spend much time on this until the end when I didn't really know what else to do. I need to learn about general properties before tackling this problem.

#### Problem 6: [uva242](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=178)
This was one of the DP questions so I generally remembered how to do it. I wasn't sure if it would work so I left it towards the end, coding the eaier ones first. Worked first try though, although I didn't think much about how exactly to lay the code out so it came out kind of messy, but AC'd so thats good. Not too worried about this.

### Strategy
I think the test taking strategy during this test was decent, although I wish I was able to spend less time on reading the problems at the beginning. I probably should've switched to stringstream earlier for #3, and I would've if I had known how much easier it would be. Otherwise, I just did problems in order of difficulty to get as many points as possible. I didn't run out of time, instead I couldn't figure out how to debug 3 and solve 5 at the end.

### Action item
Look into triangulation, practice using stringstream. Fix problem 5.

