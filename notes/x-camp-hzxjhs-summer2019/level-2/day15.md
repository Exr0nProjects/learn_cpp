## Summary for Day 15 (24 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
c1204 | 8 | Hampster Whakamole | AC | ACd using heaps after explained in class
VJudge313606| A | Resturaunt Dishes | WIP | Spend a long time debugging, still doesn't work
"" | B | Min sum of squares pairs | AC | Simply make max different pairs, pattern matching
"" | C | Wandering in park | WIP | Ran out of time after debugging problem A for too long

##### Review of problems from dev.xjoi.net contest 1204 (day 13)
1. Problem 10: traveller's budget (we get some distances and costs of gas stations, ask how much money to get to target)
    1. We start by filling up the tank
    1. When we get to the next gas station, we check if it is cheaper than the fuel currently in the tank
        1. if it is cheaper, we pretend that we didnt fill up the tank at the last station and instead fill it with the cheaper fuel
        1. Then, continue on, always swapping out fuel for cheaper fuel when possible
1. Problem 8: Gopher problem
    1. We use some kind of binary heap to solve this problem.
    1. First, start by ordering the gophers by the time that they leave
    1. Then, for each gopher we place their score in a binary min heap
        1. If the time that the gopher "expires" `d` is equal to the size of the heap, then this gopher may want to be hit at time, so we see if that gopher is worth more than the one that is currently at the top of the min heap. If so, then we replace it and heapify. (We just don't hit the one with the minimum score, and instead hit this new one)
        1. If the `d` is greater than the size of the heap, then we can hit it no matter what so we simply add it to the heap.


#### Concepts:
- **Reb Black Tree**: A Self Balancing BST that is less balanced than AVL but faster to insert/delete
    A red-black tree is a type of self balancing BST. It can be less balanced than AVL, but it wastes less rotations than AVL so we should use this type of tree if the application has lots of insertions/deletions, but AVL if it has relatively more searches. This kind of tree is often used in the backend of the `std` library to implement things like `std::map`.

    Red black trees rely on four properties:
    1. Every node is colored red or black (can be represented with a `bool`)
    2. The root node is always black
    3. There are no two adjacent red nodes (no red node can have a red child)
    4. Every path from any node to any descendant null nodes must have the same number of black nodes

    These properties make it impossible for three nodes in a row to survive. This means that there can never be a chain of three single nodes in a Red-Black tree. This is how these trees ensure balance.

    Insertion of red black trees is somewhat complicated. It consists of the following checks and actions:
    1. Do normal BST insert
    1. If (parent is black)
        1. Easy way out: New leaf node is colored red, everything is ok
    1. Otherwise (parent is red)
        1. If (uncle is red)
            1. Grandfather must be black: Property 4
            1. Color parent and uncle black
            1. Color grandfather red
            1. Recurse up the tree with the grandfather as the new "pseudo-leaf" node
        1. Otherwise (uncle is black)
            1. There are now four configurations that the new and parent nodes could be in.
            1. They correspond nicely with the four AVL cases. Essentially, we left/right/left-right/right-left rotate the parent and grandparent, and then swap the colors of the parent and grandparent.

    This will keep the black-red tree somewhat balanced, although not as balanced as an AVL tree. However, it wastes little operations in the balancing process which makes insert/delete faster but search slower. This is a good alternative to AVL trees. Further reading: { [Geeks for Geeks 1](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/), [2](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/), [visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) }

- **Binary Heaps**: A heap that is also a binary tree
    We can store this structure in an array, see "Storing Binary Tree/Heaps" below.

    To insert, we insert the new node at the bottom of the heap, in the next empty spot of the array. Then, if the new node is out of order compared to its parent, then we simply swap those nodes, and repeat until the heap structure is maintained.

    To delete, we remove the top/root node (that's the whole point of a heap anyways, and if for some reason you want to remove something else then just find it first and call it the root of that subtree, the rest of the heap doesn't care.) and fill it's place with the last node, which is one of  the smallest. Then, take the maximum of { the new root `root`, and the original `left` and `right` children }. The `root` is swapped with the largest of those and the process repeats with `root` as the root of the affected subtree.

    Heaps can be used in many places, (at least that's what it looks like from the past few days because we have been doing heap problems). Usually, when you need to continually find the least or most of something with limited other restrictions, then you want to use a heap. Especially when there is an order to the information you receive or some kind of ordering to when some actions can be performed, we can take advantage of an "intermediate" heap with limited information to find the least/most value with that particular set of information that is available in that stage of solving the problem. For example, the whackamole problem from Monday was heapable because we could make limited information heaps for each frame of time and only insert hamsters into the heap that would expire in that frame of time. This is one way to make the problem smaller and divide and conquer.

    In summary, _heaps are good for maintaining a global min/max, because the min/max can be accessed in `O(1)` and this can be maintained upon insertion/deletion in `O(log n)`. Thus, heaps are good for maintaining a global min/max relatively cheaply._

- **Storing Binary Trees/Heaps**: Basically just shove them in an array
    Because they are always the same size, if we number the nodes starting at the root going layer by layer left to right, then the child of any node will always be `node*2` and `node*2+1` in the array, and the parent of that node will always be `node/2`. This is much more convenient than storing pointers to the children, or storing edges or some shenanigans like that.

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 10

Reflection:
In contests, don't spend too much time debugging one problem. It is mostly not worth it. There is probably a fence post error somewhere. Instead, take a break, look at some of the other problems. Fifteen minutes is not enough to fully write and finish a problem. You should leave at least an hour to finish a relatively simple problem.

I really need to work on debugging, and writing code quickly. The thinking will come later when I become more familiar with writing code. It is difficult to focus on what you are trying to do if the syntax is not unconscious, so that will have to happen before I am able to quickly do contests. Until then, I will keep practicing and trying to learn about different data structures and algorithms.

Further reading:
- Priority Queue
- Fibonacci Heap
- Shell Sort
- Radix Sort
- Function Pointers
- Map
- Unordered Map (hashmap)
