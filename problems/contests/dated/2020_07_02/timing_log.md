# Contest dated/2020_07_02 (Extras 1) - played Mon 6 Jul 2020 @ 11:07 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
11:07 | start | reading problems
11:19 | have plans for 1, 2; 3 scuffed, 4 needs analysis | coding #1
11:27 | wa #1?? | debugging #1
11:36 | still wa | coding #2
11:50 | hold up, dp equation wrong (counts permutations instead of combos) | coding #2
12:16 | finally works for sample | debugging #2
12:19 | still wa | debugging #2
12:28 | idk what i changed but it works now (AC #2) | analysing #3
12:31 | looks like i need custom input | break
12:35 | break | coding #3
12:55 | input seems to work | coding #3
13:10 | tle on input :/ | debugging #3
13:18 | wa #3 | analysing #4
13:28 | i think I have a plan | psudocoding #4
13:32 | seems legit | coding #4
13:49 | WA #4 | debugging #4
13:52 | AC #2, it might help to not comment out the logic | debugging #1
14:07 | forgot other diagonal for #1, still WA | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1: [poj1970](https://vjudge.net/problem/POJ-1970)
simple brute force.

I forgot about the other diagonal at first, but after adding it in with a minute to spare it still WA'd. Not sure why.

#### Problem 2: [uva147](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=83)

I thought it was the classic coin dp so I wrote it like that until i realized that that was counting permutations of coins that sum to the target instead of combinations.

However, I quickly realized that I could just count the sequences but sorted, with a 2d dp equation. That was easy enough to write, although the equation wasn't super clear in my head while coding because I didn't write it down.

#### Problem 3: [uva10100](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=1041)

Basic LCS with string descretization.
Still wrong though, I'm not sure why. I think my LCS is correct...

#### Problem 4: [uva146](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82)
Just next permutation, but I had never written it before. After doing some samples by hand I came up with an induction method that used permute(3) = permute(2) or select next largest and sort. Easy enough to code, I collapsed it down to a pair of for loops.

### Strategy
Time management during this contest was fine, although I felt kind of slow in general. I could've saved alot of time if my DP equation for #2 was correct in the first place, i guess I need to do more paperwork on DP and sanity check that it works out. maybe check if the numbers are way to big by hand first? Or run sample test case manually.

### Action item
Get faster at debugging. Fix problems 1 and 3.

