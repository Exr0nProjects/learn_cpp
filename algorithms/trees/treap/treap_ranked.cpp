// ranked multitreap 20 may 2020
// supports get_kth_smallest

#include <iostream>

struct Node
{
	int d, w, n=1, s=1;
	Node *c[2]={};
	Node(int d): d(d), w(rand()%1000) {};
} *root = nullptr;
void setSize(Node *cur)
{
	cur->s = cur->n;
	if (cur->c[0]) cur->s += cur->c[0]->s;
	if (cur->c[1]) cur->s += cur->c[1]->s;
}
void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	setSize(cur);
	thn->c[1-dir] = cur;
	setSize(thn);
	cur = thn;
}

Node *insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) { ++cur->n; ++cur->s; return cur; }
	Node *&stp = cur->c[cur->d < d];
	Node *ins = insert(stp, d);
	if (cur->w < stp->w)
		rotate(cur, cur->d < d);
	setSize(cur);
	return ins;
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

Node *&getRank(Node *&cur, int k)
{
	if (!cur || cur->s > k) return cur;

void remove(Node *&cur)
{
	if (!cur || --cur->n > 0) { --cur->s; return; }
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]);
		setSize(cur);
	}
	else
	{
		Node *thn = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
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
			insert(root, d);
		}
		else if (c == 'r')
		{
			remove(locate(root, d));
		}
		else if (c == 'q')
		{
			Node *it = locate(root, d);
			printf("%d\n", it ? it->n : 0);
		}
		else if (c == 'k')
		{
			Node *it = getRank(root, d);
			printf("%d\n", it ? it->d : -1);
		}
		dump(root);
	}
}

