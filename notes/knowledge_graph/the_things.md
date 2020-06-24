
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

### Full Binary Tree
- Properties
    - All leaf nodes are on the last two layers
    - At most one node has exactly one child, and it is on the second last layer
    - The bottom layer is the only one that doesn't have `(1<<k) -1` (a mersene number of) nodes
    - All nodes to the left of the one child node have two children, and all to the right have none
    - Can be stored in an array (with an `alloc` variable to remember how many nodes there are)
        - One Indexed:
            - Root is at `1`
            - `lc[k] = 2*k = k<<1`, `rc[k] = 2*k+1 = k<<1|1`
        - Zero Indexed:
            - Root is at `0`
            - `lc[k] = 2*k+1 = k<<1|1`, `rc[k] = 2*k+2 = k+1<<1`
- Derived From
    - [Binary Tree](#binary-tree)

## Binary Search Tree
- Properties
    - [Binary Tree](#binary-tree)
    - Sorted from left to right
    - Insert/Query in (depth of the tree) time, `log N`
- Derived From
    - [Binary Tree](#binary-tree)

### Tree Traversal
- Properties
    - Multiple types (three in a binary tree)
        - Preorder traversal: root before children
        - Inorder traversal: root between children
        - Postorder traversal: root after children
    - DFS traversal of a (usually binary) tree
    - If all tree nodes are distinct, two traversals stored in sequence can be used to reconstruct the tree
        - For example, a preorder and inorder traversal is enough information to encode the connections of the tree
        - Recover by finding the preorder root (first element) in the inorder string and recurse.
- Derived From
    - [Depth First Search](#depth-first-search)

### Heap
- Properties
    - Each parent is either larger (max heap) or smaller (min heap) than both it's children
    - Full binary tree (no holes)
    - Implemented with heapify up and down
        - Take a heap with one branch/path out of order and use swaps to maintain the heap property
    - Can be built in o(n)
    - Can be stored in an array (full binary tree)
    - treaps
- Uses
    - Running median problem
        - Given a stream of numbers, output the current median of the set
        - Solution: use a min heap and a max heap, pushing to one or the other as numbers come in based on their sizes
        - The number on top of the larger heap is the median, or the average of the two
    - [Djikstra](#djikstra)
    - [Prim](#prim)
- Derived From
    - [Full Binary Tree](#full-binary-tree)


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

### Treap
- Properties
    - Balanced binary search tree
    - Satisfies bst property (values) and heap property (weights, random)
- Extensions
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
- Derived From
    - [Tree Rotation](#tree-rotation)
    - [Binary Search Tree](#binary-search-tree)
    - [Heap](#heap)
- Usages
    - deduplication/has num
    - previous/next in sorted array
    - running min/max of a set
    - rank of a number (counting inversions)


// TODO: these \/
- Range trees
    - Segment Tree
        - Persistent Segment Tree
            - "vanilla" usage
            - array frequency prefix
            - counting distinct elements in range
    - Binary Indexed Tree
        - Range update (PIE)
        - Prefix Sums


# Precomputation
- Properties
    - Compute some intermediate values that can be used later to solve a problem
    - Problems often come in a build then query format

## Range Precomputation
- Properties
    - Precompute a reduction over a range, usually with an operation (min max sum xor multiply)
    - When querying, if the range of the query is larger than the range that is precomputed then the precomputed range can be used
        - Otherwise, the query would have to go into the range and reduce it to the answer by itself
    - Properties of reduction
        - Can be paused in the middle and resumed later
            - This is why we can reduce part of the array and then come back afterwards to use that precomputation
    - Ranges should not be too large or too small
        - If the range is too large then small or offcenter queries won't be able to use it
        - If the range is too small then the query will have to combine/reduce many ranges
- Uses
    - Range problems (range update, query)
    - counting inversions
- Derived from
    - [Precomputation](#precomputation)

# Prefix Sum
- Properties
    - A way of collapsing an array such that you can expand it later
    - Stereotypical DP
    - Similar to taking the integral of something
    - Can be on any level of derivitive/integral, delta prefix sums are often used
    - Can be used for range update/query but it takes O(n) to do one of the operations
        - So with a delta prefix array, you can do range update in constant time but need to make a pass to query the sum
        - With a normal prefix sum, you can do range query in constant time but need to make a pass to update
    - A number of operations/reducers can be used to combine the numbers:
        - addition
        - multiplication
        - xor
        - why? associative, communitive, x op 0 = x, has inverse
        - The important thing is that you need to be able to "undo" a combination to query a range
    - DP Equation: `prefix[i] = arr[i] + prefix[i-1]`
- Careful
    - fencepost: prefix `l..r (l <= i <= r) = prefix[r] - prefix[l-1]`
        - since if you did `- prefix[l]` then you subtract the `l` but you want to include `l` in the range

# Sparse Table

<details>
<summary>Standard Code</summary>

```cpp
int N, D, table[20][MX];                         

void init()
{
    scanf("%d", &N);
    D = log2(N)+1;                                  // D = depth of the table
    memset(table, 0, sizeof table);                 // reset the memory
    for (int i=0; i<N; ++i)                         // input original array into bottom layer
        scanf("%d", &table[0][i]);                  // this layer has range=1<<0=1, aka only stores one element
    for (int j=1; j<D; ++j)                         // for each layer, range = 1<<j (inclusive)
        for (int i=0; i+(1<<j)<=N; ++i)             // for each start pos in the table which doesn't overflow given the range
            table[j][i] = table[j-1][i]             // reduce the range from the two segments it covers
                        + table[j-1][i+(1<<j-1)];   // from start to halfway through plus from halfway through to end

    // print the table
    for (int j=0; j<D; ++j)
    {
        for (int i=0; i<N; ++i)
            printf("%3d", table[j][i]);
        printf("\n");
    }
}

int query(int l, int r)                             // include left exclude right
{                                                   // this version works for sum, no overlap
    if (l > r) return -1;                           // sanity bounds check, not strictly needed
    int dif=r-l, ret=0;                             // dif is the range which will be bitmasked
    for (int bit=0; bit<32; ++bit)                  // for each power of two that goes into the range
        if (dif & (1<<bit))                         
        {
            printf("%d..%d\n", l, l+(1<<bit));      // (output the range we are using)
            ret += table[bit][l];                   // use that power of two
            l += (1<<bit);                          // move over by that range, to start the next power of two segment
        }                                           // this function works because all numbers can be represented
    return ret;                                     // as a sum of powers of two, so `dif` can be also (also how binary works)
}
```

</details>

- Uses
    - Range query in log n time after being built
- Properties
    - a log N by N array that stores the collapsation of ranges (min/max, sum)
    - Each layer stores progressively larger ranges, in lengths of powers of 2
    - Ranges can start at any location
    - Easiest query includes overlap, so it's better suited for an operation that replaces (min/max) instead of sum
- Derived from
    - [Range Precomputation](#range-precomputation)

# Stack

TODO

# Queue

TODO

# Recursion

TODO

# Iteration

TODO

# Depth First Search
- Properties
    - Search a space (usually with a recursive function)
    - Depth first property
        - When there is a fork, choose one path and go down it as far as you can
        - When you hit a dead end, backtrack and go down the next deepest available fork
        - Essentially, down before over
    - Avoid Loops
        - Previous argument
            - When traversing trees, a simple `pre` argument is enough to avoid revisiting a node
            - <details> <summary>Standard Code</summary>
                ```cpp
                void dfs(ll cur, ll pre=0)
                {
                    for (ll nxt : head[cur])
                        if (nxt != pre)
                            dfs(nxt, cur);
                }
                ```
            </details>
        - `vis` array
            - When traversing graphs or spaces, us a [`vis` array](#vis-array)
- Derived from
    - [Recursion](#recursion)

# Breadth First Search

TODO

## Vis Array

- Properties
    - Boolean array to store whether the location has been visited or not
    - Conceptually a map of node to boolean, usually either a 1d or 2d array or `map<pair<int, int>, bool>`

# binary search
- Look for the sorting property
    - Look for a number in a sorted list
    - The larger the number is, the more/less likely for something
        - Binary search over the answer
        - max of min or min of max
    - remember: either include left include right or include left exclude right
- Check function
    - Can be left/right, or left/mid/right

# Disjoint Set Union


## Minimum Spanning Tree

TODO

### Prim

TODO

### Kruskal

TODO

## Shortest Path

TODO

## Djikstra

TODO

# Things TODO
String Matching
- KMP
- Trie
- AC Automaton
    - Fail pointers
- Tree structure
- Path compression
- Merge by size/rank


For Loops
- Start stop step
- Edge list traversal
- bitwise stepping (binary indexed tree)

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


