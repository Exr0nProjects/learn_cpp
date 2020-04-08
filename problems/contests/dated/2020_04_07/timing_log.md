# Contest contests/dated/2020_04_07 - played Tue 7 Apr 2020 @ 16:01 (PST)

[Link](http://115.236.49.52:83/contest/1351).

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:03 | start | reading problems
16:33 | have vauge plans for 2, but don't understand what a_i does. #1 should be floyd? needs analysis | analysing #1
16:45 | there sohuld be a way to O(1) #1, but idk it | analysing #3
17:02 | no idea/?? | analysing #2
17:15 | don't know about number 2 either | analysing #1
17:34 | don't know about #1... this is kinda sad | analysing #3
17:43 | don't know don't know don't know.. | break
17:48 | break | analysing #1
18:08 | bruh | coding brute force solutions
18:17 | wrote most basic brute force | writing N^2 + LCA brute force for #2
18:29 | coded brute force N^2 for #2 | analysing brute force #3
18:34 | may actually know how to do #4, primes are always odd, except two and h_2 = 2 | sketchcoding #4
18:38 | nevermind, it's not prime factors it's all factors | analysing #4
19:11 | WA #4 | debugging
19:18 | got the 41 points for #4 | analysing #4
19:24 | tried tabulating some stuff in #4, still too slow | analysing #1 hopelessly

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

It was pretty clear that there was a pattern, I just didn't find it. I didn't see the array rotation thing, though I probably should have had I analysed it some more.

#### Problem 2:

I knew that this was cost times longest dist, but I didn't realize that you only needed to try the cost of one, like it says in the solution.

UPDATE:

`max` can distribute, as it says in the solution `max(a, b) * dist[a][b]` = `max(a*dist[a][b], b*dist[a][b])`. I need to get better at working with functions like `max`, `min`, and `floor` in algebra so that I can analyse problems like this in the future.

Given that we are optimizing `size(a) * dist[a][b]`, we can just check any node `a` with the two ends of the tree diameter, because one of those will be the furthest node from `a`. (proof by contradiction: suppose there was a further node, that would be the diameter instead).

#### Problem 3:

This problem felt like DP but I couldn't really wrap my head around the intuition behind it, so it was hard to analyse effectively. This problem also needs more work.

#### Problem 4:

I didn't start this problem until much later, when I realized that it was relatively easy to calculate `h_i` for a given number.
Originally I was looking for a pattern in `h_i` by hand, but then I realized that I had messed up, so then I wrote a quick python program to test and saw that the even numbers just had an `h_even` of their maximum power of two factor. The solution gives a better reason for why that is--because `h_even` must be even, otherwise if it were odd the virus would win, and that carries forwards **somehow** and causes it to be all the two factors.

#### Problem 5:

What the hell.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

I spent a lot of time jumping around between problems, but didn't look at #4 closely until much later because I thought it would be too hard. Not sure how to improve on this though.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

go back an analyse problems 2, 3, 4, 5 eventually. Think about weird transformations, like rotations for problem one. Do more transformey problems that need more analysis, I feel like I give up too easily.
algebra with functions: `max`
