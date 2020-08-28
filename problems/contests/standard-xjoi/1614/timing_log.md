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
