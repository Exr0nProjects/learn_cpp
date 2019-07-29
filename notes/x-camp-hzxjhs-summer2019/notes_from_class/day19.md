# Summary for Day 19 (29 July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
  dev.xjoi 1210 | 1 | cover dots with line | WA | For some reason I had a really hard time doing the math for this

#### Problem Review:
dev.xjoi 1210 (today)

Problem 2  
Make a tree, some kind of ring of trees? Use the greedy algorithm we can get `O(n)`.
If the ring is odd then we scam it a bit and splice it together, and theres some kind of binary tree and then you just cout the luo gu and be done with it.

Problem 3  
K1, K2, K3
For every tree store the minimum `b` value?  
`min(h[i], k_x*i + b_min)`
If a tree is behind another and the front one is shorter than the other then some of it is useless but then we remove some stuff and replace it with something else?  
Looks like we store some kind of min heap??

I did not understand the explination of these problems at all. 
## Concepts:
### Bron Kerbosch Algorithm Basics
**Overview**  
The Bron Kerbosch algorithm operates on three arrays, often called `R`, `P`, and `X`. I like to call them "require", "possible", and "exclude". The names are pretty self explanatory, and what each recursive substep the algoritm finds all maximal cliques that include all nodes in `R`, any subset of nodes in `P`, and none of the nodes in `X`. By starting off with `R = Ø`, `P = Universe`, and `X = Ø`, we find all maximal cliques in the entire graph.

**Definitions**  
Cliques:  
_A clique is any subset of verticies on a graph._

Maximal Clique  
_A maximal clique is a clique which has the following two properties:_  
1. _Every possible pair of verticies in the clique is connected._  
1. _There are no other verticies in the graph that can be added to the clique while the clique maintains the first property._  

_In other words, a maximal clique is a fully connected clique that cannot be added to._  
Notably, these maximal cliques are what the Bron Kerbosch Algorithm finds in a given graph.

Maximum Clique  
_A maximum clique is the lagrest maximal clique in a given graph, by vertex count. There can be multiple maximum cliques in a graph._  
The size of the maximum clique is the answer we are looking for to solve problem 4 from day 17.

**Algorithm**
> Each recursive stage of the basic Bron Kerbosch algorithm finds all maximal cliques that include all nodes in `R`, any subset of nodes in `P`, and none of the nodes in `X`.  

This is implemented in the following way:
```python
def union (A, B):
  return set union of sets `A` and `B`
  
def intersect (A, B):
  return set intersect of sets `A` and `B`
  
def neighbors (v):
  return set of verticies connected to `v`

def BronKerboschBasic (R, P, X):
  if (len(P) == 0 & len(X) == 0):
    return R # report as maximal clique
  for vertex in P:
    BronKerboschBasic( union( R, {vertex} ),
                       intersect(P, neighbors(vertex)),
                       intersect(X, neighbors(vertex)) )
    # move `vertex` from `P` -> `X` so that we don't check cliques 
    #   with `vertex` in them in the future.
    P = intersect ( P, {vertex} )
    X = union     ( X, {vertex} )
    
```

Essentially, in each recursive step we zoom in on the new vertex that may be added to the clique, and recursively search through all possibilities that include this vertex in the clique. If we reach a point in which there are no more verticies that could possibly be added to the clique, and if the vertex that we just addded is not connected to any of the verticies that we have already thrown out from the past iterations on this layer, then we have a new maximal clique and so we report it.  
(If `X != Ø`, then we have already reported this maximal queue so we should just skip it and keep going.)

At each stage of the recursion, the following properties hold:
1. All elements of `R` are connected to eachother - `R` is a valid clique.
2. All elements of `P` are adjacent to every vertex in `R` - `union( R, x )` is a valid clique for all `x` is an element of `P`.

This is why we can recklessly add elements  from `P` to `R` - because we have set up `P` in a way that all elements are elegible to be added to the clique.

Note: _The set `X` is not central to the function of the algorithm. Instead, it exists to ensure that the algorithm does not find maximal cliques that have already been reported. Otherwise, the algorithm would find each maximal clique `n!` times where `n` is the number of verticies in the clique._

**Complexity**  
This algorithm runs in `O(n^m)`, which is somewhat atrocious.  
However, we can improve this time by using more complex methods such as by adding a "pivot", see below.

