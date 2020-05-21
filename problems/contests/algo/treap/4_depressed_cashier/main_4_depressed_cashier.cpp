/*
TASK: 4_depressed_cashier
LANG: C++14
*/

/*
 * Problem 4_depressed_cashier (contests/algo/treap/4_depressed_cashier)
 * Create time: Thu 21 May 2020 @ 12:23 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "4_depressed_cashier");

using namespace std;
const int MX = -1;

int modify = 0;

struct Node
{
	ll d, w, num=1, s=1;
	Node *c[2] = {};
	Node(ll d): d(d), w(rand()) {};
} *root = nullptr;
void dump(Node *cur, int lay=1);

void setSize(Node *cur)
{
	if (!cur) return;
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

Node *insert(Node *&cur, ll d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) { ++cur->num; ++cur->s; return cur; }
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
		if (--cur->num > 0) { --cur->s; return; }
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

Node *getKth(Node *cur, int k)
{
	if (!cur) return nullptr;
	const int leftS = cur->c[1] ? cur->c[1]->s : 0;
	if (k < leftS) return getKth(cur->c[1], k);
	if (k < leftS + cur->num) return cur;
	return getKth(cur->c[0], k - leftS - cur->num);
}

void dump(Node *cur, int lay)
{
	return;
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i) printf("    ");
	printf("%d,%d x%d   s%d\n", cur->d, cur->d + modify, cur->num, cur->s);
	dump(cur->c[0], lay+1);
}

int main()
{
	int Q, MIN, leaving=0;
	scanf("%d%d", &Q, &MIN);
	for (int q=0; q<Q; ++q)
	{
		char c; int d;
		scanf("\n%c%d", &c, &d);
		if (c == 'I')
		{
			if (d >= MIN)
				insert(root, d-modify); // FIX: take into acount previous modifications
			else
				++leaving;
		}
		if (c == 'A') modify += d;
		if (c == 'S')
		{
			modify -= d;
			for (int i=(root ? root->s-1 : 0); i>=0; --i)
			{
				Node *it = getKth(root, i); // TODO: n log n, could be made to be just n w/ inorder traversal
				if (it && it->d + modify < MIN)
				{
					remove(root, it->d);
					++leaving;
				}
				else break;
			}
		}
		if (c == 'F')
		{
			auto loc = getKth(root, d-1);
			printf("%d", loc ? loc->d + modify : -1);
		}
		dump(root);
	}
	printf("%d\n", leaving);

    return 0;
}

