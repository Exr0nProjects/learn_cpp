/*
TASK: 1_balanced_tree
LANG: C++14
*/

/*
 * Problem 1_balanced_tree (contests/algo/treap/1_balanced_tree)
 * Create time: Wed 20 May 2020 @ 14:27 (PDT)
 * Accept time: Thu 21 May 2020 @ 10:11 (PDT)
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
	Node *&stp = cur->c[cur->d < d];
	Node *ins = insert(stp, d);
	if (cur->w < stp->w)
		rotate(cur, cur->d < d);
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
			auto it = getNeighbor(root, d-1, 0);
			printf("%d\n", it ? it->d : -1);
		}
		if (c == '6')
		{
			auto it = getNeighbor(root, d+1, 1);
			printf("%d\n", it ? it->d : -1);
		}
	}
    return 0;
}

