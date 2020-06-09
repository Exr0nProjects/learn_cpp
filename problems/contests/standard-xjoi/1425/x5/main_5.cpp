/*
 * Problem 5 (contests/standard-xjoi/1425/5)
 * Create time: Tue 09 Jun 2020 @ 08:01 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 511;
int N;
struct Node
{
	int d, w, n=1, s=1;
	Node *c[2] = {};
	Node(int d): d(d), w(rand()) {};
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
	if (cur->w < stp->w) rotate(cur, cur->d < d);
	setSize(cur);
	return ins;
}
void remove(Node *&cur, int d)
{
	if (!cur) return;
	if (cur->d == d)
	{
		--cur->s;
		if (--cur->n > 0) return;
		if (cur->c[0] && cur->c[1])
		{
			bool dir = cur->c[0]->w < cur->c[1]->w;
			rotate(cur, dir);
			remove(cur->c[!dir], d);
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

void dump(Node *cur, int lay=1)
{
	return;
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i) printf("    ");
	printf("%d x%d (w %d s %d)\n", cur->d, cur->n, cur->w, cur->s);
	dump(cur->c[0], lay+1);
}

Node *bound(Node *cur, int d, bool dir)	// dir: 1 = above, 0 = lower
{
	if (!cur || cur->d == d) return cur;
	Node *got = bound(cur->c[cur->d < d], d, dir);
	if (got) return got;
	return cur->d < d == dir ? nullptr : cur;
}

int main()
{
	int N; scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		int c, d; scanf("%d%d", &c, &d);
		if (c == 1) insert(root, d);
		if (c == 2) remove(root, d);
		if (c == 5) printf("%d\n", bound(root, d-1, 0)->d);
		if (c == 6) printf("%d\n", bound(root, d+1, 1)->d);
		//dump(root); printf("\n\n");
	}

	return 0;
}

