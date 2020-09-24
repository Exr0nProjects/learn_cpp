# Contest 1623
there's nothing here. Oops

# Contest contests/standard-xjoi/1630 aka Gold Weekly Contest #9 - played 23 Sep 2020

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:57 | start | reading problems
18:05 | have ideas for 3, 2; 2, 1 need more analysis | psudocoding #3
18:11 | plan for #3 should work | coding #3
18:18 | WA #3 ?? | analysing #2
18:49 | not sure how to store dependencies, also my brain feels unfocused | analysing #1
19:18 | might it be just numbers w/ inversions greater than 1?? | coding #1
19:30 | didn't work, WA 12/100 | debugging #3
19:40 | WA #3 45/100, maybe time to code the LIS for #1 | coding #1
20:06 | WA and wayy TLE #1, got cases 1, 9 instead of 1, 2 this time | planning
20:09 | might as well code the brute force at this ponit | coding #1
20:13 | tilted, brute force gets 45 points | analysing #2
20:19 | no inspiration | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

Didn't really get the analysis I guess.

#### Problem 2:

Wait you just binary search? I thought there was a better way because you have to use all the previous ones if you do a binary search. I guess I should've seen that because checking the previous was requiring a rescan of the entire thing... I should've went back to binary search instead of assuming against it.

#### Problem 3:

This was like that other binary search problem we did, but I didn't remember the math for it. I'm not entirely sure why I can't just do my method... #todo

#### Summary

I feel like I should be able to do these problems, although I keep going off on the wrong track. I thought some problems were ad-hoc when they weren't and didn't try to combine algorithms well enough.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1629 - played Sat 19 Sep 2020 @ 7:40 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
07:42 | start | reading problems
07:49 | 2, 3 seem easier | analysing #2
08:08 | not sure how to find number of pairs intersecting at atleast 2 flavors | analysing #3
08:11 | there's a limit on team size that brings the complexity down to 10^7. | coding #3
08:16 | uht AC #3 ig | analysing #1
08:34 | have plan for #1 (2x dijkstra for before and after eating hay) | coding #1
08:59 | WA 0 for #1 ? | debugging #1
09:04 | how to make it less equal rather than less than? | break
09:08 | can I just don'tnt on adding the ones w/o hay | debugging #1
09:12 | now how do I still allow visiting through the barn? | debugging #1
09:17 | AC #1 | analysing #2
09:38 | wait, can I just map it? | analysing #2
09:44 | I think that just works | coding #2
10:06 | WA 2/10 (pie math prolly borke) | debugging #2
10:17 | why is my pie math wrong | debugging #2
10:22 | end, 50 min rem

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

Was a graph problem, realized that I could maybe do it in two stages, then realized that i could start dijkstra in the middle by artificially pushing in source nodes.

#### Problem 2:

Thought about computing compliment, realized that it was pie. Had method for computing intersections of one node, but not of more. Realized I could loop through all subsets and use a map directly.

#### Problem 3:

Just simple dp. Didn't even have to optimize because there was a limit on the size of K.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1625 - played Fri 18 Sep 2020 @ 11:11 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:11 | start | reading problems
11:17 | read problems, 2, 3 seem doable | analysing #2
11:39 | have plan for #2 | coding #2
11:47 | AC #2 | analysing #3
11:57 | calculate dist, retrace for weight, cost = weight * saved? | coding #3
12:16 | WA 0?? is this not the max possible ? | analysing #3
12:35 | why might it be wrong answer? | analysing #1
12:49 | knapsack for each rhyme group, calculate possibilites for each letter and multiply? | coding #1
12:59 | hold up, its not that a line an only have words of that kind but rather must end in a word of it's rhyme | coding #1
13:08 | also, knapsack doesn't deal with permutations... now what | analysing #1
13:17 | well, what if we just pretend that we have that | coding #1
13:42 | It works except for the calculation of permutations | debugging #3
14:08 | I don't know what's wrong with 3 still... | analysing #1
14:13 | `dp[i][j]` = ways to get sum `j` with `i` elements? | coding #1
14:33 | noticed that the above equation was overcounting by powers of two, tried adhoc fix but didn't work | debugging #1
14:38 | not sure what I can do now | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

