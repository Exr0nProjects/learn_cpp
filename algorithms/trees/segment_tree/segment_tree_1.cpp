// segtree recode 23 May 2020

#include <algorithm>
#include <iostream>
#include <numeric>

const int MX = 100111;
using namespace std;
struct Node
{
	int v=1<<20, add=0, c[2]={};	// FIX: init v=max
} segtree[MX];
int N, D;

void build()
{
	scanf("%d", &N);
	D = log2(N) +1;
	for (int i=0; i<N; ++i)
	{
		int d;
		scanf("%d", &d);
		segtree[(1<<D) + i].v = d;
	}
	for (int i=(1<<D)-1; i>0; --i) // FIX: --i
		segtree[i].v = min(segtree[2*i].v, segtree[2*i+1].v);
}

int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D, int acc=0)	// inc l inc r
{
	printf("query %d..%d\n", tl, tr);
	if (qr < tl || tr < ql) return 1<<30;
	acc += segtree[k].add;	// FIX: add current [k].add before returning
	if (ql <= tl && tr <= qr) return segtree[k].v + acc;
	int mid = tl + (tr - tl)/2; 
	return min(
			query(ql, qr, 2*k, tl, mid, acc),
			query(ql, qr, 2*k+1, mid, tr, acc)
		);
}

int update(int ql, int qr, int delta, int k=1, int tl=1, int tr=1<<D)
{
	if (qr < tl || tr < ql) return 1<<30;
	if (ql <= tl && tr <= qr)
	{
		segtree[k].add += delta;
		return segtree[k].v + segtree[k].add;
	}
	int mid = tl + (tr - tl)/2;
	segtree[k].v = min(
			update(ql, qr, delta, 2*k, tl, mid),
			update(ql, qr, delta, 2*k+1, mid, tr)
		);
	return segtree[k].v + segtree[k].add;
}


void dump()
{
	for (int i=1; i<1<<(D+1); ++i)
	{
		if (__builtin_popcount(i)==1) printf("\n");
		printf("%3d ", segtree[i].v);
	}
	printf("\n");
}

int main()
{
	build();
	while (true)
	{
		char c=' '; while (c<'a' || c>'z') scanf("%c", &c);
		int l, r; scanf("%d%d", &l, &r);
		if (c == 'q') printf("%d\n", query(l, r));
		if (c == 'u')
		{
			int v; scanf("%d", &v);
			update(l, r, v);
		}
		printf("----\n");
		dump();
	}
}

