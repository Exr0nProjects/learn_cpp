// 14 May 2020

#include <iostream>
#include <numeric>
using namespace std;

const int MX = 100111;
int N, lays, segfault[2*MX], addv[2*MX];

void dump()
{
	for (int i=1; i<2*N; ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("(%3d +%3d)  ", segfault[i], addv[i]);
	} printf("\n");
}

void build()
{
	scanf("%d", &N);
	lays = ceil(log2(N));
	for (int i=0; i<N; ++i)
		scanf("%d", &segfault[i+ (1<<lays)]);
	for (int i=lays; i>0; --i)
		segfault[i] = min(segfault[2*i], segfault[2*i+1]);

	dump();
}

int query(int lq, int rq, int idx=1, int lb=0, int rb=1<<lays, int acc=0)
{
	if (rq < lb || lq > rb)
		return 1<<30;

	acc += addv[idx];
	if (lq <= lb && rq >= rb)
		return segfault[idx] + acc;

	const int lc = 2*idx;
	const int rc = 2*idx +1;
	const int mid = lb + (rb-lb)/2; // (lb+rb)/2 w/o overflow
	return min(
			query(lq, rq, lc, lb, mid),
			query(lq, rq, rc, mid+1, rb));
}

int update(int lq, int rq, int val, int idx=1, int lb=0, int rb=1<<lays)
{
	if (rq < lb || rb < lq) return segfault[idx];
	if (lq <= lb && rb <= rq)
	{
		addv[idx] += val; // FIX: add to addv not minv
		return segfault[idx];
	}

	const int lc = 2*idx;
	const int rc = lc+1;
	const int mid = lb + (rb-lb)/2;
	segfault[idx] = min(
			update(lq, rq, val, lc, lb, mid),
			update(lq, rq, val, rc, mid+1, rb));
	return segfault[idx];
}

int main()
{
	build();
	int Q;
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i)
	{
		char c='\n';
		while (c < 'a' || c > 'z') scanf("%c", &c);
		
		if (c == 'p') { dump(); continue; }
		
		int l, r;
		scanf("%d%d", &l, &r);

		if (c == 'q')
		{
			printf("%d\n", query(l, r));
		}
		else if (c == 'u')
		{
			int v;
			scanf("%d", &v);
			update(l, r, v);
		}
	}
}
			
