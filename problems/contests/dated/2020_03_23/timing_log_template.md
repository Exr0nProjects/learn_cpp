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


## Purify Notes

### Problem 1:

-

### Problem 2:

-

### Problem 3:

-

## Contest Reflection
1. Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?
2. Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?
3. Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
