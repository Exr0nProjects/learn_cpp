# Summary for Day 20 (30 July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
  dev.xjoi 1211 | 1 | Print directory structure | AC | Used map and iterators and a full on class
"" | 3 | Find shortest max distance | WIP | ShenBear says to use a MST and then LCA, but I need to look into those

**Problem review from the test today:**

problem 2:  
Greedy algorithm, somehow order something?

problem 3:  
make MST with kirskal, doubling method?


## Concepts:
### Doubly Linked List
**Overview**  
A doubly linked list is a linked list that is connected in both directions. Instead of only storing a `next` pointer, it also stores a `previous` pointer. This makes the delete operation much faster if only given a pointer to the node to delete because we can directly access the nodes on either side, unlike with a singly linked list where we need some reference to the previous node. This is the primary advantage that the doubly linked list has over its normal variant.  
However, the doubly linked list uses 1.5 times the memory of a singly linked list because it stores an additional `previous` pointer. There are ways to implement a doubly linked list with a single pointer per node through an XOR linked list, but traversal requires the memory addresses of one of the nodes to calculate the address of the other.

**Example**  
Here is an example implementation of a `Node` struct to be used in a doubly linked list:
```c plus plus
#include <iostream>

using namespace std;

template <class Data>
class Dll
{
public:
  struct Node // todo: should this be static? does that make the defined vars also static?
  {
    Node* prev=nullptr;
    Node* next=nullptr;
    Data data;
  };
private:
  const static int cf_maximum_size = 10;
  
  unsigned long long t_size = 0;
  
  Node nodes[cf_maximum_size], *beg=nullptr, *end=nullptr;
public:
  Dll () {};
  
  void pushFront (const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    (this->nodes)[t_size].prev = nullptr;
    if (beg == nullptr)
    {
      end = &((this->nodes)[t_size]); // first node, set the end pointer also
      (this->nodes)[t_size].next = nullptr;
    }
    else
    {
      beg->prev = &((this->nodes)[t_size]);
      (this->nodes)[t_size].next = beg;
    }
    beg = &((this->nodes)[t_size]);
    ++t_size;
  };
  void pushBack (const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    (this->nodes)[t_size].next = nullptr;
    if (end == nullptr)
    {
      (this->nodes)[t_size].prev = nullptr;
      beg = &((this->nodes)[t_size]);
    }
    else
    {
      end->next = &((this->nodes)[t_size]);
      (this->nodes)[t_size].prev = end;
    }
    end = &((this->nodes)[t_size]);
    ++t_size;
  };
  void pushBefore (Node* _n, const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    
    (this->nodes)[t_size].prev = _n->prev;
    _n->prev->next = &((this->nodes)[t_size]);
    
    (this->nodes)[t_size].next = _n;
    _n->prev = &((this->nodes)[t_size]);
    
    ++t_size;
  };
  void pushAfter (Node* _n, const Data _d)
  {
    this->nodes[t_size].data = _d;
    
    (this->nodes)[t_size].next = _n->next;
    _n->next->prev = &((this->nodes)[t_size]);
    
    (this->nodes)[t_size].prev = _n;
    _n->prev = &((this->nodes)[t_size]);
    
    ++t_size;
  };
  
  unsigned long long size () { return this->size; }
  Node* next (Node* cur) { return cur->next; }
  Node* prev (Node* cur) { return this->prev; }
  Node* front () { return this->beg; }
  Node* back ()  { return this->end; }
  void print () {
    for (Node* pt = this->beg; pt != nullptr; pt = pt->next)
      cout << pt->data << " ";
    printf("\n");
  }
};

int main ()
{
  Dll<int> mylist;
  
  mylist.pushFront(2);
  mylist.print();
  
  mylist.pushBack(5);
  mylist.print();
  
  mylist.pushAfter(mylist.front(), 3);
  mylist.print();
  
  mylist.pushBefore(mylist.back(), 4);
  mylist.print();
  
  mylist.pushFront(1);
  mylist.print();
  
  return 0;
}

```
Unfortunately, I was not able to debug `Dll<>::pushBefore()` or `Dll<>::pushAfter()`. However, the `pushFront()` and `pushBack()` functions still work.

**Complexity**  
- Insert `O(1)` given a pointer to the node by which to insert  
- Delete `O(1)` given a pointer of the node to delete
- Read `O(1)` given a pointer to the node with the value
- Read `O(n)` given an index `n` to read


### XOR Linked List
**Overview**  
XOR linked list is a version of a doubly linked list that uses a single value to store the memory addresses of both the next and previous nodes. As the name suggests, it takes the XOR of the previous and next memory addresses so that each address can be recovered by XORing the combined address with the address of the previous node.  
This means that two addresses are required at all stages to continue traversing the list, which is one of the primary disadvantages that the XOR linked list has over the normal doubly linked list. Otherwise, the XOR linked list is generally somewhat slower than the doubly linked list because it includes additional relatively cheap but still required XOR operations for each insert, delete, and traverse operation. However, the time complexities are still the same.

**Example**
Because I don't have the time to provide a fully working example, I will provide a mock up implementation which is most likely highly buggy:
```c plus plus
class Xll
{
  #include <iostream>

  using namespace std;

  const int MAXSZ = 10;

  template<class Data>
  class XLL
  {
  public:
    struct Node
    {
      unsigned long long mem;
      Data dat;
    };
  private:
    const static int maximum_size = MAXSZ;
    Node c_nodes[maximum_size];
    unsigned long long c_len = 0, c_beg = 0, c_end = 0;
  public:
    XLL () {};
    
    void pushFront (Data _d);
    void pushBack (Data _d);
    void pushBefore (unsigned long long position, Data value);
    void pushAfter (unsigned long long position, Data value);
  };

  template<class Data> void XLL<Data>::pushFront (Data _d)
  {
    if (c_beg == c_end) // if empty
      c_nodes[c_len].mem = NULL; // set memory to null, because there is nothing to link to
    else
    {
      c_nodes[c_beg].mem ^= c_len; // xor previous first node memory value with this one to create the xor linked list property in the other node
      c_nodes[c_len].mem  = c_beg; // set memory to the next thing, because there is no other side to XOR with
    }
    c_nodes[c_len].dat  = _d; // set the data of the current node
    c_beg = c_len; // update the storage of the begining
    ++ c_len; // update the length, which is also the index in the array where the next node will be added
  }

  template<class Data> void XLL<Data>::pushBack (Data _d)
  {
    if (c_beg == c_end) // if empty
    {
      pushFront(_d); // same thing as push front
      return;
    }
    c_nodes[c_end].mem ^= c_len;
    c_nodes[c_len].mem  = c_end;
    c_nodes[c_len].dat  = _d;
    c_end = c_len;
    ++ c_len;
  }
}
```
Notably, we cannot insert directly into the middle of an XOR linked list unless we are given two adjacent nodes to insert between, because we cannot calculate adjacent memory addreses without atleast two to XOR together. This is a good example of the primary downfall of the XOR linked list structure.

**Summary**  
XOR linked lists allow us to save around 33% of the memory used by a doubly linked list, but it is more computationally intensive and requires the memory addresses of two adjacent nodes to begin traversal at an arbitrary point. Otherwise, they are a good alternative to standard doubly linked lists.

## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 10

Today was pretty productive, but I don't know if I should be spending more of my time researching new concepts or doing competition problems. I should practice debugging and stuff so maybe I should focus more of my time on doing problems instead of just spending all day researching stuff and writting notes.