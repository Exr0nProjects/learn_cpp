# Bellman Ford

## What

The bellman ford algorithm computes the shortest path from a source vertex to all other vertices on a connected digraph. It is slower than Dijkstra, but works with negative edge lengths.

## How

Bellman ford works similarly to Floyd Warshall, in that it is a DP algorithm at heart. It considers the distance to each node from the source through at most one edge, then two, then three, etc, until it considers the distance from source through at most all of the edges.

## Why |V|-1 Times

If the graph is a line (linked list), and we happen to loop through the edges from the furthest to nearest to the source, then we need to loop through |V|-1 times in order to properly update the weight to the final node.

## Detecting negative weight cycles

We can loop through all the edges once more to check if there are any changes in the weights. If there are, then there is a negative weight cycle because the first |V|-1 iterations should have already covered all the edges, even in the worst case.

## Sources

- [Wikipedia](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
- [Geeks for Geeks](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)
- [Brilliant Wiki](https://brilliant.org/wiki/bellman-ford-algorithm/)
- [MIT 6.006 L15](https://courses.csail.mit.edu/6.006/spring11/lectures/lec15.pdf)