Not sure how to do knapsack when order matters

#### Problem 2:

originally thought it was counting inversions, but I realized you could just simulate it as insertion sort 

#### Problem 3:

not sure why it was WA, maybe I didn't understand the problem correctly?

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1624 - played Wed 16 Sep 2020 @ 23:26 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
23:30 | start | reading problems
23:36 | read problems, seem doable but no ideas yet | analysing #1
23:52 | not sure how to update for #1 | analysing #2
23:59 | I don't understand the question, why is it 4 not 3?? | reading #2
00:06 | have plan for #2 even though I don't quite understand the sample input | coding #2
00:14 | WA sample only #2, not sure what I expected | analysing #3
00:46 | I could do it with a N^2 way of solving the 1 rect version | analysing #1
00:55 | I guess it's time to write brute forces | writing partial #1
01:21 | changeless #1 got WA for one test case only? sad | debugging partial #1
01:31 | lca troubles, now 22 pts RE | debugging partial #1
01:35 | not sure whats wrong with partial #2 causing RE | analysing #3
01:52 | questioning my understanding of the sample test case | analysing #3
02:00 | I feel like I'm missing something here, can't you just paint some edges and get like 30+ k=2?? | coding partial #1 TLE
02:06 | how did that get fewer REs?? WA/TLE/RE #1 45 pts | analysing #3
02:15 | maybe there is no N^2 method after all, what about 2x apple picking? | analysing #3
02:19 | 1. not sure how to update 2, 3: don't understand the sample bruh | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

-

#### Problem 2:

-

#### Problem 3:

-

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1621 - played Wed 2 Sep 2020 @ 17:06 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:07 | start | reading problems
17:18 | read problems | analysing #1, becuase even tho 3 looks easier it historically hasn't been
17:27 | have plan w/ bellman ford + knapsack | analysing #1
17:36 | wayyy tle, now what | analysing #1
17:51 | call that a brute force | analysing #3
18:04 | not sure how to RMQ this | coding brute force #3
18:27 | TLE 30... need to optimize a little | coding brute #3
18:45 | computer is freaking out | break
19:19 | using a different machine now | coding brute #3
19:26 | run error?? | debugging brute #3
19:40 | Wait, that optimization doesn't even improve the complexity over K... bruh | analysing #3
19:42 | I should prolly code brute force #1 | coding brute froce #1
20:09 | Run error not TLE?? | debugging brute force #1
20:20 | are some numbers larger than 1k?? | debugging brute #1
20:23 | 9/10 TLE brute force #1, no time for #2 | optimizing brute #1
20:31 | AC #1 that's soo cheese, 6 min remaining | analysing #3

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

-

#### Problem 2:

-

#### Problem 3:

-

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1620 - played Tue 1 Sep 2020 @ 16:19 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:20 | start | reading problems
16:26 | nem 3 looks doable | analysing #3 complexity
16:51 | #3 harder than it looks (can't djikstra) | analysing #1
17:09 | can you just straight dfs it? can't figure out complexity, call it brute force | coding brute force #1
17:21 | memoization became wa / re? but not TLE | debugging #1
17:34 | this is bad news bears | analysing #2
17:59 | not familiar with 3sum, don't know how to precompute | analysing #3
18:10 | binary search topological sort doesn't even work, does this dp thing even make sense? | analysing #3
18:22 | use 2d rmq for #3? | coding #3
18:42 | wait this MLEs so hard | analysing #3
18:50 | but wait, I can sweep line | coding #3
19:05 | RE #3 | debugging #3
19:24 | this is so weird why does accessing the `val` array RE | debugging #3;
19:35 | N != P and I forgot to use the descretization WA #3 | debugging
19:46 | fixed some bugs, now WA 86/100 | debugging
19:49 | not sure why wa | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

-

#### Problem 2:

-

#### Problem 3:

