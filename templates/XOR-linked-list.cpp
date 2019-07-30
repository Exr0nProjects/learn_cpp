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
