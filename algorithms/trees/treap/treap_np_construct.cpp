// 15 May 2020

#include <iostream>

using namespace std;

struct Node
{
	int d, w;
	Node *c[2] = {}, *n[2] = {};
	Node(int d): d(d), w(rand()) {}
} *root = nullptr;

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *&insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;
	const bool dir = cur->d < d;
	Node *&stp = cur->c[dir];
	Node *&ins = insert(stp, d);
	if (stp == ins && !ins->n[1-dir])
	{
		ins->n[dir] = cur->n[dir];
		ins->n[1-dir] = cur;
		cur->n[dir] = ins;
		if (ins->n[dir])
			ins->n[dir]->n[1-dir] = ins;
	}
	if (cur->w < stp->w)
		rotate(cur, dir);
	return ins;
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

void remove(Node *&cur)
{
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur, 1-dir);
	}
	else
	{
		Node *thn = cur;
		if (cur->n[0]) cur->n[0]->n[1] = cur->n[1];
		if (cur->n[1]) cur->n[1]->n[0] = cur->n[0];
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
	}
}

