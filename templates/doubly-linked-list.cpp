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
{ // todo: pushAfter() and pushBefore() don't work for some reason, looks like they just straight dont do anything.
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
