// 19 May 2020 15:07-15:12 (5 min)

#include <iostream>

struct Node
{
	int d, w, s=1;
	Node *c[2]={}, *n[2]={};
	Node(int d): d(d), w(rand()%1000) {}
}

void getSize(Node *cur)
{
	cur->s = 1;
	if (cur->c[0]) cur->s += cur->c[0]->s;
	if (cur->c[1]) cur->s += cur->c[1]->s;
}

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

void remove(Node *cur)
{
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]);
	}
	else
	{
		Node *thn = cur;
		if (thn->n[0]) thn->n[0]->n[1] = thn->n[1];
		if (thn->n[1]) thn->n[1]->n[0] = thn->n[0];
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
	}
}

