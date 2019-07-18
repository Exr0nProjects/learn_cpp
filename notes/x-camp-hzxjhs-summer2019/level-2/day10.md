## Summary for Day 10 (18 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
2.13 | [1228](../../../problems/2.13/x1228/main.cpp) | n queens | AC
2.14 | 7939 | File I/O | AC
"    | 7940 | File I/O | AC
"    | 7941 | File I/O | AC
"    | 7942 | File I/O | AC
"    | 7943 | File I/O | AC
"    | 7944 | std::err | AC
2.15 | 7200 | Struct 1 | AC
"    | 7201 | Struct 2 | TLE
"    | 7202 | Struct 3 | TLE
"    | 7203 | Struct 2.1 | AC
"    | 7204 | Struct 2.2 | WA

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
    
- **structs**: Group pieces of data together
    Structs are useful for grouping related pieces of data together. They have many useful applications, such as
    - Grouping things together into an object for better abstraction
    - Allowing multiple data types to be bound into one and used as arguments for functions or elements in arrays
    For example, they can be used to create "node" objects for trees or maps, or to pass a "cow" to a "catapult" function, if the particular problem requires it. All said, it is a way of abstracting data and making it easier to work with. Earlier I noted that `struct`s and `class`es are really similar, and what the differance was. Basically, they are technically almost identical but `struct`s are often used as pure data structures, while `class`es are used to create "interfaces" for other pieces of code to interact with. This is a naming convention that most people follow, so this is a framework we can use when reading other people's code and writing our own. 
    
- **scanf and printf**: Faster for big datasets than `cin` and `cout`.
    For the most part I have been using `cin` and `cout` for I/O because it is easier to use with C++ `std` library classes and types. However, `scanf` and `printf` are much faster beause they don't have the same amount of call overhead as `cin` and `cout`. This makes them much faster to call, and can significantly speed up a program. However, they do not work well natively with C++ types, like `std::string`. Instead, there are often work arounds to the problems such as in this example:
    ```C++
    #include <bits/stdc++.h>
    
    using namespace std;
    
    int main ()
    {
        printf("Hello world!\n");
        printf("`printf` stands for print format. It can format things, similar to Python3 `print` and Java `System.out.format`\n");
        printf("num: %d, char: %c, c-string: \"%s\" and so on.\n", 65, "A", "const char[] (null terminated character sequence");
        
        string mystr = "something like this!";
        printf("and we can convert c++ strings to c strings with %s\n", mystr.c_str());
 
        return 0;
    }
    ```
    The `scanf` and `printf` syntax take a little getting used to, but it's like learning RegExp:  commit once and use it everywhere. 
    
    Notably, `scanf` has some quirks with characters and invisibles in the input stream. Best to explicitly remove newlines from the input stream when inputting characters with `scanf`, with something like `scanf("%c\n", &mychar);`. If something is really broken, try replacing `scanf` with `cin` to see if the problem gets fixed. If so, maybe some speed reduction is worth a working program. 

- **Dijkstra Basics**: An algorithm to find the shortest route on a weighted undirected graph
    Dijkstra's algorithm is often an effective one for finding a route on a graph. Here is a summary of [an article about it on Brilliant](https://brilliant.org/wiki/dijkstras-short-path-finder/) about it. 
    
    Basically, the algorithm entails visiting the shortest unvisited node from the origin and checking if going to a neighboring node from that node is less costly than whatever was previously stored in the node. If it is, then the neighboring node is updated. 
    
    Here is a more detailed set of instructions for the algorithm:
    - Setup
      1. Give every node an integer `id`, starting from 0.
      1. Create 2 arrays \<int\> `dist` and \<bool\> `visit`, each capable of holding all elements. 
      1. Initialize all values of `dist` with `infinity`.
      1. Initialize all values of `visit` with `false`. 
      1. Initialize `dist[start]` with `0`.
    - Execute
        1. For each `idx` in `visit`
            1. If `visit[idx]` is `false` and `dist[idx]` is the minimum of `dist`
                1. `visit[idx]` = false;
                1. For each `idy` of neighbors
                    1. If `dist[idy]` more than `dist[idx]` + `inbetween` (the distance between nodes `idx` and `idy`)
                        1. `dist[idy]` = `dist[idx]` + `inbetween`;
        1. If there are no more `false` values in `visit`
          1. Return `dist`
    
    Notably, Dijkstra is gaurenteed to find the shortest path from the start to any node, however it is a "blind" search which means it does not consider where the objective is. This makes it useful for computing things like vector fields, but it runs rather slowly for computing the shortest distance to a specific node. There are other algorithms, such as a "greedy best first search" algorithm which tries to estimate the distance between a candidate test node and the objective, and searches in the "direction" of the objective. This means it can get trapped in concave obstacles, but for the most part it runs much faster than Dijkstra.
    
    Additionally, A* is a combination of Dijkstra and greedy search algorithms. It tends to perform very well in real world applications because it is fast and versatile. A good A* resource can be found [here](http://theory.stanford.edu/~amitp/GameProgramming/index.html).

- **File I/O**: `freopen`, `fin`, `fout`, `cerr`
    File opening with `freopen` is similar to other programming languages. There are filemodes, and the function returns a pointer to a file stream? It is a little confusing. Some extra sources:
    - [freopen](http://www.cplusplus.com/reference/cstdio/freopen/)
    - [fopen](https://en.cppreference.com/w/cpp/io/c/fopen)
    - [fprintf](http://www.cplusplus.com/reference/cstdio/fprintf/)
    - [cerr](http://www.cplusplus.com/reference/iostream/cerr/)

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 8
