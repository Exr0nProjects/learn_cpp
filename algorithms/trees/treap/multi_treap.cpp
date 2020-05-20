// multi treap, 20 May 2020

#include <iostream>

struct Node
{
	int d, w, n=1;
	Node *c[2] = {};
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

Node *insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) { ++cur->n; return cur; }
	Node *&stp = cur->c[cur->d < d];
	Node *ins = insert(stp, d);
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
	if (!cur || --cur->n > 0) return; // FIX: check if greater than 0 because double-decrement on recursion
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

#define RESET "\033[0m"
#define BLACK "\x1b[38;5;239m"
void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
	return;
	if (lay == 1) printf("dump:\n");
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i)
		printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
	printf("%d x%d %s(%4d @ %x)%s\n", cur->d, cur->n, BLACK, cur->w, cur, RESET);
	dump(cur->c[0], lay+1);
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
			insert(root, d);
		}
		if (c == 'r')
		{
			remove(locate(root, d));
		}
		if (c == 'q')
		{
			Node *loc = locate(root, d);
			printf("%d\n", loc ? loc->n : 0);
		}
		dump(root);
	}
}

