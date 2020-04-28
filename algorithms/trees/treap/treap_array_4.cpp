// treap array rewrite, hopefully clean (27 Apr 2020)
// does not reuse memory after deletion... use an alloc pq for that

#include <iostream>	// io
#include <cassert> 	// assert

const int MX = 100111;

int value[MX], weight[MX], child[MX][2], root=0, alloc=1;

inline bool cmp(int l, int r)
{ return l < r; }
inline int step(int cur, int val)
{ return child[cur][cmp(value[cur], val)]; }

//        R	             R	
//        |	             |	
//       cur	left    thn	
//      /   \   <---   /   \
//    thn    C	      A	   cur	
//   /   \	    --->      /   \
//  A     B	   	right    B     C

int rot(int cur, bool dir)
{
	assert(child[cur][dir]);						// don't rotate an empty node into the tree
	// TODO: how to update pointer from parent?   
	int thn = child[cur][dir];						// then, aka new 'cur'
	child[cur][dir] = child[thn][1-dir];			// update pointer to center child
	child[thn][dir] = cur;							// update pointer to cur
	//cur = thn;									// update references to cur, since other code expects to be in same position on the tree
	return thn;										// return new 'cur'
}

int parent(int val, int cur=root)
{
	int step = child[cur][cmp(value[cur, val])];	// get next step
	if (step && value[step] != val)					// if next step exists and isn't the target
		return parent(val, step);					// go there
	return cur;										// else, this is the "would be parent"
}

int insert(int val, int cur=root)
{	// recursively insert a node, then heapify up on the way back
	if (value[cur] == val)							// if already exists
		return cur;									// return
	const int dir = cmp(value[cur], val);			// direction to branch at this node
	if (child[cur][dir])							// if that direction isn't a leaf
	{	// TODO: write with parent, maybe?
		int it = insert(val, child[cur][dir]);		// recursively insert
		if (weight[cur] < weight[child[cur][dir]])	// if heap property broken
			rot(cur, 1-dir);						// fix it by rotating branch with new node to top
		return it;									// return insertion position
	}
	// insert here
	value[alloc] = val;								// set value
	weight[alloc] = rand() % (MX*1000); 			// 0.1% chance of weight collision
	return alloc++;									// return insertion position, increase size counter
}


int has(int val)
{
	int cur = parent(val);							// find would be parent of val node
	return child[cur][cmp(value[cur], val)];		// return whether correct child exists
}

int erase(int val)
{
	int pre, cur = has(val);						// find the node
	if (!cur) return;								// if it doesn't exist, then we're done!
	while (child[cur][0] && child[cur][1])			// both children exist
	{
		int l = weight[child[cur][0]];				// get weight of left
		int r = weight[child[cur][1]];				// get weight of right
		rot(cur, l > r);							// rotate away from bigger (so bigger ends on top)
	}
	child[
	// delete the node
	child[cur][0] = child[cur
	value[cur] = 0;
	weight[cur] = 0;

