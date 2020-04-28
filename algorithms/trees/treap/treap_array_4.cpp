// treap array rewrite, hopefully clean (27 Apr 2020)
// does not reuse memory after deletion... use an alloc pq for that

#include <algorithm>	// swap
#include <iostream>		// io
#include <cassert> 		// assert

const int MX = 100111;

int value[MX], weight[MX], child[MX][2], root=0, alloc=1;

 
inline bool cmp(int l, int r) { return l < r; }
inline int& step(int cur, int val) { return child[cur][cmp(value[cur], val)]; }

int rot(int &cur, bool dir)
{
//	        R	           R	
//	        |	           |	
//	       cur	  left    thn	
//	      /   \   <---   /   \
//	    thn    C        A	  cur	
//	   /   \	  --->      /   \
//	  A     B	  right    B     C
//
	assert(child[cur][dir]);						// don't rotate an empty node into the tree
	// TODO: how to update pointer from parent?   
	int thn = child[cur][dir];						// then, aka new 'cur'
	child[cur][dir] = child[thn][1-dir];			// update pointer to center child
	child[thn][dir] = cur;							// update pointer to cur
	std::swap(cur, thn);							// update references, since other code expects to be in same position on the tree
	return thn;										// return new 'cur'
}

int parent(int val, int cur=root)
{
	const int stp = step(cur, val);					// get next step
	if (stp && value[stp] != val)					// if next step exists and isn't the target
		return parent(val, stp);					// go there
	return cur;										// else, this is the "would be parent"
}

int insert(int val, int &cur=root)
{	// recursively insert a node, then heapify up on the way back
	if (value[cur] == val)							// if already exists
		return cur;									// return
	const int dir = cmp(value[cur], val);			// direction to branch at this node
	if (step(cur, val))								// if that direction isn't a leaf
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

int has(int val) { return step(parent(val), val); }	// return whether child exists on wouldbe parent

void erase(int val)
{
	int big, pre = parent(val);						// get would be parent
	int &cur = step(pre, val);						// and child if it exists
	if (!cur) return;								// if child doesn't exist, we're done!
	while (child[cur][0] && child[cur][1])			// both children exist
	{
		big = weight[child[cur][0]]					// which side has larger weight?
			< weight[child[cur][1]];
		pre = cur;									// remember parent of final cur
		cur = rot(pre, 1-big);						// rotate away from bigger (so bigger ends on top), reassign cur to its new loc
	}
	child[pre][big]= child[cur][0] | child[cur][1];	// only one child, just bitwise-or to get its pos
	// delete the node
	value[cur] = 0;
	weight[cur] = 0;
	child[cur][0] = child[cur][1] = 0;
}

void dump(int cur=root, int lay=1)
{
	if (!cur) return;
	for (int i=0; i<lay; ++i) printf("|   "); printf("(%d | %d) at %d\n", value[cur], weight[cur], cur);
	dump(child[cur][0], lay+1);
	dump(child[cur][1], lay+1);
}

int main()
{
	srand(0);
	char c;
	int d;
	while (true)
	{
		c = '\n';
		while (c == '\n' || c == ' ')
			scanf("%c", &c);
		if (c == 'i')
		{
			scanf("%d", &d);
			insert(d);
		}
		else if (c == 'd')
		{
			scanf("%d", &d);
			erase(d);
		}
		else if (c == 'q')
		{
			scanf("%d", &d);
			printf("found %d at %d\n", d, has(d));
		}
		else if (c == 'x')
		{
			dump();
		}
		else
			printf("i: insert, d: delete, q: query, x: dump\n");
	}
}
