// 10 may 2020
// This is my "gold standard" basic treap

#include <iostream>

struct Node
{
	int d, w;
	Node *c[2] = {};
	Node *next = nullptr, *prev = nullptr;
	Node(int d): d(d), w(rand() % 10000) {}
} *root = nullptr;

void rotate(Node *&cur, bool dir) // dir = which side should be new top?
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *& insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;

	Node *& stp = cur->c[cur->d < d];
	Node *& ins = insert(stp, d);
	if (stp->w > cur->w)
		rotate(cur, cur->d < d);
	return ins;
}

Node *& locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

void remove(Node *&cur)
{
	if (!cur) return; // FIX: add nullptr test
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]); // FIX: remove the other side, since we rotated not swapped
	}
	else
	{
		Node *tmp = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete tmp;
	}
}

// note: this was cheat-copied in
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
	printf("%d %s(%4d @ %x)%s\n", cur->d, BLACK, cur->w, cur, RESET);
	dump(cur->c[0], lay+1);
}

int main()
{
	srand(20);
	while (true)
	{
		char c=0;
		while (c < 'a' || c > 'z') scanf("%c", &c);
		if (c == 'x') break;

		int d; scanf("%d", &d);
		if (c == 'i')
		{
			if (root) insert(root, d);
			else root = new Node(d);
		}
		else if (c == 'r')
		{
			if (root) remove(locate(root, d));
		}
		else if (c == 'q')
		{
			printf("%d\n", (bool) locate(root, d));
		}
		dump(root);
	}
}

