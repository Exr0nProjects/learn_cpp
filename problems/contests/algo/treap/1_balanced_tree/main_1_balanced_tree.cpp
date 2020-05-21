/*
TASK: 1_balanced_tree
LANG: C++14
*/

/*
 * Problem 1_balanced_tree (contests/algo/treap/1_balanced_tree)
 * Create time: Wed 20 May 2020 @ 14:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>

using namespace std;
const int MX = -1;

struct Node
{
	int d, w;
	Node *c[2] = {};
	int num=1, s=1;
	Node *n[2] = {};
	Node(int d): d(d), w(rand() % 100000) {}
} *root = nullptr;

void setSize(Node *cur)
{
	cur->s = cur->num;
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
	if (cur->d == d) { ++cur->s; ++cur->num; return cur; }
	const bool dir = cur->d < d;
	Node *&stp = cur->c[dir];
	Node *ins = insert(stp, d);
	if (ins == stp && !ins->n[1-dir])
	{
		ins->n[dir] = cur->n[dir];
		ins->n[1-dir] = cur;
		cur->n[dir] = ins;
		if (ins->n[dir])
			ins->n[dir]->n[1-dir] = ins;
	}
	if (cur->w < stp->w)
		rotate(cur, dir);
	setSize(cur);
	return ins;
}
void remove(Node *&cur, int d)
{
	if (!cur) return;
	if (cur->d == d)
	{
		if (--cur->num > 0) { --cur->s; return; } // FIX: update cur size
		if (cur->c[0] && cur->c[1])
		{
			const bool dir = cur->c[0]->w < cur->c[1]->w;
			rotate(cur, dir);
			remove(cur->c[1-dir], d);
			setSize(cur);
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
	else
	{
		remove(cur->c[cur->d < d], d);
		setSize(cur);
	}
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

Node *lowerBound(Node *cur, int d)
{
	if (!cur || cur->d == d) return cur;
	const bool dir = cur->d < d;
	Node *loc = lowerBound(cur->c[dir], d);
	if (loc) return loc;
	return dir ? cur : nullptr;
}

Node *upperBound(Node *cur, int d)
{
	if (!cur || cur->d == d) return cur;
	const bool dir = cur->d < d;
	Node *loc = upperBound(cur->c[dir], d);
	if (loc) return loc;
	return dir ? nullptr : cur;
}

Node *getNeighbor(Node *cur, int d, bool dir)	// nullptr means no suitable neighbor in that subtree
{
	if (!cur || cur->d == d) return cur;
	const bool stpd = cur->d < d;
	Node *loc = getNeighbor(cur->c[stpd], d, dir);
	if (loc) return loc;
	return stpd == dir ? nullptr : cur;
}

Node *getKth(Node *cur, int k)
{
	if (!cur || k < 0 || k > cur->s) return nullptr;
	const int leftSize = cur->c[0] ? cur->c[0]->s : 0;
	if (k < leftSize) return getKth(cur->c[0], k);
	if (k < leftSize + cur->num) return cur;
	return getKth(cur->c[1], k - leftSize - cur->num);
}

int getRank(Node *cur, int d)
{
	if (!cur) return 0;
	const int leftS = cur->c[0] ? cur->c[0]->s : 0;
	if (cur->d == d) return leftS;
	if (cur->d > d) return getRank(cur->c[0], d);
	return getRank(cur->c[1], d) + cur->num + leftS;
}

void dump(Node *cur, int lay=1)
{
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0;i <lay; ++i) printf("    ");
	printf("%d x%d (%d @ %x s %d, p:%x n:%x)\n", cur->d, cur->num, cur->w, cur, cur->s, cur->n[0], cur->n[1]);
	dump(cur->c[0], lay+1);
}

int main()
{
	int Q;
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i)
	{
		char c = ' '; while ((c < 'a' || c > 'z') && (c < '0' || c > '9')) scanf("%c", &c);
		int d; scanf("%d", &d);
		if (c == '1') insert(root, d);
		if (c == '2') remove(root, d);
		if (c == '3')
			if (locate(root, d))
				printf("%d\n", getRank(root, d)+1);
		if (c == '4')
		{
			auto it = getKth(root, d-1);
			printf("%d\n", it ? it->d : -1);
		}
		if (c == '5')
		{
			auto it = getNeighbor(root, d, 0);
			printf("%d\n", it ? it->d : -1);
		}
		if (c == '6')
		{
			auto it = getNeighbor(root, d, 1);
			printf("%d\n", it ? it->d : -1);
		}
		dump(root);
	}
    return 0;
}

