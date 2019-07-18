## Summary for Day 10 (18 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
2.13 | 1228 | n queens | AC
2.14 | 7939 | File I/O | AC
"    | 7940 | File I/O | AC
"    | 7941 | File I/O | AC
"    | 7942 | File I/O | AC
"    | 7943 | File I/O | AC
"    | 7944 | std::err | AC
2.15 | 7200 | Struct 1 | AC
"    | 7201 | Struct 2 | TLE
"    | 7202 | Struct 3 | TLE

#### Concepts:
- **speed**: look for redundancy
    Finally solved the queens problem today after Teacher Wang pointed out that I had an
    extra for loop that was not needed in my recursion function.
    It could be simulated by recursing through the same area as the for loop, and removing the for loop
    made the entire programe much faster. Next time, don't waste so much time not noticing things.
    Instead, stop, and get some help.

- **search algorithms**: BFS for maps, DFS for trees
    In general, it seems like BFS is better for maps and DFS for trees and other types of structures. 
    BFS increments one step at a time, and searches the entire area possible with that many steps which makes it good for finding shortest path
    type solutions.    However, DFS goes all the way down the depth of the search space before returning, which makes it difficult to decide weather
    to check if a specific spot can be reached through a shorter path on a map. However, in other structures such as trees, where movement is more 
    restricted to "coridors" DFS can work much lighter than BFS because DFS can easily be implemented with recursion, while BFS often requires a
    seperate data structure to remember what still needs to be visited, such as a `queue`. Choosing BFS vs DFS is important for efficient solving of a problem
    and these factors need to be taken into consideration. 
    
#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 5
