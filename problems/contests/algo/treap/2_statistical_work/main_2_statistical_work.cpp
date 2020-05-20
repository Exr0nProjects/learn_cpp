/*
TASK: 2_statistical_work
LANG: C++14
*/

/*
 * Problem 2_statistical_work (contests/algo/treap/2_statistical_work)
 * Create time: Tue 19 May 2020 @ 17:09 (PDT)
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

using namespace std;
const int MX = 500111;
int N, M, head[MX], tail[MX], min_gap=1<<30, min_sort_gap=1<<30;

struct Node
{
	int d, w;
	Node *c[2]={}, *n[2]={};
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
Node *&treap_insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;
	const bool dir = cur->d < d;
	Node *&stp = cur->c[dir];
	Node *&ins = treap_insert(stp, dir);
	if (stp == ins && !ins->n[1-dir])
	{
		ins->n[dir] = cur->n[dir];
		ins->n[1-dir] = cur;
		cur->n[dir] = ins;
		if (ins->n[dir])
			ins->n[dir]->n[1-dir] = cur;
		min_sort_gap = min(min_sort_gap, min(
					d - ins->n[0]->d,
					ins->n[1]->d - d));
	}
	if (cur->w < stp->w)
		rotate(cur, dir);
	return ins;
}

void insert(int p, int d)
{
	min_gap = min(min_gap, (int)abs(tail[p]-d));
	tail[p] = d;
	min_gap = min(min_gap, (int)abs(head[p+1]-d));

	treap_insert(root, d);
	printf("after insert: min_sort_gap = %3d, min_gap = %3d\n", min_sort_gap, min_gap);
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &head[i]);
		tail[i] = head[i];
		treap_insert(root, head[i]);
	}
	printf("okay\n");
	for (int m=0; m<M; ++m)
	{
		char buf[20];
		scanf("%s", buf);
		if (buf[0] == 'I')
		{
			int p, d;
			scanf("%d%d", &p, &d);
			insert(p, d);
		}
		else
		{
			if (buf[3] == 'S')
				printf("%d\n", min_sort_gap);
			else
				printf("%d\n", min_gap);
		}
	}

    return 0;
}

