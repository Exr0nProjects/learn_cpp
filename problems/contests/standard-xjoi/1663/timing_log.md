# Contest contests/standard-xjoi/1663 - played Fri 27 Nov 2020 @ 10:57 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:00 | start | reading problems
11:11 | 1, 3 seem doable.. | analyzing #1
11:56 | can't think of way to do binary lifting #1, will come back later | analyzing #3
12:01 | seems fine | coding #3
12:30 | that took way longer to code then i thought it would, also MLE 0 | analyzing #3
12:36 | decreasing array size to 50% cases gets WA? | debugging #3
12:44 | not sure why WA, or how to avoid N^2 time and memory.. maybe persistent BIT?? | analyzing #1
13:08 | pretty sure this can become LCP but i don't remember how to code it and probably can't figure it out in 50 min | analyzing #2
13:22 | don't know how to do #2, its brute force time | coding brute #2
13:27 | TLE 50 #2 | coding brute #1
13:42 | WA 0 #1 (out of bounds fencepost tripping me up) | debugging #1
13:45 | oops forgot to remove debug, out of bounds logic was fine | optimizing #1
13:55 | memoization optimization did nothing (still TLE 70) | end

## Contest Reflection

### Knowledge

#### Problem 1:

I started by reading the problem wrong. After looking at the sample explanation I realized I should think about it as where numbers are equal. I tried using binary lifting like one problem we went over in class, but having each char point to the next equal char just made chains. I also tried having a char point to the next char that was not equal, but it didn't work. When coming back, I thought about edge weights and realized that it could become LCP by taking the dist to the next equal char. **However, I am not familiar enough with LCP to code it, so I ended up just writing a brute force.**

#### Problem 2:

I thought it might be like Ray Pass me the Dishes but its difficult because it has to be greater than or equal not just equal. Didn't know what to do so just wrote an N^2 brute force.

#### Problem 3:

I thought this was a simple 2d prefix sum problem, but didn't realize that it would both MLE and TLE (I thought N was small enough but didn't think carefully). Later, **I thought a dynamically allocated 2d BIT (almost like PST but without the persistence) could work, but I thought it would take too long to code so went back to thinking about other problems.**
I did code the original N^2 solution but it was WA for some reason, which was another reason I avoided coding the more complex datastructure. (Maybe I understood the problem wrong and that wouldn't even work).

### Strategy
I think my strategy was pretty good, although maybe I spent too much time on the first problem before thinking about other things and coming back to it.

### Action item
practice the daily coding items.. i haven't been doing them recently
