# Contest [!meta:srcpath!] - played [!meta:beg!]

## Contest Timeline

| Time | Note | Next |
|----|----|----|
17:01 | start | reading problems
17:10 | problems seem hard I guess? mathy. | analyzing #5
17:35 | nop | analyzing #1
17:53 | i guess I should think abotu brute forces | analyzing #2
18:07 | can you literally output one letter | coding partial #2 (1,2)
18:29 | WA 50 and got distracted in the middle | debugging 
18:46 | can combine first and second ideas to get full method? submitted not ran | plan
18:58 | not sure what problem to do next | analyzing #3
19:15 | i guess I should code brute forces first | plan
19:19 | point values low I don't want to | analyzing #5
19:43 | what if you counted the complement (truncated subtrees)? | analyzing #5
19:59 | no that wont work | walk
20:10 | walk | brute force time #1
20:53 | toxic to code, more toxic to debug | debugging #1
21:03 | actually wasn't so bad to debug, TLE 40 (and AC #1) | analyzing #1
21:07 | broh what it oscolates? | coding #1
21:20 | apparently it settles into oscellation | coding #1
21:30 | worked for my cases but WA 20? | debugging #1
21:46 | floting point exception core dumped.. not sure where the problem even is yet | debugging #1
22:00 | didn't end up debugging in time.. too bad | end

## Contest Reflection

### Knowledge

#### Problem 1:

Originally avoided because I thought it was going to be difficult. After coding a brute force, I decided to print out the answers and see if they had a pattern (I thought that meeting locations always went up if $v_1 < v_2$ or something). Turns out they just cycle.. so I tried to take advantage of that. However, implementation/debugging was too slow.

#### Problem 2:

Started by creating a string "abcabc..." that has no palendromes of longer than length one (because three letters is enough to cycle). After studying the limits, the $k(k+1)/2$ sounded like triangle numbers so I looked for a pattern with those. I found that a string of sequential letters was what they wanted, so I coded that into the brute force as well. Then I realized that I could concatenate strings to control how many palendromes there were, and I could avoid cross cycling with the original brute force method. This combined method worked.

#### Problem 3:

I tried to think of it from a DP perspective (what happens if you add one node?) because there are multiple quries. Didn't get very far.

#### Problem 4:

Didn't have any ideas for this problem, except to try every possibility. Didn't code it because I opted to work on #1 toward the end.

#### Problem 5:

I spent a while thinking about this problem because I thought it would be fun. I thought maybe it was tree DP, because the statistics for a node can possibly be computed from its neighboors. However, I needed a weighted choose function (choose from an array, sum the products of the subsets) which would not work.

### Strategy
Probably should have spent less time on problem five, and started by coding brute forces. Especially number one, because I thought it was going to be too difficult but it turned out to be doable.

### Action item
Practice implementation, learn to use a debugger, math.

