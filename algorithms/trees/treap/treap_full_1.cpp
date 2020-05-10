// 10 May 2020

#include <iostream>

struct Node
{
	int d, w, size;
	Node* c[2] = {};
	Node* next=nullptr, prev=nullptr;
	Node(int d): d(d), w(rand() % 10000), size(1) {}
} *root;

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *& insert(Node *&cur, int data)
{
	if (!cur) return cur = new Node(data);
	if (cur->d == data) return cur;
	
	Node *&stp = cur->c[cur->d < data];
	Node *&ins = insert(stp, data);
	if (cur->w < stp->w)
		rotate(cur, cur->d < data);
	return ins;
}

Node *& locate(Node *&cur, int data)
{
	if (!cur || cur == data) return cur;
	return locate(cur->c[cur->d < data], data);
}

void erase(Node *&cur)
{
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		erase(cur->c[1-dir]);
	}
	else
	{
		Node *thn = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
	}
}

