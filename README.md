# learn_cpp

[![Actively Developed](https://img.shields.io/badge/Maintenance%20Level-Actively%20Developed-brightgreen.svg)](https://gist.github.com/cheerfulstoic/d107229326a01ff0f333a1d3476e068d)

A compilation of solutions to competative programming problems, especially from low level USACO and 115.236.49.52:83.

## Exr0n's Handbook

This is the core of my understanding of competative programming. It is applicable to all problem solving, as far as I can tell.

### Attack Plan

1. Read question statement
1. Try sample test case to verify your understanding (NO SKIP!!!)
1. Paper work on algorithm/complexity to make sure it won't TLE (NO SKIP!!!)
1. Coding with as short codes as possible
1. Debugging(hopefully will be minimum with proper 2 and 3)
1. Make up your own test cases to test edge cases for your codes
1. AC

### Time Complexities

My complexities graph can be found here: <https://www.desmos.com/calculator/bhq70wfqsx>.
<img src="./notes/random_intuitions/time_complexity.png" style="border: 1px solid black;">

10^8 operations is usually safe.

## Test Cases

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
    - Dynamically allocated -- `use vector.reserve()`!
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
