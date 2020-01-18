# Contest usaco/silver/2017jan - played Fri 17 Jan 2020 @ 15:59 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
16:00 | start | reading problems
16:08 | have plan for all three, although 2 and 3 are sketch | coding #1
16:39 | 8/10 #1 (4, 10 WA) | coding #2
16:56 | AC #2 | coding #3
17:02 | misunderstood #3 | analysing #3
18:09 | AC #3 | debugging #1
18:26 | AC #1 (faulty binary search) | end

## Purify Notes

### Problem 1: cowdance

**The binary search implementation is faulty.** I had to correct it at the end with while loops to crawl and check, probably a fencepost error somewhere.

### Problem 2: hps

-

### Problem 3: cowcode

I had induced a fencepost error in an attempt to fix this problem, and instead what I should have done is taken `2**l` instead of `l+1`.
