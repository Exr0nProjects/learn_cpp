## Summary for Day 16 (25 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
VJudge 313606 | C | Park wandering | <stat> | Used  `std::priority_queue` instead of a heap, help from Alex Guo. The issue was I was relying on `queue.top()`, but the top item was changing on a new push because it was implemented as a heap.
dev.xjoi 1207 | 1 | Minimum Lumberjacking | AC | Simple after you understand it, find dist to nearest tree
"" | 2 | Modulus thing? | WIP | Not sure what the problem even means

#### Problem review
1207 (Today) Problem 3
Alice and Bob game. We use a 2d DP approach where the value at [i,j] is the probability of alice winning when alice has i points and bob has j points?

Problem 2
Search problem, "zhe ban sou suo" aka halving search
similar to extreme size knapsack problem, where you knapsack one side and then knapsack the other
uses "ni4 yuan2", whatever that is

dp start values: `dp[i][n] = 1` and `dp[n][j] = 0`;
Alice has two possibilities:

`dp[i][j] = 1/(pow(2, k))`

#### Problem review
Yesterday problem 4
some kind of DP

`f[i][j] -> f[i+1][j]`
`f[i][j] -> f[i+1][j+1]`

and some other stuff, it's all kind of confusing

#### Concepts:
There's literally nothing here this is so sad.

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 8

Today was decently productive but I had a hard time focusing so I did not get too much done. The test today was somewhat difficult, with some weird questions.
