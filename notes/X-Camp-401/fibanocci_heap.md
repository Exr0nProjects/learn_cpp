# Fibanocci heap

Fibanocci heap is a collection of heaps, they do not have to be binary heaps.
Each node has the following things stored:
struct Node:

- bool marked
- doubly linked list of children
- int children aka rank

The rank of a tree is the number of children it has.
We also maintain an array of log(n) that stores a pointer to a root with a specific rank, so there is one pointer to a root of rank 1, one to a root of rank 2, etc.  

Additionally, we keep a pointer to the minimum root.

## Operations

### Insert

Insert is trivial, since trees can be single nodes. We just add a new node with the value into the roots list.

### Delete Min

Delete is also quite simple: We have a pointer to the minimum so just take all of its children and meld it with the roots list, such that the min node has no more children. Then, remove it.

We also need to compress the trees, so using the rank array, loop through the dll and if the position in the array corresponding to the rank of the tree is empty, make that position point to that root otherwise combine the two trees with the bigger root as a child of the smaller root.

### Decrease Key

To delete other elements, we can make their key negative infinity with decrease key and then run delete min. To do decrease key, we first check if the heap property is violated. If not, then nothing changes.  

If the heap property is violated, then meld the decreased node with the roots and check if the parent is marked. If not, then mark it. Otherwise, meld the parent with roots as well and continue upwards. This is to keep the trees flat.

## Time Complexity

It is difficult to figure out the time complexity of such a system, but we can used amortized cost, specificly the potential method, to find it out. The basic idea is that some operations have significant difference in average case and worst case cost, so accounting for an average instead of taking the worst case cost gives a better estimate on run time.

The potential method requires use of a potential function, which satisfies a few properties:

- It must start at zero (before anything is initialized)
- It must always return a non-negative integer

Given the potential of two states, before and after `m` operations, we can compute the amortized running time to be `delta potential/m`.
Using this method, we get that the amortized runing time of decrease key is `O(log n)`.
