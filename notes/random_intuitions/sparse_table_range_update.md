# Sparse Table Range Update

An argument for why updating a range in a sparse table takes `O(N)` and not `O(N log N)`:
```
the number of locations to update if j==0 is 1<<j = 1
if j==1 then 1<<j = 2... etc. because each level up there are 2**level more ranges that cover the updated location.
thus, the number of things to update is equal to the sum of 2**k for k=0..log_2(N)
Because of the way powers work, this is just equal to 2**(log_2(N) + 1) -1
using exponent rules, that is just 2**(log_2(N)) * 2**1 -1 = N * 2 -1 = O(N)
```

