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
int N, M;
struct Node
{
	int d, w, n=1, s=1;
	Node *c[2] = {};
	Node(int d): d(d), w(rand()) {};
} *root = nullptr;

void setSize(Node *cur)
{
	cur->s = cur->n;
	if (cur->c[0]) cur->s += cur->c[0];
	if (cur->c[1]) cur->s += cur->c[1];
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
	return ins;
}
void remove(Node *&cur, int d)
{
	if (!cur) return;
	if (cur->d == d)
	{
		if (--cur->n > 0) return;
		if (cur->c[0] && cur->c[1])
		{
			bool dir = cur->c[0]->w < cur->c[1]->w;
			rotate(cur, dir);
			remove(cur->c[!dir]);
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

Node *bound(Node *cur, int d, bool dir)	// dir: 1 = above, 0 = lower
{
	if (!cur || cur->d == d) return cur;
	Node *got = bound(cur->d < d, d, dir);
	if (got) return got;
	return cur->d < d == dir ? nullptr : cur;
}

int main()
{

	return 0;
}

