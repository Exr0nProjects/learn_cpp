// lopsided heap, Exr0n 27 April 2020
// the goal: a normal binary heap but the left child of each node is smaller than the right child if both exist.
// why? easy heapify down
// done as dop arrays simulating pointers for use in treap

#include <iostream>

const int MX = 1000111; 	// max 1m nodes
int value[MX], heap[MX], root=0, alloc=1;

int heapify_up(int cur)
{
	if (value[cur*2] > value[cur*2+1])
		swap(
	if (!cur/2) return;				// already at top
	if (value[cur/2] < value[cur])
	{
		swap(value[cur/2], value[cur]);
		heapify_up(cur/2);
	}
}

