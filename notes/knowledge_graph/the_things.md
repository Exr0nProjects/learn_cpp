
# Things to keep in mind
- Properties
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

# Graph
- Properties
    - Pretty much the most versitile thing
    - A collection of nodes and edges
        - Each edge connects two nodes (usually but maybe not different)
- Algorithms
    - Traversal
        - [Depth First Search](#depth-first-search)
        - [Breadth First Search](#breadth-first-search)
    - Singe Source Shortest Path
        - Greedy: [Dijkstra](#dijkstra)
        - Negative Edges: [Bellman Ford](#bellman-ford)
    - All Pairs Shortest Path
        - [Floyd Warshall](#floyd)
    - [Minimum Spanning Tree](#minimum-spanning-tree)

## Graph Storage
- Properties
    - Store connections, uses depend on algorithm
        - In algorithms that only care about edges
            - Ex. bellman ford, kruskal
            - You can use a list of edges that isn't sorted by source
    - Methods sorted by source
        - Adjacency Matrix
            - A N by N array that stores the weight between two nodes (`adj[i][j] = cost to get from i to j`)
        - Adjacency List
            - An array of lists, each list is the edges that come from node `i`
            - Usually stored as `list<int> head[MX];` where head is the head of the linked list
        - Edge list (manual adjacency list)
            - Simulate linked list heap storage with an array
            - <details><summary>Standard Code</summary>

                ```cpp
                struct Edge { ll f, t, n; } edges[MX*MX]; // from, to, next
                ll head[MX], alc=1;
                void addEdge(ll u, ll v)
                {
                    // add a directed edge from `u` to `v`
                    edges[alc].f = u;                   // set `from` value of node, not really needed
                    edges[alc].t = v;                   // set `to` value, this is the important one
                    edges[alc].n = head[u];             // store the id of the next edge in the linked list
                    head[u] = alc++;                    // add the new edge to the linkedlist for that node
                }

                // to loop over the edgelist
                for (ll e=head[cur]; e; e=edges[e].n)   // `e` is the edge id/index
                    if (edges[e].t != pre)              // access `next` with `edges[e].t`
                        visit(edges[e].t, cur);
                ```

            </details>
- Algorithms
    - Anything that uses a [graph](#graph)
- Classic Problems/Uses
    - Anything that uses a [graph](#graph)
- Derived From
    - [Linked List](#linked-list)
    - [Dynamic Allocation](#dynamic-allocation)
- Careful
    - `edges` array needs to be the number of nodes squared!


# Tree
- Properties
    - It's a graph
    - There is only one path between each pair of nodes
    - The number of edges is one less than the number of nodes
- Derived From
    - [Graph](#graph)

## Rooted Tree
- Properties
    - There is only one root
    - Every node has only one parent, except for the root
    - Every pair of nodes has one lowest common ancestor
- Derived from
    - [Tree](#tree)

### PIE on Tree
- Properties
    - A way of combining ranges across a tree path:
        - Add the range from each of the two endpoints to the root
        - Subtract the range from the root to the LCA
- Derived From
    - Principle of Inclusion and Exclusion
    - [LCA](#least-common-ancestor)

### Least Common Ancestor
- Properties
    - Only one in a rooted tree
- Algorithms
    - Constant time: sparse table of dfs order traversal, min depth in range of any occurance of the two endpoints
    - Doubling method ~~([exponential search?](https://www.geeksforgeeks.org/exponential-search/))~~ [with rmq](https://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/)
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
- Careful
    - Don't infinite loop by jumping between two nodes forever

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
    - [Dijkstra](#dijkstra)
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
- Careful
    - Nodes should have default values for everything (including node pointers)
    - Remember to setSize on rotate, insert, delete
    - Always modify both `Node->s` and `Node->n` in insert/delete

## Range Tree
- Properties
    - Stores a set of range precomputations
    - Usually a wrapper over an input array (may start empty)
- Algorithms
    - [Segment Tree](#segment-tree)
    - [Binary Indexed Tree](#binary-indexed-tree)
- Classic Problems/Uses
- Derived From
    - [Range Precomputation](#range-precomputation)
    - [Ranges](#ranges)
    - [Tree](#tree)
- Careful
    - Be sure to remember how your range indexing works!
        - include left or right?
        - zero indexed or one?

### Segment Tree
<details><summary>Standard Code</summary>

```cpp
ll N, D, tsum[MX], addt[MX];
void point_update(ll q, ll addv,                // update one point in the segment tree with these arguments
                  ll k=1, ll tl=1, ll tr=1<<D)  // and these defaults (start at root with range of entire segtree
{
    if (tl == tr)                               // the range is one, therefore we must be at a leaf node and done traversing
    {
        addt[k] += addv;                        // update the add tag, can also use an `apply` function for this
        tsum[k] += addv *(tr-tl+1);             // update the sum, remember to multiply by range and fencepost cuz inc l inc r
    }
    ll mid = tl + (tr-tl>>1);                   // push_down here if using set_tag
    if (q <= mid)                               // if query would be in the left subtree
        point_update(q, addv, k<<1, tl, mid);   // query left, use `lc[k]` if persistent/dynamic
    else
        point_update(q, addv, k<<1|1, mid+1, tr); // remember mid+1 cuz inc l inc r
    tsum[k] = tsum[k<<1] + tsum[k<<1|1];        // remember to update this sum on postorder dfs
}
void range_update(ll ql, ll qr, ll addv,
                  ll k=1, ll tl=1, ll tr=1<<D)
{
    if (qr < tl || tr < ql) return;             // return if query range is out of tree range (no overlap)
    if (ql <= tl && tr <= qr)                   // if query fully covers this segment
        return apply(addv, k, tl, tr);          // apply the tag
    ll mid = tl + (tr-tl>>1);                   // get the middle of the range to propogate subtree range
    range_update(ql, qr, addv, k<<1, tl, mid);  // update both subtrees (cuz range) recursive basecase 
    range_update(ql, qr, addv, k<<1|1, mid+1, tr);  // will stop it if out of bounds
    comb(k);                                    // combine subtree accumulators
}

ll point_query(ll q, ll k=1, ll tl=1, ll tr=1<<D)
{
    if (tl == tr) return tsum[k];               // if left and right bounds equal, we are at leaf
    push(k); ll mid = tl + (tr-tl>>1);          // this uses push, but for only add tag you can use an accumulator
    if (q <= mid)
        return point_query(q, k<<1, tl, mid);   // propogate to proper subtree (tail recursive!)
    else return point_query(q, k<<1|1, mid+1, tr);
}
ll range_query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D,   // standard stuff
               ll acc=0)                        // we can use an accumulator for addtag so we don't have to push
{
    if (qr < tl || tr < ql) return 0;           // sum + 0 = sum, so we return zero in the base case
    if (ql <= tl && tr <= qr)                   // if tree range covered by query
        return tsum[k] + acc);                  // return sum + add tags from traversal
    acc += addt[k];                             // this might need to go before previous lines
                                                //      depending on if addt[k] counds for tsum[k] or not
    return range_query(ql, qr, k<<1, tl, mid)   // return the sum of subtree ranges if query range doesn't fully cover this
         + range_query(ql, qr, k<<1|1, mid+1, tr);
}
```

</details>

- Properties
    - Stores larger segments at the top
    - Each segment is a power of two in length
    - Binary: A segment tree is a binary tree
    - Symmetrical: The structure is recursive and the left and right subtree are the same
    - Tags and lazy computation:
        - Uses tags to store updates that are combined during query when needed
        - No need to check intermediate values or push_down with point update
- Algorithms
- Classic Problems/Uses
- Derived From
    - [Lazy Computation](#lazy-computation)
    - [Range Tree](#range-tree)
- Careful
    - Need 2\*N space, since the tree itself is N-1 nodes
    - Don't forget to initialize

#### Segment Tree Tags
<details><summary>Standard Code</summary>

```cpp
ll tsum[MX], sett[MX], addt[MX];
void apply(ll setv, ll addv, ll k, ll tl, ll tr)// apply tags represented by `{ setv, addv }` to node `k`
{
    if (setv == -1 && !addt) return;            // don't apply anything because tag is null
    if (setv >= 0)                              // if set tag
        tsum[k] = setv * (tr-tl+1);             // apply set tag first (add tag is ignored)
    else                                        // else, no set tag
        tsum[k] += addv * (tr-tl+1);            // apply add tag (remember to multiply
                                                //      by the range of the node)
    sett[k] = setv;                             // push the themselves down
    addt[k] = addv;
}
void push(ll k, ll tl, ll tr)                   // push_down the tags to both subtrees
{
    ll mid = tl + (tr-tl>>1);                   // get mid value to tell `apply` the subtree range
    apply(sett[k], addt[k], k<<1, tl, mid);     // apply to the left subtree
    apply(sett[k], addt[k], k<<1|1, mid+1, tr); // and the right
    sett[k] = -1; addt[k] = 0;                  // reset tags to null
}
void comb(ll k)                                 // combine accumulators
{
    tsum[k] = tsum[k<<1] + tsum[k<<1|1];        // good place to do modulo, or if many accumulators
}
```

</details>

- Properties
    - Tags usually represent the operations that can be applied to the underlying array
    - Some tags are order sensitive (set tag) while others can be applied at any time (add tag)
        - Order sensitive tags require only one per path to leaf, so you need push_down (`push()`)
        - Combinable tags (add tag, mulitply) can be computed lazily
    - Tag precedence and representation matters
        - Decide how any combination of tags will be applied to any other combination
        - Write the `apply` function, which takes tags and a target node in the segtree
        - With the operations `{multiply, set, add}` its possible to just use multiply and add
            - Multiply by zero and add to simulate set tag
            - Multiply has higher precedence
            - See problems codechef-addmul and HDU2578
- Algorithms
- Classic Problems/Uses
- Derived From
    - [Lazy Computation](#lazy-computation)

#### Segment Tree Binary Search
- Properties
    - Binary Search over a set of precomputed/intermediate tags on a segment tree
    - Usually can find the answer to something in logN time (traversing the segtree).
- Algorithms
- Classic Problems/Uses
    - Binary search on empty spaces:
        [POJ 2182 Lost Cows](http://poj.org/problem?id=2182),
        [POJ 2828 Buy Tickets](http://poj.org/problem?id=2828),
        [POJ 2886 Who Gets the Most Candies?](http://poj.org/problem?id=2886)
    - Binary Search across PST of prefix frequency:
        [SPOJ MKTHNUM](https://www.spoj.com/problems/MKTHNUM/),
        [SPOJ COT](https://www.spoj.com/problems/COT/)
- Derived From
    - [Tree Precomputation Binary Search](#tree-precomputation-binary-search)
- Careful
    - The tags must be prefix-sumable to be able to subtract one side from the other/root

#### Segment Tree Storage
TODO
- Properties
    - Heap-like (full binary tree, stored in array)
    - Dynamic Allocation (for PST, BIT-SegT)
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

#### Persistent Segment Tree
TODO
- Properties
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

### Binary Indexed Tree
TODO
- Properties
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

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

## Lazy Computation
- Properties
    - We can store something somewhere for now and use it later
    - Order of things don't matter or will be dealt with 
        - Mixing of update and query?
        - A bunch of update then a bunch of query?
        - One update/query before/after another update/query?
- Algorithms
- Classic Problems/Uses
- Derived From
    - [Precomputation](#precomputation)
- Careful

## Tree Precomputaiton Binary Search
- Properties
    - Binary search over intermediate values in a tree
- Algorithms
    - Treap find rank/kth
    - Segment Tree prefix frequency
- Classic Problems/Uses
- Derived From
    - [Lazy Computation](#lazy-computation)
- Careful

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
    - Range query in constant time after being built
    - Good for min/max, not so good for sum (overlap allowed)
    - Constant time LCA
- Properties
    - a log N by N array that stores the collapsation of ranges (min/max, sum)
    - Each layer stores progressively larger ranges, in lengths of powers of 2
    - Ranges can start at any location
    - Easiest query includes overlap, so it's better suited for an operation that replaces (min/max) instead of sum
- Derived from
    - [Range Precomputation](#range-precomputation)
    - [Dynamic Programming](#dynamic-programming)


# Array
- Properties
    - Continuous memory
    - Random access
    - Philosophy: unkown number of the same thing that we should be able to loop over
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

## Vis Array
- Properties
    - Boolean array to store whether the location has been visited or not
    - Conceptually a map of node to boolean, usually either a 1d or 2d array or `map<pair<int, int>, bool>`
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful

## Dynamic Allocation
- Properties
    - On sparse storage, we can create "linked lists" in our arrays manually
- Algorithms
- Classic Problems/Uses
- Derived From
    - [Array](#array)
- Careful


# Stack

TODO

# Queue

TODO

# Recursion
- Properties
    - Steps
        - Represent the problem
        - Wishful thinking
            - How to use a solved subproblem to solve this?
        - Base Case
            - When do you stop recursing
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful
    - Base case in all dimensions
    - Don't recurse too deep

## Tail Recursion
<details><summary>Sample Code</summary>

Examples of a program to sum the numbers from `1..N` using recursion:
```cpp
// without tail recursion, we need N stack frames
void sum(int n)
{
    if (!n) return 0;
    return sum(n-1) + n;    // new stack frame allocated, this one used to remember to add `n`
}

void sum(int n, int acc=0)
{
    if (!n) return acc;
    return sum(n-1, acc+n); // returning recursive call directly, stack frame reused
}
```

</details>

- Properties
    - Very deep recursion by reusing stack frames
    - Sometimes you need more than one accumulator, depends on number of recursive calls?
- Algorithms
- Classic Problems/Uses
- Derived From
- Careful
    - Make sure it's correct

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
<details><summary>Sample Code</summary>

```cpp
int djs[MX], djf[MX];           // group size (only valid for leader) and father
void init()
{
    for (int i=0; i<MX; ++i)
    {
        djs[i] = 1;             // size of each group starts as 1
        djf[i] = i;             // each node is it's own parent
    }
}
int find(int n)
{
    if (djf[n] != n)            // not leader of subtree
        djf[n] = find(djf[n]);  // path compression, move self directly under leader
    return djf[n];              // return leader, aka the group that self is in
}
void merge(int a, int b)
{
    a = find(a);                // work with leaders of subtrees
    b = find(b);
    if (a == b) return;         // if in same group, ignore
    if (djs[a] < djs[b])        // enforce `a` has more nodes than `b`
        swap(a, b);
    djs[a] += djs[b];           // maintain subtree size of `a`, only valid for leader
                                //  because others might get path compressed w/o size update
    djf[b] = a;                 // put `b` directly under `a`, so all `find` calls under `b` get `a`
}
```

</details>

- Properties
    - A tree stored by "parent" array, root of each tree is the "leader" of the group
    - Merge by putting the leader of one group as a direct descendant of the leader of the other
        - Merge by size, aka put smaller group under larger
        - Lazy merge, the children of the smaller merged leader don't change
    - Lazy Computation
        - `find(n)` function that finds the leader of a group recursively
        - compresses the path for future speed up
    - Extensions
        - Count groups: subtract a counter on each successful merge
        - Merge conditions: only merge if another condition is also true
        - Merge order: merge based on a different property (other than group size)
            - This increases time complexity negligably
- Algorithms
- Classic Problems/Uses
- Derived From
    - [Lazy Computation](#lazy-computation)
- Careful
    - INIT DJS

## Minimum Spanning Tree

TODO

### Prim

TODO

### Kruskal

TODO

## Shortest Path

TODO

## dijkstra

TODO

## Floyd

## Bellman Ford

# Things TODO
String Matching
- KMP
<details><summary>Standard Code</summary>

```cpp
int N, P, nxt[MX];                          // len of string and pattern, pi array
char str[MX], pat[MX];                      // 1 indexed
void set_nxt()                              // initializes the pi arary
{
    nxt[0] = -1;                            // sentry, so we can stop if we are at zero (j == -1)
    for (int i=1; i<=P; ++i)                // for each character in pattern
    {
        int j = nxt[i-1];                   // start at failpointer of parent
        while (~j && pat[j+1] != pat[i])    // while that fail pointer doesn't work (ac auto noises)
            j = nxt[j];                     // continue to next failpointer
        nxt[i] = j+1;                       // remember in `nxt` array
    }
}
void count()
{
    int tot=0, j=0;                         // total matches, cur pos (`q`) in pattern
    for (int i=1; i<=N; ++i)                // for each char in `str`
    {
        while (~j && pat[j+1] != pat[i])    // while not at sentry and doesn't match
            j = nxt[j];                     // continue to next failpointer (same as in `set_nxt`)
        ++j;                                // increment `j` to match next char
        if (j == N)                         // if this is the end of the pattern
            ++tot, j=nxt[j];                // successful match found, shift pattern for next match
    }
}

int main()
{
    scanf("%s%s", str+1, pat+1);            // 1 indexed
    N = strlen(str+1);                      // get length of strings cuz `scanf("%n")` is glitchy
    P = strlen(pat+1);
    set_nxt();                              // init `nxt` array, can be reused if pattern stays the same
    printf("%d\n", count());                // and count occurances
}
```

</details>

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
- Careful
    - Range Boundary Semantics
        - is it include left include right? or include left exclude right?

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

# Dynamic Programming
1. Frame the Question!
1. Write down the Equation
- Don't start coding right away
    - Make sure to write down the equation
- Choose or merge from smaller subproblems
- Find the recursive solution, then look for computational overlap
    - Draw a recursive tree?
- If you don't have to try the subproblems, you might have a greedy problem
- Must have overlapping subproblems

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
    - Dijkstra
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


