# Contest usaco/bronze/2017jan - played 29 Dec 2019 @ 11:06 (PST)

## Contest Timeline

| Time | Note | Next |
11:07 | start | reading problems
11:15 | have plans for first 2 problems (1 is iffy) | writing #2
11:33 | 4/10 (final 6 WA) for #2 | researching for #1
11:54 | 10/11 (test case #3 WA) for #1 | analysing #3
12:19 | still don't know how to do #3 | debugging #2
12:27 | AC #2 (was missing parenthises) | debugging #1
12:31 | AC #1 (was missing tie condition where two cows are both second last) | analysing #3
12:42 | Have idea for #3, (toggle furthest always) | more paper testing
12:51 | convinced | Coding #3 now
13:23 | 9/10 (#2 WA, probably missing edgecase) | debugging now
13:26 | AC #3 (had to fix base "impossible" case which actually happens if input is "1\n1") | answers and purify

## Purify Notes

### Problem 1: notlast

My method for second smallest is `nlogn`, but by running multiple array_mins we can achieve `O(n)`. However, I am leaving my original method because it is easier to code and debug (`std::sort`)

### Problem 2: hps

My method was rather complex for this problem compared to the USACO answer, because I didn't realize that there was a simple two state solution. Due to the cyclic nature of rock, paper scissors, either the ordering is `1>2>3>1...` or `1<2<3<1...` so we only need to test those two states. See [purify_hps](./xhps/xpurify_hps.cpp).

### Problem 3: cowtip

My method was a slightly more confused version of the USACO provided answer: because I was not sure if I could simply use any of the "farthest" spots, I wrote a complicated recursive `fathrest` function to diagonally snake and test each location. Instead, I could have gone bottom up, right left and achieved the same results. See [purify_cowtip](./xcowtip/xpurify_cowtip.cpp).
