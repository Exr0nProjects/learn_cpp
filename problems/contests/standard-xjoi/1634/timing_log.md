# Contest standard-xjoi/1634 - played Sun 22 Nov 2020 @ 13:34 (PST)

## Contest Timeline

| Time | Note | Next |
|----|----|----|
13:37 | start | reading problems
13:45 | read problems, not sure how to do them | analyzing #1
14:00 | have MST merging offline plan for #1 | coding #1
14:35 | submitted #1, need to casegen | analysing #2
14:59 | have idea for #2 | validating #2
15:07 | should work, and 1 got ACed | coding #2
15:28 | WA 44 #2 | debugging #2
15:37 | dunno whats wrong | analyzing #3
16:02 | idek how to model #3 | debugging #2
16:12 | hold up, my method doesn't actually work | analyzing #2
16:30 | have a patch.. does it work | coding #2
16:33 | AC #2 epic | analyzing #3
16:43 | still don't have a plan... probably time to start writing brute forces | analyzing brute #3
16:51 | I hardly even know how to brute force it | coding brute #3
17:06 | welp i guess it's the sum of pascal's triangle with each layer multiplied by the number of segments to the power of M, but too late I guess. | end

## Contest Reflection

### Knowledge
What knowledge did you use in this test, and which part you didn't do well knowledge-wise?

#### Problem 1:

At first I thought it was going to be binary lifting, but then I realized that it was basically some flood fill type thing. I was thinking about how to PST it and then binary search based on K, but I know from previous problems that usually PST is overkill and there is a way to do it offline. This made me think of counting connected component size as a offline flood fill method, and thats how I came to my solution.
Writing the code for this problem was a little annoying because my monotonic sort was backwards and the comparisons were sketchy... I should practice implementing things like this (merge sort, MQ). 

#### Problem 2:

After playing with some test cases, I realized that the farmers should always choose the closest entry to Bessie. Then, I realized that if Bessie got to any node before any farmers, then there needed to be the degree of that node many farmers to catch her. I thought up until this point that there were multiple queries, but after checking the sample input I realized there was actually only one. So, I devised a flood fill taking the max degree "hub" node strategy, where a hub is any node that is closer to Bessie than the nearest exit. That got WA 44. As I was playing with test cases later, I realized that you can't just take the max because Bessie can turn away sooner than that. Some more test cases gave the idea that maybe all hubs need to be counted, but subtract two because Bessie has to enter and exit. That solution worked.

#### Problem 3:

I didn't have much time for this problem. I thought at first it was PIE, but after reading the problem again I realized it should be simple.. because you can take each column individually and place the last stamp at the end. Then I realized that the last stamp can go anywhere.. but didn't know how to avoid overcounting. I later realized it was a matter of placing a number of dividers in and multiplying, but I didn't finish writing this. Will ask someone and update.

### Strategy

I think I could have spent more time on the last problem, but that was only possible if I figured out #2 faster. 

### Action item

- Practice writing monotonic things where a for loop doesn't play well (merge sort, MQ)
- Practice math / combinatorics

