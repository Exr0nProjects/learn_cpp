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
	if (!cur || --cur->n) return; // TODO: need --cur->c > 0 ? shouldn't be negative ever
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
			printf("%d", loc ? loc->n : 0);
		}
		printf("\n");
	}
}

