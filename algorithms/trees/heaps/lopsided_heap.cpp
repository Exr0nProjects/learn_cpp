// lopsided heap, Exr0n 27 April 2020
// the goal: a normal binary heap but the left child of each node is smaller than the right child if both exist.
// why? easy heapify down
// done as dop arrays simulating pointers for use in treap
// TODO: too much work to write with pointers rn, should come back to it later.

#include <iostream>

const int MX = 1000111; 	// max 1m nodes
struct Node
{
	int v, p;		// value, parent
	Node *c[2];		// children
} *root;

int heapify_up(Node *cur)
{
	if (cur->c[0]->v > cur->c[1]->v)
		swap(cur->c[0], cur->c[1]);
	if (cur == root) return;
	if (cur->v > cur->p->v)
	{
		swap(cur, cur->p);

int value[MX], parent[MX], heap[MX], root=0, alloc=1;

int heapify_up(int cur)
{
	if (value[child[cur][0]] > value[child[cur][1]])
		swap(child[cur][0], child[cur][1]);
	if (!parent[cur]) return;				// already at top
	if (value[parent[cur]] < value[cur])
	{
		swap(value[cur/2], value[cur]);
		heapify_up(cur/2);
	}
}