**Sources<a name="bkbasic-sources"></a>**
- [Wikipedia](https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm)
- [SO - Basic Python Iplm](https://stackoverflow.com/questions/13904636/implementing-bron-kerbosch-algorithm-in-python)
- [OpenGenus.com Article](https://iq.opengenus.org/bron-kerbosch-algorithm/)
- [UGlasglow - Report on BK variations](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/report.pdf)
- [UGlasglow - BK Intro Slides](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/papers/bronKerbosch.pdf)
- [SE CS - Basic Bron Kerbosch Time Complexity](https://cs.stackexchange.com/questions/68060/what-is-the-time-complexity-of-the-classic-bron-kerbosch-algorithm-for-finding-c "What is the time complexity of the classic Bron-Kerbosch algorithm for finding cliques?")

### Bron Kerbosch Algorithm (with pivot) / Tomita
**Explanation**  
[OpenGenus.org](https://iq.opengenus.org/bron-kerbosch-algorithm) (as well as [Wikipedia](https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm)) says that the above basic version of the algorithm is inefficient because it makes many useless recursive calls that will not result in a maximal clique. We can augment the algorithm by introducing a "pivot" vertex `u`. Then, in each recursive call we only call the next layer of the algorithm on nodes that can result in a maximal clique based on the pivot.  
The pivot is helpful for reducing the size of the search space from a given recursive state by only allowing the algorithm to search verticies that either are `u` or share no neighbors with `u`, because if the new vertex shared a neighbor with `u` then we could also add `u` to the clique. That possibility is already taken care of when we choose the pivot `u` to be the new `v`.   
The above concept is kind of confusing, but the logic can be clearly seen when view like this:  
> Each element of `P` is already able to form a clique with `R`; the only reason we don't simply `return union(R, P)` is because elements of `P` don't necessarily form cliques amongst themselves (i.e. they aren't adjacent to eachother). However, if an element `v` of `P` is a neighbor of the pivot `u`, then we could add both `u` and `v` to `R` and still have a maximal clique. And because this possibility includes `u`, it is already taken care of when we choose `u` to be the new vertex `v`.

The redundant recursive trees that the pivot processs truncates are normally terminated at the bottom of the tree when `P = Ø` and `X != Ø`. Instead of waiting until the end to make sure we aren't redundantly reporting cliques, we can do some of this pruning during the recursion by only splitting down recursive branches if we are sure that they don't interfere with the pivot.

This means that we need to choose a pivot that maximizes the reduction of redundant branches, by choosing a pivot `u` that has the maximum number of neighbors. This is called Tomita`s algorithm, and has Python code like this:

**Example**
```python
def union (A, B):
  return set union of sets `A` and `B`
  
def intersect (A, B):
  return set intersect of sets `A` and `B`
  
def neighbors (v):
  return set of verticies connected to `v`

def BronKerboschBasic (R, P, X):
  if (len(P) == 0 & len(X) == 0):
    return R # report as maximal clique
  u = element of union(P, X) with maximum neighbors
  for vertex in P & not in neighbors(u):
    BronKerboschBasic( union( R, {vertex} ),
                       intersect(P, neighbors(vertex)),
                       intersect(X, neighbors(vertex)) )
    # move `vertex` from `P` -> `X` so that we don't check cliques 
    #   with `vertex` in them in the future.
    P = intersect ( P, {vertex} )
    X = union     ( X, {vertex} )
```
This is essentially the same as the basic Bron Kerbosch algorithm, but we choose a pivot instead of running through every possibility at each stage. (The skipped possibilities will still be processed further in the recursive tree.) 

_We can find the pivot in `P` or `X` because they are pretty much the same thing, but `X` has already been visited. Thus, it doesn't matter if the pivot comes from `P` or `X`, as long as it is one of them._

**Complexity**  
Although specific complexity of this algorithm depends on implementation, a suite of tests run with java implementations found the number of expanded verticies to be reduced by a factor of between 2 and 2000. The times also ranged in terms of performance, sometimes similar to basic Bron Kerbosch and sometimes reduced by a factor of 2. However, based on the desrciption of the process these [tests](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/report.pdf "Review of the Bron-Kerbosch algorithm and variations by Alessio Conte") were not highly rigorous and results should be taken with a grain of salt.

**Sources**  
See [the sources under "Bron Kerbosch Algorithm Basic"](#bkbasic-sources)

## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 9.5

Today I was decently productive. I am still very slow at looking at problems and recognizing how to do them, as well as debugging, although that will come with time. Instead, I focused today on trying to understand the Bron Kerbosch Algorithm and its pivot extension, which I think I understand now. However, there is this thing called vertex ordering that makes Bron Kerbosch run in `O(3^(n/3))`, which is "the best we can hope for" because there can be up to `3^(n/3)` maximal cliques in a graph [(study)](https://snap.stanford.edu/class/cs224w-2010/readings/tomita06cliques.pdf "University of Electro Communications, Tokyo - Experiments and Complexity Analysis for Maximal Cliques").
