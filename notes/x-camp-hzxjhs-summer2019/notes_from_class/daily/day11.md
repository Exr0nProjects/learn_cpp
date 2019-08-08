## Summary for Day 11 (19 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
4.4 | 9513 | in/store trees | WA

#### Concepts:
- **games**: Usually you can make a DAG and run dp on it

- **Storing Maps by Edges**: using a linked list of edges to store maps and trees

    We use a set of linked lists to store edges. Each linked list contains the edges that lead from a specific node. We have a head array to store the starts of the linked lists, and when we want to see all of the edges leading from a node, we just go to the start of the linked list, which is stored by the head array. Then, we can traverse the linked list to get all of the edges leading from the original node, and for each edge we can run the same process on the node that that edge points to. This is a fast way to store and process a tree, and is versatile because we can store edges given different criteria. For example, we can store an edge in the linked list of a node not only when that edge leads from the node, but maybe also when it leads to the node. By varying this criteria, we can make this structure useful for many applications.

    TLDR: Instead of storing nodes with arrays of other nodes that are pointed to, we store the edges in sets of linked lists so that we don't have to do expensive array expanding operations like `push_back` in vectors. Instead, we simply use linked lists to store edges and add to the end when needed.

- **Binary Search Tree**: a binary tree (each node has at most two children) that is ordered

    It is organized such that all nodes to the right of a node is greater in value than that node, and all nodes that are to the left are smaller in value. This makes it easy to search the tree because at each node you can simply go to the right if the value you are searching for is larger than the node, or to the left if the target value is smaller.

- **Counted BST**: A binary search tree that has a value and count variable stored at each node

    This has all of the advantages of a normal BST, except it can hold multiple accounts of each value, by holding a `count` variable along with the `value` variable at each node. This allows the BST to hold the same value multiple times over, and still make searching the tree easy.

    We can also calculate the `weight` of a node as the sum of the weights of the two children nodes, plus the count of the current node. This recursive system allows us to figure out what index a specific number should be if we were printing out all of the values, for example. This "ranking" property is useful for many applications.

- **Tree Balancing**: In BSTs, we want short trees
    The shorter the tree, the more efficient search will be happen when the tree is balanced.

    There are some ways to achieve this, such as:
    - Random Sort: We scramble the data before starting creating the tree
    - Read From a Heap: By combining trees and heaps, we can get more balanced trees
    - AVL: A self balancing tree structure, which uses "rotations" to balance out an unbalanced tree.
        (This is the most effective method to keep your tree balanced)
        See below:

- **Tree Balancing: Rotation**: Rotate the tree to keep the BST properties but make the tree more balanced

    AVLs use this kind of method to keep a BST balanced. There are four types of "rotations" that are used to keep a tree like this balanced:
    - Left: Rotate once left. This works when the top two layers have only one child per node.
    - Right: Same as above but on the right.
    - Left-right: When on average there are more than two children per node, we need these combination rotations, which involve rotating a subtree one direction and then rotating the whole tree the other.

    A good resource for AVL tree rotation basics: [https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm]

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | <score>

We should probably try and get a computer to share so that we can see what the teacher broadcasts onto peoples screens. Maybe we can squeeze in by the other Alexes?

What is "Cha1 Lu4"??
