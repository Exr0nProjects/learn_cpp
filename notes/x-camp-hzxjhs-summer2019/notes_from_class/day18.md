# Summary for Day 18 (27 July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
  pXXXXX | XXXXX | XXXXXXXXXXXXX | XXXXXXXX | XXXXX

### Problem Review:
VJudge 314632 (Yesterday)

p2: dp, where `dp[i][j]` is equal to number of combinations with an array of size i and the sum % 3 == j.

p3: bfs, we consider one search layer at a time and hold a counter, to make sure each turn we do not move more than `s` steps

p4:
- Use a map to (li3 san1 hua4)
- We want to find friends who don't obstruct each other,
- Somehow we convert this to an n digit binary number, which  represents what friends will come when.
- We make an array of these and then somehow convert this into a graph, at which point we find the longest continuous path?
- This problem can be converted to another problem, and both of them are np. They form an np-complete problem pair.
- Something about a bron-kerbosch search algorithm.
- This is a `O(2^n)` brute force, which is somewhat massive.
- We can store the "clique" bits with an [`std::bitset` from the `<bitset>` header](http://www.cplusplus.com/reference/bitset/bitset/).
Basically, make an array of 10^5 bit masks, one for each friend, and call each bit the space between two time points where Hiasat can change his name. A `true` value in a bit means that friend visits the site between those two time values. With these bit masks, if any two friends have a `true` bit in common then they cannot both be satisfied. Next, we create a disconnected graph with one node for each friend, and draw an edge between all friends that have common `true` bits. We then find the [maximum independent vertex set](https://www.tutorialspoint.com/graph_theory/graph_theory_independent_sets.htm) of the graph, and the number of vertices is the answer to the problem.

Notably, there is a somewhat efficient brute force for finding the maximum fully connected set in a graph, and we can convert this problem to that one by taking the edge inverse. In other words, we connect all of the friends that do not interact with each other and put edges between them, and then we find the maximum fully connected set with the Bron-Kerbosch algorithm.

This problem makes significant use of new concepts for me, including bit masks, graph inverses, and the maximum independent set / maximum fully connected set, and maps to store the names. See more of these concepts below...

## Concepts:
#### Bit Masks
**Overview**

Bit masks are used to keep/flip/write certain bits. In general, these bits don't represent binary numbers the way most sections of memory do, and instead may represent other things, such as a snowflake. Usually, there is a value and a mask, and we can use different bitwise operators to "mask" the mask on the value. The bitwise operators used are `&` for keep, `^` for flip, and `|` for write.

**Examples**

For example, if we are working with 8 bit numbers we might use a `0b00001111` (`0x0f`) mask to read the last 4 bits of an 8 bit value. We would do something like this:
```c plus plus
    0b01101011  <- value
 &  0b00001111  <- mask
--------------
    0b00001011  <- answer
```
which, as you can see, extracts the last four bits of the original value.

**Uses**

Some problems are more easily solvable with bit masks, such as problem D from yesterday's test (CodeForces \#553, Div 2). The problem was solved with some complex transformations, where we start by reading the input into an array of bit masks. These bit masks can then be used for other things, such as constructing a graph, which is the next step in that problem.

Another example of using bitwise flags and masks is the N Queens problem. We can store four bitwise flags, one for board horizontal, vertical, and two for the diagonal directions and use these to store what board spaces we can place new queens on instead of storing the entire board. This significantly compresses the amount of storage needed even for bigger chessboards from a space complexity of `O(n^2)` to `O(6n)`. The lessened search space also allows a recursive backtracking algorithm to run faster.

These kinds of bit flags and masks are also used for many real world applications, such as permissions for files on linux computers, which are stored as three bit flags for read, write and execute. Bit masks are also used in IPv4 in the form of net masking, which is why so many LAN ip addresses start with 192.168 (they were masked with 11000000:10101000).

**Sources**
- [SO - What is bit masking?](https://stackoverflow.com/questions/10493411/what-is-bit-masking)
- [LearnCpp.com - Bit Flags and Masks](https://www.learncpp.com/cpp-tutorial/3-8a-bit-flags-and-bit-masks/)

#### Bron-Kerbosch Algorithm
is complicated...

#### Map
**Overview**

Maps are basically the same as Python dictionaries, in that they associate a key with a value. However, in python the key must be of type `str` while in C++ the key can be any type. `std::map` tends to store values in a binary search tree based on a comparison object, which should follow a "strict weak ordering", whatever that means. The ordering makes it possible to iterate through the map, however it also means that `std::map` is slightly slower than `std::unordered_map` defined in the `<unordered_map>` header.

**Examples**

We can create a simple `std::map` with keys of type `std::string` and values of type `int` like this:
```c plus plus
#include <bits/stdc++.h>
using namespace std;

int main ()
{
  map<string, int> mymap;

  mymap["cow"] = 6;
  mymap["dog"] = 8;
  mymap["turtle"] = 7;

  printf("%d", mymap[cow]);
}
```

We can also create a map that uses a custom ordering for its key sorting, with either a compare class or a compare function pointer, like this:
```c plus plus
#include <map>
#include <cstdio>
#include <string>
using namespace std;

bool strComp (const string& a, const string& b)
{ // Compare lexicographically as a demo, even though std::string already has this feature implemented with operator overloads
  if (a.length() < b.length()) return true;
  else if (b.length() < a.length()) return false;

  // String lengths are the same
  for (int i=0; i<a.length(); ++i)
  {
    if (a[i] < b[i]) return true;
    else if (b[i] < a[i]) return false;
  }
  // We don't actually need to worry about the case where `a[i] == b[i]` because the keys will never be exactly the same, after all, that is not allowed in a map!
  return false;
}

struct StrComp
{
  bool operator() (const string& a, const string& b) const
  { // This is the same logic as in the `bool mycmp(string, string)` function
    if (a.length() < b.length()) return true;
    else if (b.length() < a.length()) return false;

    for (int i=0; i<a.length(); ++i)
    {
      if (a[i] < b[i]) return true;
      else if (b[i] < a[i]) return false;
    }
    return false;
  }
};

int main ()
{
  bool (*fcmp) (const string&, const string&) = strComp;
  map<string, int, bool(*)(const string&,const string&)> funcComp (fcmp); // We pass the class constructor template a function pointer to specify that we are using a comparison function

  map<string, int, StrComp> classComp; // But if we use a class comparison method, we can simply pass a reference to the class definition
}
```
and accessing the info stored is done with the `[]` operator and the value of the key. Pretty much the same as an array, or again, a Python dictionary.

**Summary**
Maps are pretty much dictionaries, but the key can be any type/class. However, they are ordered which means the key type must have a strict weak ordering property (???), and we can provide a custom compare function through either a class method or a function pointer. Maps are somewhat slower than unordered maps, but they can be iterated through which is a big advantage.

[cplusplus.com](http://www.cplusplus.com/reference/map/map/) says that "Maps are typically implemented as _binary search trees_.", which means that they have a similar complexity. It depends on what the specific BST used is, but I assume it is a self balanced one and so it is probably AVL or a Red Black Tree.

**Sources**
- [Cplusplus.com - `std::map`](http://www.cplusplus.com/reference/map/map/)

#### Extended Euler's Algorithm
**Math and Implementation**
`ax + by = gcd(a, b) = gcd(b, a % b)` <- this is the heart of euler's algorithm
```
ax = by + 1
ax = 1 (mod b)
```
and something about
```
x = y'
y = x' - floor( a/b )*y'
```
where `ax+by = gcd(a, b)` and `x'` and `y'` are the previous `x`, `y` respectively.

This means that once we have one solution, we can go back and find all solutions. And there is one trivial solution with Euler's GCD method: where `x = 1` and `y = 2`;

```
int exGcd(int, intb, int&x, int&y)
{
  if (b==0)
  {
    x=1; y=0;
    return a;
  }

  int r=exGcd(b, a%b, x, y);
  int t=x; x=y; y=t-a=b*y;
  return r;
}
```
**luogu P1082**
Find the problem [here](luogu.org/problem/P1082).

_Given `a` and `b`, find the minimum `x` such that `ax=1 (mod b)`_.   This uses the above strategy, somehow? `ax=by+1` -> `ax-by=1`

**Sources**
- [Brilliant Wiki - Extended Euclidean Algorithm](https://brilliant.org/wiki/extended-euclidean-algorithm/)
- [Article in Mandarin explaining the math](blog.csdn.net/fearlessxjdx/article/details/74276376)
- [GfG - Euclidean Algorithms (Basic and Extended)](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)

## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 9
