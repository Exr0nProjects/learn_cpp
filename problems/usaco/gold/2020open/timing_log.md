# Contest usaco/gold/2020open - played Sun 29 Mar 2020 @ 09:10 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
09:10 | start | reading problems
09:19 | have idea for 2, but all need more analysis | analysing #1
09:42 | fleshed out N^2 for #1, but it's too slow | analysing #1
09:56 | unsure how to make #1 faster | analysing #2
10:03 | have plan for #2 | quickly coding #2
10:15 | don't understand the sample case for #2 | analysing #2
10:19 | why should 1 be the same as 4 and 5? | analysing #3
10:43 | have some analysis -- can get 1..N and LCM of prime decomposers (primes that sum to less than N) | takinga walk
10:49 | we can get all diverse numbers (no duplicate prime factors) whose factors add to less than N | analysing #3
10:56 | but we can get more numbers, like 12 from 10 (4, 6) and also non-basic cycles (6 thru 5 by 5 in len 10) | analysing #3
11:03 | there's too many options | analysing #2
11:12 | finally understand why #2 has 1 = 4 = 5... cow 2 admires both 1 and 4 so 1=4 | analysing #2
11:34 | how to use disjoint merge? | analysing #2
11:48 | seems like I have to manually put the edges together, O(n)... wait i can use linked lists | psudocoding #2
11:54 | seems legit | coding #2
12:14 | WA/RE #2 | debugging
12:18 | dunno what's wrong | analysing #1
12:26 | I think I can get the second step to O(N), but not the first... | psudocoding #1
12:30 | step 2 optimization works on sample | coding brute force #1
12:48 | WA and RE #1... why? | taking a walk
12:51 | I don't kno why everything is broken | debugging #2
13:19 | still broken | analysing #3
13:25 | have jank plan for #3 | psudocoding
13:27 | nvm, I still have to consider the other possibilities for sub-parts | debugging #1
13:51 | got 5 cases | attempting rolling array
14:07 | rolling array doesn't work | not much I can do now.

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: haircut

I figure this is a dp problem, and reasonably quickly got a two stage N^2 DP that should work. However, it's too slow and risks MLE.  
When I came back to this probem, I realized that the second stage could be shortend to O(n) by splitting from a single quadratic stage into two linear DP stages. This made my code faster, but still it was too slow because of the first stage which was still N^2.  
Later, I tried optimizing the first stage by using a rolling array, but I didn't get that working in time.

#### Problem 2: fcolor

At first, I misunderstood the problem because I thought two cows only needed to have the same color if they admired the same cow, not that if they admired the same color.  
When I realized my mistake, I spent a while trying to figure out how to merge edgesets, but then I realized that I could use `std::list.splice` which is constant time.  
After writing and debugging that, it only got the sample test case. I realized that it broke if you had a cow that admired itself, but after fixing that it was still RE and WA
I couldn't come up with something to break it, so I ended up with just the sample test case.

#### Problem 3: exercise

I realized pretty quickly that you can always get all the numbers from 1..N, but I couldn't figure out how to compute the other numbers quickly enough... because any number includes all possibilities from the numbers smaller than it, and you have to take the LCM of all of the possible "splits" in size.
12: 2  3  4  5  6  7  8  9 10 11 12 14 15 18 20 21 24 28 30 35 42 60

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

As seen above, I jumped around pretty actvely when I couldn't figure something out. I could have left a bit more time for the brute force solution of #1, but I didn't realize that I could use the rolling array until very late in trying to optimize bf1.

I need to think about a better way to organize reflections and takeaways from contests, because reviewing for this one was kind of difficult -- I had to go back through previous timing logs and read them one by one, which is not super efficient.

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?

Do more DP and graph problem practice, get better at coding the classic algorithms. I don't know if there's anything specific that came up in this test that I should explicitly practice.
