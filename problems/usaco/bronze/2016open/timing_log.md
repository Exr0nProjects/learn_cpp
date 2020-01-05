# Contest usaco/bronze/2016open - played Mon 30 Dec 2019 @ 11:37 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:37 | start | reading problems
11:45 | have plans for 1, maybe 3 | coding #1
11:48 | realize that 1 might be harder than I thought because the total diff < K not diff from one < K | analysing #1
11:53 | AC #1 (was slightly different from what I originally thought but still works the same) | analysing #2
12:06 | have plan for bashy #2 (2.6e7 ops) | coding a mock up? might switch to #3 if takes too long
12:30 | finished overlap func for #2, this is taking a while | will work on it for another half hour before pausing to check #3
12:46 | this over lap func is actually not functional, and this problem is too difficult in general | moving on to #3
12:56 | have plan for #3 | coding #3
13:06 | AC #3 | working on #2 i guess
13:34 | shift code seems to work | now its time to put it all together
14:01 | AC #2 | pause

## Purify Notes

### Problem 1: diamond

This problem was not modified because it uses the same approach as the USACO soln and is quite simple. 

### Problem 2: bcs

My original code for this problem uses the same approach as the USACO soln, but is more readable due to the use of functions. However, it also contains extra logic (to prevent shifting over the edge) which is traded for runtime in the USACO soln. **It is unclear which should be considered better**, so a cpp impl of the usaco soln can be found [here](./xbcs/xnew_bcs.cpp).

### Problem 3: reduce

Although my code uses more memory (it stores all the numbers instead of just eight) it is easier to code (no shenanigans with eight different variable names) so I will prefer my code.
