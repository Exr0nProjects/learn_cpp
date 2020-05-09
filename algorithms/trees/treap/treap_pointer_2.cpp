// 9 May 2020

#include <iostream>
#include <cassert> // assert
#include <cstdlib> // random

struct Node
{
	int data;
	int w;
	Node* c[2];
} *root = nullptr;

void rotate(Node *& cur, bool dir) // dir = which child should be new parent?
{
	if (!cur) return;
	assert(cur->c[dir]);
	Node* thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[dir] = cur;
	cur = thn;
}

void insert(Node *&cur, int data)
{
	const bool dir = cur->data < data;
	Node*& stp = cur->c[dir];
	if (stp) insert(stp, data);
	else
	{
		stp = new Node();
		stp->w = rand();
		stp->data = data;
	}
	if (stp->w > cur->w)
		rotate(cur, dir);
}

void remove(Node *&cur)
{
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[dir]);
	}
	else
	{
		Node *tmp = cur;
		cur = cur->c[0] | cur->c[1];	 // TODO: legal? one or both are nullptr
		delete tmp;
	}
}

void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i)
		printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
	dump(cur->c[0], lay+1);
}
