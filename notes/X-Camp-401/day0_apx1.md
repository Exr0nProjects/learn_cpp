## Concepts
### Topological Sort
**What**  
Topological sort is a set of algorithms used to sort a DAG into a topological ordering. 
A DAG (Directed Acyclic Graph). It runs in `O(V+E)` where `V` is the number of verticies and `E` is the number of edges in the graph. 

**Underlying Idea**  
Topological sort is based on DFS. 

**Uses**  
Lots of problems can be represented as DAGs and DAG problems tend to be solveable with DP because there is a clear progression between states. Topological sort is one way to figure out what order to do each DP state in to ensure that all subproblems are solved before the main one. One example of this is finding the shortest path in a weighted DAG.  
Problems that don't seem to involve DAGs can also be mutated to involve them, such as the longest increasing disjoint subsequence. We can treat each number as a node and draw edges from numbers that are lower to other numbers and before them in the array. This creates a DAG that can be traversed with DP, and looking at the DP solution to this problem shows that indeed this is the ordering that is used.  
Other less obvious problems can also be converted to DAGs, such as a version of the longest increasing subset where instead of having to be in order, there is a different criteria that may be unsorted, such as alphabetical order by name, for example.

It is used in the real world for many problems that involve DAGs, such as dependancy resolution. This problem might arrise if multiple files include headers that refer to eachother, for example, or when evaluating referential cells in spreadsheets.

**Constraints**  
Topological sort only works on DAGs non-empty DAGs.

**Algorithm**  
The two main ways to accomplish Topological Sort are Khans Algorithm and an unnamed DFS algorithm. The DFS algorithm is usually prefered because it is easier to implement, however it uses the stack and runs risk of stack overflow via hyper-deep recursion.  
The DFS algorithm goes like this:
```python
visited = [bool]
output = [node]

def dfs (node):
    if (visited[node]) return
    visited[node] = True

    for next in node.children:
        dfs(next)
    
    output.append(node)

for node in nodes if (!node.hasParents()): # The node is the "start" of the DAG, there is always atleast one.
    dfs(node)

print(dfs)
```