## Summary for Day 14 (23 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
c1205 | 1 | City Driving Turning | TLE | Used DFS. Not sure why it is too slow...
c1205 | 2 | Horse Racing Selection | WIP | Should be doable with DP, but my approach was similar to the apple problem, got distracted

###### Review from yesterday:
- [VJudge 313134-C](https://vjudge.net/contest/313134#status//C/1/):
    The way this person solved this problem consisted of a few stages:
    1. Move to the center
        This will let us set up for the next step
    1. Now, find the quadrant with the least number of rooks in it.
        There will be at least one quadrant that has rooks <= (the number of rooks) /4. Because there are 666 rooks, that means that at least one quadrant will have at most 166 rooks. The other 500 rooks must therefore be in the other three quadrants. We choose to go towards that quadrant.
    1. It only takes at max 499 steps for the king to move from the center to a corner.
        This means there will be no way for all 500 rooks to move out of the other three quadrants before we cross that diagonal. In this way, we are guaranteed to get checked along the way.

- [VJudge 313134-D](https://vjudge.net/contest/313134#status//D/1/):
    Something about binary segmentation of the problem, cutting it in half each time.
    We can traverse the graph and see if any edges go against it's proper DAG.
    Requires use of Topological sorting, see below

#### Concepts:
- **size_t**: an unsigned type to represent sizes in memory

    This type is usually defined per implementation to be either an `unsigned int` or `unsigned long long`, and is used as the type for variables which store memory sizes. Although it is not technically necessary, it is good practice to use the `size_t` type because it makes it more clear what the variable you are defining will be used for. It doesn't look like there are any real disadvantages, as long as you keep in mind that `size_t` will be an `unsigned` type.
    An internet debate discussing the advantages and disadvantages of using `size_t` as an argument type can be found on [bytes.com](https://bytes.com/topic/c/answers/220206-what-size_t), and some quick reference from [cplusplus.com](http://www.cplusplus.com/reference/cstring/size_t/).

- **Topological Sort**: Order the nodes of a DAG such that the parents of each node are always before the node itself  in the sort

    Essentially, we would like to take a Directed Acyclic Graph (DAG) and place the nodes in order such that when we see the `id` of a node, we are guaranteed to have already seen all of the ancestors of that node.
    This is useful for many applications that involve DAGs, such as determining the order to evaluate expressions in spreadsheets or the order to load modules for each dependent piece of new code to be able to run.
    There are two main ways that Topological Sort is achieved:
    - Khan's Algorithm (BFS)
        1. Start by initializing arrays `in_order` and `visited` with enough space to store pointers to each node
        1. Visit each node, and count how many direct parents it has. Store this value in `in_order`.
        1. Find a node that has no ancestors and put it in the front of the queue. This will be our first `source` node.
        1. While we have nodes in the queue, pop the front and take it as `source`:
            1. For each `child` of `source`:
                1. If the `in_order` of `child` is `1` and `child` is not `visited`, then put `child` on in the queue and mark it as `visited`.
                1. Otherwise, subtract `1` from the `in_order` of `child`.
                1. `in_order` essentially counts how many parents are remaining to put in the sort before we can put `child` in the sort.
            1. Add `source` to the end of the Topological Sort.

        Khan's Algorithm runs in `O(|V|^2+|E|)`, where `|V|` is the number of nodes/vertices and `|E|` is the number of edges.
    - Modified DFS
        This is basically the same as normal DFS over a graph, except we keep track of what has been visited and don't visit it again. Whenever we reach a new node, we put it at the front of the sort, such that for each node `source` it is guaranteed that all of its descendants are already in the sort, behind it.

        This version of DFS runs in `O(|V|+|E|)` time, which is faster than Khan's Algorithm. This is usually the easiest way of creating a Topological Sort.

    Further reading can be found: { [Geeks for Geeks](https://www.geeksforgeeks.org/topological-sorting/), [UWashington CS](https://courses.cs.washington.edu/courses/cse326/03wi/lectures/RaoLect20.pdf), [HackerEarth](https://www.hackerearth.com/zh/practice/algorithms/graphs/topological-sort/tutorial/), [Tutorial-Horizon - Algorithms](https://algorithms.tutorialhorizon.com/topological-sort/)  }

- **Bipartite Graph**: A graph with two sets of nodes, where a set of nodes cannot have a connection inside it

    Useful for some problems. We can find out if a graph is Bipartite by DFSing through it and checking if every connected node has the same "color" as the current node, and by "coloring" each node the opposite color as its ancestor when traversing. I don't know why this structure is useful yet, but it came up in the second problem of the contest today.
    Further resources: { [Geeks for Geeks Bigraph Testing](https://www.geeksforgeeks.org/bipartite-graph/), [Example Applications on Stack Exchange](https://cs.stackexchange.com/questions/24057/concrete-and-simple-applications-for-bipartite-graphs), [A Dense Textbook Excerpt from UChicago Math](http://www.math.uchicago.edu/~may/VIGRE/VIGRE2007/REUPapers/FINALAPP/Salvatore.pdf) }

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 7

This afternoon I got distracted by people around me. I ended up not doing too many problems on the test, and getting a bad score. Tomorrow, I will try to not get distracted and stay focused even when people around me are not. However, if it doesn't work then I will find a new spot to sit to be more focused in the future.
