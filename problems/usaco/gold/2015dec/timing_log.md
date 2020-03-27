# Contest usaco/gold/2015dec - played Thu 26 Mar 2020 @ 15:47 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:47 | start | reading problems
16:00 | have plm dp frames for 1, 2, sketchy plan for #3 | analysing 1
16:11 | don't know how to do #1 | analysing #2
16:17 | break to think | about #2
16:27 | have plan for #2 | coding #2
16:32 | WA 10/12 #2 | analysing #3
16:36 | seems legit | coding #3
16:58 | WA and empty file #3 (6/16) | debugging #3
17:09 | WA/TLE #3 (12/16) | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

I didn't know how to do this problem, I kept thinking of it as some kind of DP.  
I did think that you needed to sort the cards, but I didn't get to making more observations past that.

After looking at the solution, the problem is relatively simple. I didn't get either of the two key insights however, and perhaps didn't try hard enough. For future and real contests: **Try harder--look for properties if nothing comes to mind**.

#### Problem 2:

I originally thought that I could do a two stage simple knapsack, but my frame was `dp[i][1]` = the most value you can get up to `i`, which I thought would break because the `/2` on drinking water would get over written by other values.  
I ended up doing a little more math and realizing that I could try each drink "location" and get the final value in one expression, so I ended up doing that instead which worked.  
I had one oversight and one edgecase during this:
- **Remember to allow solutions that don't involve drinking water**
- **Check through `T`, not up to it**
Those were quick fixes and got the problem accepted.

#### Problem 3:

I knew this problem was just shortest path, and didn't really think too hard about it. I thought I was using BFS while writing it but I now realize that it is actually djikstra, because I don't always push states that are one more that the current one and so I can't use a normal queue.  
The fixes required for AC from when I ended:
- **Use vis array instead of set to prevent TLE**
- **End at y=N, x=M not y=N, x=N, stupid mistake**

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

I think my timing was decent during this test, I did correct time complexity analysis this time.  
I wrote down the dp equation I was planning on using for #2, which was good because during that process I realized that it might not work. I then took a walk around and figured out an even easier solution, which is to just scan the dp array and take a max over an expression.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

I need to be more careful when coding, because all the things stopping me from getting problems 2 and 3 accepted were stupid little mistakes.  
This will probably be better if I am more awake and alert during the contest, but I should double check everything I am typing, I guess.
