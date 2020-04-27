// treap array rewrite, hopefully clean (27 Apr 2020)

#include <iostream>	// io
#include <cassert> 	// assert

const int MX = 100111;

int value[MX], weight[MX], child[MX][2], root=0, alloc=1;

inline bool cmp(int l, int r)
{ return l < r; }
inline int step(int cur, int val)
{ return child[cur][cmp(value[cur], val)]; }

//        R	         R	
//        |	         |	
//       cur	        thn	
//      /   \   --->   /   \
//    thn    C	      A	   cur	
//   /   \	          /   \
//  A     B	   	 B     C

int rot(int &cur, bool dir)
{
    assert(child[cur][dir]);
    // TODO: how to update pointer from parent?   
    int thn = child[cur][dir];
    child[cur][dir] = child[thn][1-dir];
    child[thn][dir] = cur;
    cur = thn;
}

int insert(int val, bool bad)
{
    if (root)						// if the tree exists
    {	// TODO: rewrite this block
	int cur=root;
	while ( child[cur][cmp(value[cur], val)] )	// while the next traversal exists
	    cur=child[cur][cmp(value[cur], val)];	// go there
	// construct node
	child[cur][cmp(value[cur], val)] = alloc;	// set the child of the parent
    }
    value[alloc] = val;					// set value of new node
    weight[alloc] = rand()%(1<<30);			// random weight of new node
}

int insert(int val, int cur=root)
{
    if (value[cur] == val)
	return cur;
    const int dir = cmp(value[cur], val);
    if (child[cur][dir])
    {
	int it = insert(val, child[cur][dir]);
	if (weight[cur] < weight[child[cur][dir]])
	    rot(cur, 1-dir);
	return it;
    }
    // insert here
    value[alloc] = val;
    weight[alloc] = rand() % (MX*1000); 		// 0.1% chance of weight collision
    return alloc++;
}


int has(int val)
{
    int cur=root;
    while (cur)
    {
	if (value[cur] == val) return cur;
	cur=child[cur][cmp(value[cur], val)];
    }
    return false;
}

int erase(int val)
{
    int it = has(val);
    if (!it) return;

