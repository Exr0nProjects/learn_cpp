# Summary for Day XX (XX July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
| pXXXXX | XXXXX | XXXXXXXXXXXXX | XXXXXXXX | XXXXX |

## Concepts:
### Balanced Tree Types
**Desc**
List
-   AVL Tree
-   Red Black Tree
-   Treap

### Heaps
**Should be Complete Trees**
Efficient way to represent if its a complete binary tree:  
child = `2i` and `2i+1`  
parent = `i/2`  
thus `heapify()` is just `array.sort()`  

### Linked List
Used to be much more common, but now it is used less.  
It is very useful but it is easy to screw up because you have to use `new` and `delete`, otherwise you have a memory leak.  
A *memory leak* is the problem of wasted space in heap memory. This can happen when you create pointers with `new` but then don't `delete` them. This happens in linked lists when you delete the first link, because suddenly you don't have a way of accessing the other links and cannot delete them!  

### Stack vs Heap memory
Stack addresses and heap addresses grow in opposite directions, starting from opposite ends of the allocated RAM.  
You almost always allocate in stack memory, but when you use `new` you are using heap memory, and you have to remember to `delete` it afterwards otherwise you are wasting memory, aka memory leak.

### Recursion slowness
Comes from calling the same state multiple times, this is why DP helps.

### Virtual Memory

## Reflection:
| Type | Score (/12) |
|--------|:-------------:|
| Productivity | <score> |

## Further Reading
-   Virtual Memory
-   bellman-ford
-   kruskal
-   prim
-   tobological sort
-   floodfill
-   disjoint set
-   LCA