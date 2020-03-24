# Contest "psudo tree dp" - played Mon 23 Mar 2020 @ 15:40 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
15:40 | start | reading problems
15:54 | have plans and prelim equations for 1, 2, 4, link to 3 seems broken... | coding #1
16:13 | middle of debugging 1, infinite loops | debugging #1
16:17 | `require` function was bad, should be ok now | submitting #1
16:18 | AC #1 | Coding #2
16:32 | 2 seems to work except uniqueness testing | analysing #2
16:41 | Don't understand the "yes" on the first sample case for #2 | submitting code anyways
16:47 | I thought that #1 was not unique, because jason jack joe jill or jason jack joe jim, but actually the first "option" doesn't work (alex C pointed it out) | analysing how to check uniqueness for #2
16:58 | assumed checking root was enough to determine uniqueness, didn't work | coding #4
17:12 | AC #4 | analysing uniqueness for #2
17:27 | still don't know how to determine uniqueness... call a node quasi if it's subtree has the same value whether you take it or not. It's not that any quasi node prevents uniqueness, see sample test case 1. It's not that any non quasi node creates uniqueness, see (1, 2; 1, 3; 2, 4; 4, 5; 3, 6). It could be that whether the root is determined dictates whether the tree is determined, but I tried that and got wrong answer. Have been looking for counter examples to the root one, but haven't found any. Tried inductive proof but was complicated | continuing to chew at root quasi-ness determinism
17:44 | Have idea for determining uniqueness | coding #2 uniqueness
17:53 | plm new uniqueness check, got WA | debugging #2
17:59 | what if during the dp if there is a undetermined max condition then just set a flag? | coding #2 uniqueness v4
18:19 | AC #2 Finally, skip #3 because link was inaccessable.

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: [DP13 oj12186 Another Crisis](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3338)

This problem was decently simple. I just assumed that framing the question would be one dimensional, and the subproblem structure would be like a tree because any boss requires a number of subordinates to get pressured. That number is the branching factor.  
I had a little trouble with the `requires` function because I somehow screwwed up my algebra it was spitting out the wrong percentage conversion, but it was a pretty quick fix. I had to add a special modulo clause because of integer division.  
**It would help to have more practice doing algebra with inequalities and the `floor` function (integer division)**

#### Problem 2: [DP14 oj1220 Party at Hali-Bula](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3661)

I had the most trouble with this problem, because of the check uniqueness thing at the end.  
The finding of the most number of people to bring was easy enough because we covered it in class and I reviewed last night.  
However, I had a lot of trouble figuring out how to check whether a tree was unique, because at first I was looking for a way to do it by directly analysing the results in the memoized array. For example, I tried simply checking if the root was ambiguous and I also tried saying "undetermined" if any of the subtrees was undetermined, but that was never going to work because it depends on whether the parent is determined and if so, what the parent is determined to be.  
Later, I went to the bathroom and there I thought, why don't I just traverse the tree again from the root and simulate the inviting of the people? That way if the current node is not taken and the value of taking/not taking a child is the same, then the guest list is undetermined. That was a quick way to write it and has the same time complexity, although more recursive overhead.  
I don't know how I would write that in a bottom up fashion though, similar to how I still don't know how to write DP23 in a bottom up fashion.

#### Problem 3: DP15, skipped

Skipped, because the link on the DP doc doesn't seem to work. (Redirects to the OJ homepage)

#### Problem 4: [DP37 tm1039 Anniversary Party](https://acm.timus.ru/problem.aspx?space=1&num=1039)

This problem was also relatively straightforward, because it is just a small variation on the most unconnected nodes problem, like #2. Instead of adding `1` when picking a node, I simply added the conviviality of the person (`value[i]`).

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

I think my strategy during this test was pretty good. Perhaps in the future if I get stuck on something I will intentionally remember to take a break for a few minutes, evaluate whether there's some better method to do what I'm trying to do. See the timing log above for more detalis.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

As I mentioned in the problem 1 reflection, I think I could practice algebra with inequalities and the `floor` function to avoid mistakes like that, and to help with problems like binary search test #2 (dev xjoi 1636 2). I also need to come back and redo these problems as bottom up, and make sure to get dp 15 done. If there is some way to remember to step back and avoid my mistake in problem 2, that would be helpful as well but I don't know how to systematically avoid that.

