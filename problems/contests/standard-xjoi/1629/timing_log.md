# Contest contests/standard-xjoi/1629 - played Sat 19 Sep 2020 @ 7:40 (PDT)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
07:42 | start | reading problems
07:49 | 2, 3 seem easier | analysing #2
08:08 | not sure how to find number of pairs intersecting at atleast 2 flavors | analysing #3
08:11 | there's a limit on team size that brings the complexity down to 10^7. | coding #3
08:16 | uht AC #3 ig | analysing #1
08:34 | have plan for #1 (2x dijkstra for before and after eating hay) | coding #1
08:59 | WA 0 for #1 ? | debugging #1
09:04 | how to make it less equal rather than less than? | break
09:08 | can I just don'tnt on adding the ones w/o hay | debugging #1
09:12 | now how do I still allow visiting through the barn? | debugging #1
09:17 | AC #1 | analysing #2
09:38 | wait, can I just map it? | analysing #2
09:44 | I think that just works | coding #2
10:06 | WA 2/10 (pie math prolly borke) | debugging #2
10:17 | why is my pie math wrong | debugging #2
10:22 | end, 50 min rem

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

Was a graph problem, realized that I could maybe do it in two stages, then realized that i could start dijkstra in the middle by artificially pushing in source nodes.

#### Problem 2:

Thought about computing compliment, realized that it was pie. Had method for computing intersections of one node, but not of more. Realized I could loop through all subsets and use a map directly.

#### Problem 3:

Just simple dp. Didn't even have to optimize because there was a limit on the size of K.

### Strategy
How did you spend your time during the test, and whether there's any issue about your strategy?

### Action item
How would you change your homework, your mastery of knowledge, or class time etc in order to do better next time?
