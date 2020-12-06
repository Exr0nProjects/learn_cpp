# learn_cpp

[![Actively Developed](https://img.shields.io/badge/Maintenance%20Level-Actively%20Developed-brightgreen.svg)](https://gist.github.com/cheerfulstoic/d107229326a01ff0f333a1d3476e068d)

A compilation of solutions to competative programming problems, especially from low level USACO.

## Exr0n's Handbook

This is the core of my understanding of competative programming. It is applicable to all problem solving, as far as I can tell.

### Attack Plan

1. Read question statement
1. Try sample test case to verify your understanding (NO SKIP!!!)
1. Paper work on algorithm/complexity to make sure it won't TLE (NO SKIP!!!)
1. Create a coulpe testing edge cases and make sure the algorithm works (NO SKIP!!!)
1. Coding with as short codes as possible
1. Debugging(hopefully will be minimum with proper 2 and 3)
1. Make up your own test cases to test edge cases for your codes
1. AC

### Time Complexities

My complexities graph can be found here: <https://www.desmos.com/calculator/bhq70wfqsx>.
<img src="./notes/random_intuitions/time_complexity.png" style="border: 1px solid black;">

10^8 operations is usually safe.

## Naming

Don't make names too similar, it's easy to make typos (`djs` vs `djf`)

## Coding
- Simplify
	- Don't use complicated things
		- Just make and pass new vectors, don't do it in place
		- Just use slow STL operations, don't write your own
	- Don't abuse the language
		- Don't use weird, "big brain" things
		- multiply by 2 instead of bitshifting
		- don't try to calculate fibonacci weirdly (`(a = b) += a; swap(a, b);` can break)
		- don't abuse xor
		- don't spam comma operators
		- add curlies
        - don't spam nested expressions
        - don't use assignments as expressions (esp modification assignments like +=)

## Debugging

### Wrong Answer (correct algorithm, edge cases)

0. Always write down buggy test cases and re-test them later
1. Print everything, check "easy path" cases
	- Iteration begin and end variables
	- Recursive arguments
	- Binary search variables
	- Segtree node id and ranges
	- Intermediate math
	- Dump data structures
		- Segtree
		- Treap
		- Sparse table
		- DJS
		- Edgelist
2. Spot checking
    - See algorithm specific pitfalls
    - Read all the compiler warnings
	- Array bounds
		- Segment tree needs 2*N nodes
		- Edge list needs N*N nodes
		- Persistent Segtree and Sparse table need a logN factor
	- Integer bounds
		- long long causes weird bugs
	- Clears
		- map.empty() does not empty the map!
		- check all globals, memset pods only (not pairs!)
	- Initialization
		- INIT DJS
    - Check math
        - watch for `1+min()` over rolling mins, see [here](cses/dp/x_minmizing_coins_up/main_minmizing_coins_up.cpp)
    - Abusing the language
        - See abusing the language (above)
	- See the [spreadsheet](https://docs.google.com/spreadsheets/d/108BTxTj_I0vphA3WWyaXxDSzDrEKQHLStBFrrKi03Ec/edit#gid=2108033227)
3. Check edge cases
	- All zeros
	- All negatives
	- All positives 
	- Maximum value
	- Minimum value
	- Decimals
	- Multi-case in input?
    - Leaf nodes (node 1 is a leaf?)
4. Case generator
	- Make sure casegen has full range of inputs
		- Full min/max?
		- Negatives?
		- Decimals?
		- `l` always less than `r`?
		- Multi cases?
		- All negative/zero/positive?
			- Don't assume `max(0, a[i])` will get `a[i]`, if all are negative
5. Check casegen common mistakes
	- Reread problem carefully
	- Input
		- Needs to be exactly the same
		- Wrong input can cause RE, WA, and TLE
		- Don't `scanf("\n");` on UVA, use `getchar()`
		- Use stringstream if needed
	- Array sizes
		- Some arrays need to be special
			- MX*MX for edgelist
			- MX<<1 for segtree
			- MX by log(MX) for sparse table, pst; sometimes multiply by 2
			- Sometimes the problem is N*K array size or something
6. Compare codes
	1. Align general logic (algorithms and datastructures)
	2. Align data types, representation
	3. Align function semantics
	4. Align variable names, transplant functions
6. Just rewrite it

### Time Limit Exceeded (correct algorithm, optimizations)

#### Something went wrong
- Infinite looping
	- Recursive base cases?
	- BIT will tle if index is zero
#### What to Optimize
1. Symmetries
	- Does the problem have more properties that can be used to calculate only part of it?
2. Optimize Structures
	- Replace sets with hashsets, etc
3. Recursion to Iteration
	- Collapse recursive calls to iteration when possible
	- Not always though, constant factors of advanced structures might be too slow
4. Collapse functions
	- Replace function calls with their source code, or use macros
5. Optimize operations
	- Bitshift instead of multiplying by 2
6. Cache usage?
	- Not sure if there's a good way to take advantage of this reliably...
#### Methods
1. Find what's wrong
	- Starting with the input, comment things out until you get WA
		- remember to `while input` correctly
		- stringstream (37369bf6161219145bca640c8dcf41ec7c5828e5)

### Test Cases

1. Sample test cases
2. Size edge cases
   1. 0, 1, max N
3. Special properties
   1. Try to trick the greedy algorithm or something
4. Graphs
   1. No nodes
   2. One node
   3. Fully connected
   4. Cycles
   5. Negative edges
   6. Disjoint graphs
5. Recursion
   1. Base case

## Algorithm Specific Pitfalls

### Disjoint Set Union
- iNiTdJs

### Dinic
- `kdep` (bfs) must clear the `dep` array and re-populate it
- when adding reverse edges, default weight should be zero.

## Algorithmic Paradighms

- Brute Force
    - Iterate through all posibilities
    - Try to match each state with the solution
    - DFS
        - Go as far as possible
        - Backtracking
        - Stack
    - BFS
        - Layer by layer
        - Queue
    - Complexity
        - How many total states are there?
        - How can that be reduced?
            - Pruning - highly problem dependant
            - Early Termination
- Problem size Constant Reduction
    - Based on induction
    - Recursion
        - Termination condition!
    - Iteration
        - Base case!
    - If there are overlapping subproblems, try DP
    - Dynamic Programming - Decrement problem size
        1. Frame the Question!
        - Don't start coding right away
            - Make sure to write down the equation
        - Choose or merge from smaller subproblems
		- Find the recursive solution, then look for computational overlap
			- Draw a recursive tree?
        - If you don't have to try the subproblems, you might have a greedy problem
- Greedy Algorithm
    - Local optimal = global optimal
- Divide and Conquer
    1. Divide and Conquer
    1. Merge - most important
    - Reduce the problem by ratio/percentage, not by some constant
- Binary Search
    - Look for the sorting property
        - Look for a number in a sorted list
        - The larger the number is, the more/less likely for something
            - Binary search over the answer
            - max of min or min of max
    - Check function
        - Can be left/right, or left/mid/right
- Sweep Line
    1. Sweep a Line - Visualize on paper!
    1. Define Events
    1. What to do at each event?
    1. How to persist state through events with some structure?
- Graphs
    - Djikstra
        - Single source shortest path
        - Greedy
        - No negative edges
    - Bellman Ford
        - Single source shortest path, negative edges ok
        - DP
        - Based on first `k` edges
            - Uses edges for inner loops
        - Rolling array
        - No negative loops - run one more iteration
    - Floyd
        - All pairs shortest path
        - DP
        - Based on nodes, use up to `k` nodes
        - Path recovery - use recursion
        - Rolling array
    - MST
        - Greedy Algorithms
        - Prim
            - Priority Queue
            - Loop over nodes
            - use for dense graphs
        - Kruskal
            - Disjoint set
            - Loop over edges
    - Representation
        - Adjacency matrix - dense graphs
        - Adjacency list - sparse graphs
        - Edge list - not organized by source of each edge

## Data Structures
- Array
    - Continuous memory
    - Random access
- Vector
    - Continuous memory
    - Random access
    - Dynamically allocated -- use `vector.reserve()`!
- Vanilla Tree
    - `N` nodes, `N-1` edges
- Binary Tree
    - Two nodes
    - Full Binary Tree
        - All upper (non-leaf) layers are filled
        - On the last layer, holes are only on the right
        - Can be stored in an array
            - **One indexed!!**
            - Parent of `i` = `i/2`
            - Left child of `i` = `2*i`
            - Right child of `i` = `2*i+1`
    - Heap
        - It's a full binary tree
        - Running Median Problem
    - BST
        - Left is smaller, right is bigger
        - Do Rotations to balance
        - Balanced BST
            - Treap
            - AVL
            - Red Black Tree
            - Just use `std::set` or `std::map`!
### STL
- `std::set`
    - BST
    - single key only
    - needs `operator<`
- `std::map`
    - BST
    - key value pairs
- `std::priority_queue`
    - Fibonocci heap
- `std::unordered_set/map`
    - No internal ordering
    - Constant time access
    - Need custom hash function for pairs

### Algorithms to "memorize"
| Algorithm | Number of times |
|-----------|-----------------|
disjoint set 					| y
kruskal 						| y
prim 							| y
floyd 							| -
floyd(with path constructed) 	| y
dijkstra(no pq) 				| y
dijkstra(pq) 					| y
bellman ford(no path) 			| -
bellman ford(with path) 		| y
tree preorder 					| -
tree inorder 					| -
tree postorder 					| -
basic treap 					| y
otf prev/next treap				| y
KMP								| 
AC Automaton					| 
sparse table 					| -
segment tree					| -
segment tree range update 		| -
convex hull						| 

### Things to think about
- When can you replace min/max BIT with binary search?
    - usaco gold springboards, cses/dp/x_increasing_subsequence_up

### Solving problems
- USACO Silver 2019dec milkvisits:
	- N * M must be too slow, so maybe we know to solve each in N or N log N, aka query must be constant or log
	- an NxN lookup table takes N^2 to fill

#### Training
- 5 hour practice test in the morning starting at 7:30-12:50
- discussion in the afternoons
- Recode wrong problems
- [poj list](https://blog.csdn.net/pyub153/article/details/50480333)
- Debugging
	1. WA: Output everything after each "algorithm"
		- sometimes array size wrong, even tho its wa not re
		- long longs
		- modulo is negative?
		- scanf/printf %lld
		- clears
	2. RE: output after functions to see where it RE'd
		- Array size
		- infinite recursion
		- Array indexing (too big or too small (negative?))
		- nullptr

