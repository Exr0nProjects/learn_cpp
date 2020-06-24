
# Things to keep in mind
- Properties
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

# Tree
- Properties
    - There is only one path between each pair of nodes
    - The number of edges is one less than the number of nodes

## Rooted Tree
- Properties
    - There is only one root
    - Every node has only one parent, except for the root
    - Every pair of nodes has one lowest common ancestor
- Derived from
    - [Tree](#tree)

### Least Common Ancestor
- Properties
    - Only one in a rooted tree
- Algorithms
    - Doubling method ([exponential search?](https://www.geeksforgeeks.org/exponential-search/))
    - Single pass
- Derived From
    - [Rooted Tree](#rooted-tree)

## Binary Tree
- Properties
    - Rooted and Directed (has a root, each node has a parent).
    - Maximum of two children per parent
- Derived from
    - [Rooted Tree](#rooted-tree)

## Binary Search Tree
- Properties
    - [Binary Tree](#binary-tree)
    - Sorted from left to right
    - Insert/Query in (depth of the tree) time, `log N`
- Derived From
    - [Binary Tree](#binary-tree)

#### Tree Rotation
<details>
<summary>Standard Code</summary>

```cpp
struct Node
{
    ll d, w;                            // data, weight, more fields possible
    Node *c[2] = {};                    // pointers to the children of this node, left = 0, right = 1, nullptr for none
    Node(ll d): d(d), w(rand()) {}
};

void rotate(Node &cur, bool dir)        // 1 = left rotate, 0 = right rotate. Rotate the `dir` child to the top.
{
    if (!cur || !cur->c[dir]) return;   // return if the current or new root is nullptr (failsafe)
    Node *thn = cur->c[dir];            // create temporary pointer to the new root
    cur->c[dir] = thn->c[1-dir];        // swap the between subtree's parent pointer
    thn->c[1-dir] = cur;                // set `cur` to child of `thn`, swapping their depth in the tree
    cur = thn;                          // update the pointer reference to maintain call site's pointer on subtree root
}
```
</details>

- Properties
    - Preserves the BST property while changing the shape of the tree
    - Essentially swaps a child and parent nodes' position
        - This means it can be used as `swap` in heapify (see [treap](#treap))
- Uses
    - Balanced BSTs to reshape the tree and improve complexity
- Derived From
    - [Binary Search Tree property](#binary-search-tree)

#### Treap
- Treap

- Range trees
    - Segment Tree
        - Persistent Segment Tree
            - "vanilla" usage
            - array frequency prefix
            - counting distinct elements in range
    - Binary Indexed Tree
        - Range update (PIE)
        - Prefix Sums

# Prefix Sums
- Operations:
    - addition
    - xor
    - why? associative, communitive, x op 0 = x, has inverse
- fencepost: prefix `l..r (l <= i <= r) = prefix[r] - prefix[l-1]`
    - since if you did `- prefix[l]` then you subtract the `l` but you want to include `l` in the range


- Sparse Table

String Matching
- KMP
- Trie
- AC Automaton
    - Fail pointers
disjoint set (dsu)
- Tree structure
- Path compression
- Merge by size/rank


For Loops
- Start stop step
- Edge list traversal
- bitwise stepping (binary indexed tree)


# binary search
- Look for the sorting property
    - Look for a number in a sorted list
    - The larger the number is, the more/less likely for something
        - Binary search over the answer
        - max of min or min of max
    - remember: either include left include right or include left exclude right
- Check function
    - Can be left/right, or left/mid/right

# heaps
- full binary tree
- heapify up and down
- can be built in o(n)
- stored in array
- treaps

# treap
- balanced binary search tree
- satisfies bst property (values) and heap property (weights, random)
- rotations!
- extensions
    - counted treap (multiset)
        - store extra `n` and `s` for num and size
        - remember to modify both when modifying one
        - `setSize` in rotate, insert, remove
    - ranked treap
        - can get rank of a number when traversing (log n)
        - count how many times stepped right during traversal from root
        - also works with counted treap
    - getkth treap
        - get the kth smallest/largest number in log n
        - step right or left depending on left subtree size
    - pred/succ treap
        - store predessessor or successor
        - three ways to do this
            - lower bound (best, log n, node doesn't have to exist)
                - traverse, store the last time you stepped in the other direction
            - otf constructon
                - constant time given a pointer to the node
                - doesn't work if node doesn't exist in the treap
                - kind of annoying to write (update insert and remove fxns)
            - inorder traversal
                - generally bad
                - need to retraverse each time a node is inserted
- usages
    - deduplication/has num
    - previous/next in sorted array
    - running min/max of a set
    - rank of a number (counting inversions)

# indirection
- swap array values for indicies
- basically counting sort
- watch out for MLE
- may have to do descretization
- usages
    - counting inversions
    - transform the problem/limits

# descretization
- compress big range of numbers, preserve relative size
- create array of pairs with value and index, sort by value
- flip the pair, sort by index while storing sorted index for each value
- useful for indirection

# ranges
- most range combine is include left include right (segment tree, BIT, sparse table)
- most range query is include left exclude right by default (binary search)

# greedy range sequencing
- sort by end time

# indexing
- most problems are 1 indexed
- zero indexing is good for math (modulo)
- often a good idea to leave zero for special cases / sentry
    - edgelist
    - storing full binary tree/heap in array

# recursive backtracking
- store some external state
    - operations
        - step in
        - recurse, process the state
        - undo
    - can be used in top down DP if external state is full represented by the problem fram (dp candy problem)

# convex hull
- sweep line
    - events = points
    - each time, check if the point is on the inside of the line
        - if so, continue
        - if not, binary search backtrack until convex property is satisfied
    - does one half, just repeat the same for the bottom when done
# any intersecting segments
- sweep line
    - events: lines start/end/intersect
    - treap of intersections between segments and sweepline
    - lemma: all intersections occur between lines that are neighbors
    - solution: keep track of neighboring lines in a treap, swap on intersect

# topological sort
- only possible in directed acyclic graphs
- use to check cycles in O(N)

# directed acyclic graphs (DAG)
- no cycles
- directed edges
- all dp problems can be represented as DAGs

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
        1. Write down the Equation
        - Don't start coding right away
            - Make sure to write down the equation
        - Choose or merge from smaller subproblems
        - Find the recursive solution, then look for computational overlap
            - Draw a recursive tree?
        - If you don't have to try the subproblems, you might have a greedy problem
        - Must have overlapping subproblems
- Greedy Algorithm
    - Local optimal = global optimal
- Divide and Conquer
    1. Divide and Conquer
    1. Merge - most important
    - Reduce the problem by ratio/percentage, not by some constant
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