-

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
# Contest contests/standard-xjoi/1614 - played Thu 27 Aug 2020 @ 16:05 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:05 | start | reading problems
16:12 | not sure how to do any of them | break
16:18 | break | analysing #3, I guess
16:35 | maximum number of factors is 127? should've just brute forced it earlier, can N^2 or smt | analysing #3
16:44 | have plan I guess | coding #3
17:11 | why is this so hard to code | coding #3
17:26 | WA/TLE 72 | debugging #3
17:53 | weird bug | now what
17:57 | bruh | analysing #1
18:10 | semes to work for sample | coding #1
18:19 | AC #1 wow that was alot easier than I thought it would be | analysing #2
18:33 | if its just find the complexity, O(N) sweep and check if it intersects the previous. Knapsack style but binary search on how many before this can be skipped? | analysing #1
18:47 | does it not work for the sample? | analysing #1
18:52 | stressing about timeeee | analysing #1
19:01 | can't ignore later I guess, because one of the first two double is discounted by the big one | analysing #1
19:17 | i really want to keep thinking but I guess I have to write brute force | coding #1 brute froce
19:31 | WA 1 and only 5 mins remaining????? | debugging
19:34 | not sure why wrong ig idk what to do aagh | end

## Contest Reflection

### Knowledge

#### Problem 1:

When I first looked at this problem, I thought it was going to be really difficult. I remember struggling with it alot when I first took the contest. However, I did think that the solution would be something like topological sort.
When I came back to it, I remembered a lexographically smallest topological sort problem where you put all the nodes into a priority queue. That ensures that you always take the smallest node, and by "locking" the value in when you pop from the pq seemed to gaurentee that you didn't put it any later. By anti-relaxing the nodes (maxing each `v` with `u` + `w`) when `u` is popped, it seems to just work.
I didn't think it would be that simple but I guess it really was.

#### Problem 2:

I also initially skipped this problem because I thought it would be really math heavy. Coming back, I started thinking about a simpler version of the problem: what if you only had to find the complexity of the original sequence?
I figured you can O(N) sweep that by sorting by end time and directly checking if it overlapped the previous one. Then I wondered if the previous one wasn't taken, how you would find the next previous one.
At this point, I noticed that you could binary search to find out how many nodes are "overlapped" and that that might allow you to figure out how many reigons this range contributes in total. After playing around with the math for a moment, I came up with each range contributing `2^{N-o-1}` complexities, where `o` is the number of other ranges whose end times are inside this range (binary search on `o`).
After trying it for the sample test case, I realized that this wasn't quite right. Then, **I tried to figure out why by just thinking about it, instead of drawing a more detailed diagram**. This spent a bunch of my time and I didn't gain much out of it, and it ended up just stressing me out.
Finally, I drew a better diagram and realized that in some cases, two distinct ranges are negated into one by a third range that covers both. I was thinking about an expression that would model this, but my brain felt slow (just in general today, but especially here) and didn't come up with a solution in time.
After a bit, I figured that **I should write the brute force first, to try to get a few test cases.** This was lucky because the contest length was actually 3.5h instead of 4, so otherwise I wouldn't have had time to even finish the brute force. Either way, I only got the first test case with the brute froce so it didn't really work out.

#### Problem 3:

I started working on this problem first, because it felt like the easiest. At first, I tried to figure out if there was a secret sorting property or something, but realized that you actually have to calculate each one individually.
Then I wondered how many factors there were, and struggled to find the answer with math for too long. **I should have just written a short code to find out** earlier.
Finally, I realized that there were only at most 128 factors, so I decided to just write a O(N) dfs for each one. At this point, I just needed to figure out how to decide if a subtree is possible or not. I remember having trouble with this last time.
I had some idea of sorting the numbers and using pointers from the front and back to match subpaths together, but after some flopping around with sort time complexities I realized that I could just use counting sort and make sure that each statistic had the same compliment.
This had some edge case issues but seemed to mostly work. The only problem was that the counting sort range was too high, and my complexity would be N^2. So, I had to use a map to store it, which seemed to work but introduced a log factor. I submitted this and got WA/TLE 57 or 72 points.
Then, I tried to optimize by using a counting sort but also having a queue to only check the numbers that were written, which hould be amortized O(N). However, that was screwwing up on the sample test case and I had already spent too much time on this problem, so I just went back to look at the other two.

