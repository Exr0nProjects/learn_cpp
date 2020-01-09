# Time complexity

**Some basic patterns in time complexiy based on the type of problem**

Simple DP problems can usually be solved in O(n) or O(n log n), O(n^2) is often too slow.  
Graph problems can rarely be solved faster than O(n log n), and O(n^3) is probably the upper bound.  
Simulations problems are more flexible, O(n^3) is usually fine (atleast for USACO Bronze).  
DQN (divide conquer) algorithms usually run in O(n log n) (think merge sort), and the merge function should run in O(n).  
