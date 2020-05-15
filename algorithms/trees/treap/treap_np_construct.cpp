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
		remove(cur->c[1-dir]); 	// FIX: remove takes a pointer, not a dir
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

int main()
{
	while (true)
	{
		char c = '\n'; while (c < 'a' || c > 'z') scanf("%c", &c);
		if (c == 'x') break;
		int d; scanf("%d", &d);
		if (c == 'i')
		{
			if (!root) root = new Node(d);
			else insert(root, d);
		}
		if (c == 'r')
		{
			if (!root) continue;
			else remove(locate(root, d));
		}
		if (c == 'q')
		{
			printf("%d\n", (bool)locate(root, d));
		}
		if (c == 'n')
		{
			Node *it = locate(root, d);
			if (it) it = it->n[1];
			if (it) printf("%d\n", it->d);
			else printf("0\n");
		}
		if (c == 'p')
		{
			Node *it = locate(root, d);
			if (it) it = it->n[0];
			if (it) printf("%d\n", it->d);
			else printf("0\n");
		}
	}
}

