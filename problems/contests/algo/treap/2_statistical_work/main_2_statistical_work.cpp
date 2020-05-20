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
int N, M, head[MX], tail[MX], min_sort_gap=1<<30;

struct Node
{
	int d, w;
	Node *c[2]={}, *n[2]={};
	Node(int d): d(d), w(rand()) {}
} *num_root = nullptr, *gap_root = nullptr, *pre_min_gap = nullptr;
void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}
Node *&tinsert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;
	const bool dir = cur->d < d;
	Node *&stp = cur->c[dir];
	Node *&ins = tinsert(stp, dir);
	if (stp == ins && !ins->n[1-dir])
	{
		ins->n[dir] = cur->n[dir];
		ins->n[1-dir] = cur;
		cur->n[dir] = ins;
		if (ins->n[dir])
			ins->n[dir]->n[1-dir] = cur;
	}
	if (cur->w < stp->w)
		rotate(cur, dir);
	return ins;
}
Node *&tlocate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return tlocate(cur->c[cur->d < d], d);
}
void tremove(Node *cur)
{
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		tremove(cur->c[1-dir]);
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
void tremove(Node *&root, int d)
{ tremove(tlocate(root, d)); }

void insert(int p, int d)
{
	if (p+1 < N) tremove(gap_root, abs(tail[p] - head[p+1]));
	tinsert(gap_root, abs(tail[p] - d));
	tail[p] = d;
	if (p+1 < N) tinsert(gap_root, abs(head[p+1] - d));

	Node *ins = tinsert(num_root, d);
	min_sort_gap = min(min_sort_gap, min(d - ins->n[0]->d, ins->n[1]->d - d));
	printf("after insert: min_sort_gap = %3d, min_gap = %3d\n", min_sort_gap, pre_min_gap->n[1]->d);
}

int main()
{
	scanf("%d%d", &N, &M);
	pre_min_gap = tinsert(gap_root, -1);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &head[i]);
		tail[i] = head[i];
		if (i) tinsert(gap_root, abs(head[i]-head[i-1]));
		tinsert(num_root, head[i]);
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
				printf("%d\n", pre_min_gap->n[1]->d);
		}
	}

    return 0;
}

