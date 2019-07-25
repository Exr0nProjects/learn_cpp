## Summary for Day 12 (20 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
4.4 | 9513 | tree input | TLE
"   | 9517 | guard palace | WA

#### Concepts:
- **Floyd Warshall Algo**: Determine shortest distances between all nodes on a graph _independent_ of edges.
    On a graph with `n` nodes and `q` edges, Floyd Warshall runs in `O(pow(n, 3))`. This means that Floyd Warshall is suitable for densely connected graphs because the number of connections does not slow down the algorithm.

    Essentially, the algorithm takes each pair of nodes in the graph and tries to get from one node to the other through an intermediate node. If the distance from the `start` to `intermediate` plus the distance from `intermediate` to `end` is less than the current best distance from `start` to `end`, then the best distance is updated to reflect the one that goes through the `intermediate` node.

    Some articles about the Floyd Warshall Algorithm can be found on \[[Brilliant](https://brilliant.org/wiki/floyd-warshall-algorithm/), [Geeks for Geeks](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/), [Tutorials Point Q&A](https://www.tutorialspoint.com/Floyd-Warshall-Algorithm)\]


#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | <score>