### Strategy
I could improve on my strategy by spending less time debugging #3 at the beginning of the contest and knowing how long the contest was. I felt something was off with the timer at the beginning, but didn't register that it said 3:29:59 instead of 3:59:59.

### Action item
Practice recursion, and DP. Get better at debugging, but I don't know how to do that specifically.
# Contest contests/standard-xjoi/1613 - played Tue 25 Aug 2020 @ 16:00 (PDT)

The problems are from Gold 2020 Open.

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:03 | start | reading problems
16:08 | vaugley remember problems | analysing #1
16:21 | I think I understand how to do it | coding #1
16:27 | plm #1 coded, segfault?? | debugging
16:38 | AC #1 | analysing #2
16:50 | just make a tree, amortized O(N)? | analysing #2
17:02 | how to update sublinks when coming from a higher node? what if there is a cycle? | analysing #2
17:05 | what if a cow admires two colors? then link both colors? can we just set a group for each admired color? | analysing #2
17:15 | wait I don't understand the question, can a cow admire two cows who have diff colors?? | analysing #2
17:19 | their diagram just confuses me | coding #2
17:29 | I think I still need that amortized tree thing for dist > 2 | analysing #2
17:39 | Patch dsu merge somehow? store a cow who admires each dummy? | coding #2
17:56 | somewhere the merge is finicky | debugging #2
18:09 | finally works for sample | submitting #2
18:12 | WA 1/100? | debugging #2
18:33 | i'm not sure why its only getting one case, reread the problem | reading #2
18:37 | I should look at another problem | analysing #3
18:57 | N^2 DP? | analysing #1
19:00 | maybe just write it as a brute force? I'm running out of time anyways | coding #1
19:11 | not sure how to calculate LCM well, should I just keep thinking? | analysing #1
19:19 | I have to add them... maybe this is the right solution | coding #1
19:27 | Idk if I should go back to coding #2 brute force but this one can get me more cases | coding #1
19:50 | brute force #1 still has WA 1 | debugging #1
19:54 | i can try to code brute #2 ig | coding #2 brute force
20:00 | what if there are loops? | end

## Contest Reflection

### Knowledge

#### Problem 1:

We had talked alot about haircut, so I knew that it was solved with counting inversions. I also remember from the past that it was something about prefix sums, so I just looked for how you can figure out when a hair pair stops mattering.
It turns out that this happens when both have been cut to the same length, aka the global len is the minimum in the pair or less. Thus, you can store how many inversion pairs have a minimum at a_i, and prefix sum over that for the answer.
For a moment, I couldn't figure out how to gaurentee the minimum, but later I realized that when using the BIT method you always have either the minimum or maximum in the pair. Thus, you just have to sweep forwards and use range query, or in my case use one query and subtract it from the running total.

#### Problem 2:

I quickly realized that if you start at a node, then all layers in the tree going off that node must be the same color. I'm not sure why I didn't understand this when I previously saw the problem. However, I couldn't figure out how to merge all the sets right without N^2, because when you merge two sets you have to merge the sets that admire them as well.
I had a sketchy recursive DSU which I think should work, but I don't know why it only gets one test case.

#### Problem 3:

We need to sum the LCMs of all sets S such that the sum of S is = N. I didn't realize this last time I saw the problem, but I now see that it comes from splitting cows into groups that have period of length (size of group). I think this gaurentees that you find all possible periods, but I don't have a rigerous proof for it.
However, I couldn't figure out a math way to sum the LCMs, and I couldn't figure out how to generate the groups quickly to calculate LCM. Besides, it was WA on all but 1 test case. Not sure how to do this problem.

### Strategy

I started with doing #1 because I was pretty sure I could figure it out quickly. That worked out. However, afterwards I spent a lot of time on #2 before moving on to #3. Although I don't think I'm close to solving #3, if it had been easier then that might have been a misplay.

### Action item
Math with LCM? Practice writing recursion because I struggled with that on #3
