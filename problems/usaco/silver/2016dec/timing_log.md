# Contest usaco/silver/2016dec - played Wed 15 Jan 2020 @ 20:31 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
20:32 | start | reading problems
20:46 | have plans for all 3 | coding #1
20:57 | AC #1 | coding #2
21:13 | 2/10 #2 (others WA) | coding #3
21:27 | 1/10 #3 (others RE) | debugging #3
21:31 | no clue why #3 is RE | debugging #2
21:41 | fixed one problem in #2, now 4/10 (others WA) | debugging #2
21:50 | fixed under anti-overcount, made ret ll, still 4/10 | pause
16 Jan 2020 19:41 | continue | debugging #2
19:54 | AC #2 | debugging #3 (a bunch of REs??)
20:33 | AC #3 | rest and purify (total time: 2h 10m)

## Purify Notes

All solutions used the same logic, analysis, and algorithm as the usaco soln. There was no significant purification.

### Problem 1: haybales

-

### Problem 2: citystate

Didn't read the problem properly. Had to skip any city state where the city and state were the same (to avoid counting pairs within one state).

### Problem 3: moocast

Termination condition didn't work. Was setting `vis` array after recursive calls so the DFS was still visiting already visited nodes.
