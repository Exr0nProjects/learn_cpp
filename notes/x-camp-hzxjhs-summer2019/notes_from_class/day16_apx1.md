# Appendix 1 for Day 16 (25 July 2019)

## Concepts:
#### Priority Queues
**Theory**

The simplest implementation of priority queues use arrays, because they are easy to understand and use. However, they are not particularly fast (read `O(n)`, insert `O(1)`, delete `O(n)`).

However, priority queues are often implemented with heaps, where whenever a new item is added to the priority queue, it is also added to the heap. Most priority queue implementations use binary heaps because they are relatively simple and fast  (read `O(1)` and insert/delete `O(log n)`). However, we can also use Fibonacci heaps which significantly speed up the insert operation (insert `O(1)`). The `std` library uses Fibonacci heaps to implement `priority_queue` which makes it a good wrapper for any heap and priority queue needs.

**STL Implementation**

Priority queues (defined in the `<queue>` header for C++11) are essentially heaps.
You can `push()` and `pop()`, and access the element with the least sort through `top()`. Here is an example of priority queue usage:
```C++
#include <bits/stdc++.h>
#include <queue> // for priority_queue
#include <vector> // for vector
#include <functional> // for greater
using namespace std;

int main ()
{
  // Create the priority_queue
  priority_queue< int, vector<int>, greater<int> > mypq;
  // Make sure to separate `>` signs to avoid creating an accidental pipe!

  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    int t;
    scanf("%d", &t);
    mypq.push(t);
    printf("Minimum so far: %d", mypq.top());
  }

  printf("Global minimum: %d\n", mypq.top());

  mypq.pop();
  printf("Second smallest: %d\n", mypq.top());

  mypq.pop();
  printf("Third smallest: %d\n", mypq.top());

  return 0;
}
```
This example uses most of the basic functions of `priority_queue`.

**Summary**

Priority queues are good for keeping a global minimum/maximum. It can be created in `O(n)` time and the sorted element can be removed in `O(log n)`. It can be used for any applications which require a heap or a queue, or when an actual priority queue is needed. In the real world, it is used for things like CPU Scheduling and graph algorithms such as Dijkstra and Prim's Spanning Tree.

**Extra Reading**

- [cplusplus.com Reference](http://www.cplusplus.com/reference/queue/priority_queue/)
- [GfG Priority Queue Introduction](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)
- [GfG Applications of Priority Queue](https://www.geeksforgeeks.org/applications-priority-queue/)
