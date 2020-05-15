// 15 May 2020
// og code written in 6 min

#include <iostream>
using namespace std;

struct Node
{
	int d, w;
	Node *c[2] = {};
	Node(int d): d(d), w(rand()%10000) {}
} *root = nullptr; // FIX: init to null

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;	// FIX: nullptr check comes before data access
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *&insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;
	Node *&stp = cur->c[cur->d < d];
	Node *&ins = insert(stp, d);
	if (cur->w < stp->w)
		rotate(cur, cur->d < d);
	return ins;
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}
	
void remove(Node *&cur)
{
	if (!cur) return;		// FIX: check null ptr
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]);
	}
	else
	{
		Node *thn = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
	}
}

