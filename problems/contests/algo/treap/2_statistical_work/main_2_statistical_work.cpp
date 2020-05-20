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
	int d, w, count=1;
	Node *c[2]={}, *n[2]={};
	Node(int d): d(d), w(rand()) {}
} *num_root = nullptr,
	*gap_root = nullptr, *pre_min_gap = nullptr,
	*sgap_root = nullptr, *pre_sort_gap = nullptr;
void tdump(Node *&cur, int lay=1);
void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}
Node *tinsert(Node *&cur, int d)
{
	printf("inserting %d at %x\n", d, cur);
	if (!cur) return cur = new Node(d);
	if (cur->d == d)
	{
		++cur->count;
		return cur;
	}
	const bool dir = cur->d < d;
	Node *&stp = cur->c[dir];
	Node *ins = tinsert(stp, d);
	if (stp == ins && !ins->n[1-dir])
	{
		ins->n[dir] = cur->n[dir];
		ins->n[1-dir] = cur;
		cur->n[dir] = ins;
		if (ins->n[dir])
			ins->n[dir]->n[1-dir] = cur;
		printf("inserted\n");
	}
	tdump(cur);
	printf("uh ins %x\n", ins);
	if (cur->w < stp->w)
		rotate(cur, dir);
	printf("uh NOWWWWW ins %x\n", ins);
	tdump(cur);
	return ins;
}
Node *&tlocate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return tlocate(cur->c[cur->d < d], d);
}
void tremove(Node *cur)
{
	if (!cur || --cur->count) return;
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
void tdump(Node *&cur, int lay)
{
	if (!cur) return;
	tdump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i) printf("    ");
	printf("%3d x%d\n", cur->d, cur->count);
	tdump(cur->c[0], lay+1);
}

void insert(int p, int d, bool init=0)
{
	if (!init && p+1 < N)
	{
		tremove(gap_root, abs(tail[p] - head[p+1]));
		tinsert(gap_root, abs(head[p+1] - d));
	}
	tinsert(gap_root, abs(tail[p] - d));
	tail[p] = d;

	printf("inserting num %d\n", d);
	Node *ins = tinsert(num_root, d);

	printf("done: ins %x       ins->n[0] %x, ins->n[1] %x\n", ins, ins->n[0], ins->n[1]);

	if (ins->n[0] && ins->n[1]) tremove(sgap_root, abs(ins->n[0]->d-ins->n[1]->d));
	if (ins->n[0]) tinsert(sgap_root, abs(ins->n[0]->d -d));
	if (ins->n[1]) tinsert(sgap_root, abs(ins->n[1]->d -d));

		printf("nums:\n"); tdump(num_root); printf("\n");
		printf("gaps:\n"); tdump(gap_root); printf("\n");
		printf("sgaps:\n"); tdump(sgap_root); printf("\n");

	if (pre_sort_gap->n[1] && pre_min_gap->n[1])
		printf("after insert: min_sort_gap = %3d, min_gap = %3d\n", pre_sort_gap->n[1]->d, pre_min_gap->n[1]->d);
}

int main()
{
	srand(100);
	scanf("%d%d", &N, &M);
	pre_min_gap = tinsert(gap_root, -1);
	pre_sort_gap = tinsert(sgap_root, -1);
		printf("nums:\n"); tdump(num_root); printf("\n");
		printf("gaps:\n"); tdump(gap_root); printf("\n");
		printf("sgaps:\n"); tdump(sgap_root); printf("\n");
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &head[i]);
		tail[i+1] = head[i]; // FIX: overlap list thingy to make insert gap calculation work
		insert(i, head[i], true);
		/*
		tail[i] = head[i];
		if (i)
		{
			printf("inserting gap %d\n", abs(head[i]-head[i-1]));
			tinsert(gap_root, abs(head[i]-head[i-1]));
		}
		tinsert(num_root, head[i]);

		printf("nums:\n"); tdump(num_root); printf("\n");
		printf("gaps:\n"); tdump(gap_root); printf("\n");
		*/
	}
	tremove(gap_root, head[0]); // FIX: fencepost--inserts a ghost gap because it's the first
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
				printf("%d\n", pre_sort_gap->n[1]->d);
			else
				printf("%d\n", pre_min_gap->n[1]->d);
		}
	}

    return 0;
}

