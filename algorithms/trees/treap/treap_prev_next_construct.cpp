// 15 May 2020
// og code written in 6 min
/* problems inputs:
i 6 r 6 i 2 i 2 i 5 n 5 => segfault
i 6 i 2 r 6 i 2 i 5 n 5 => wrong answer, should be 0 got 5
*/

#include <iostream>
using namespace std;

struct Node
{
	int d, w;
	Node *c[2] = {};
	Node *n[2] = {};	// neighbors: 0 = prev, 1 = next
	Node(int d): d(d), w(rand()%10000) {}
} *root = nullptr;

// note: this was cheat-copied in
#define RESET "\033[0m"
#define BLACK "\x1b[38;5;239m"
void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
	if (lay == 1) printf("dump:\n");
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i)
		printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
	printf("%d %s(%4d @ %x)%s\n", cur->d, BLACK, cur->w, cur, RESET);
	dump(cur->c[0], lay+1);
}

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
	Node *&stp = cur->c[cur->d < d];
	Node *&ins = insert(stp, d);
	
	const bool dir = cur->d < d;
	if (ins == stp && !ins->n[1-dir])	// FIX: ensure inserted node's prev didn't already point, aka don't double insert into linked list if node already existed
	{
		ins->n[dir] = cur->n[dir];
		cur->n[dir] = ins;
		if (ins->n[dir])	// FIX: don't assign next/prev of nullptr!
			ins->n[dir]->n[1-dir] = ins;
		ins->n[1-dir] = cur;
	}

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
		// FIX: update next/prev on delete
		// FIX: have to check another layer to avoid assigning nullptr segfault
		if (cur->n[0] && cur->n[0]->n[1]) cur->n[0]->n[1] = cur->n[1];
		if (cur->n[1] && cur->n[1]->n[0]) cur->n[1]->n[0] = cur->n[0];
		// FIX: don't assign cur until we're done w/ it!
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
		dump(root);
	}
}

