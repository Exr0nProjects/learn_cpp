// 14 May 2020
// query and update are inc l inc r
// input 1-index vs 0-index depends on default bounds, make sure to get the distance right or it will fail!

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
	for (int i=(1<<lays)-1; i>0; --i) // FIX: i=(1<<lays)-1 not i=lays; -1 cuz else overwrite first of last layer
		segfault[i] = min(segfault[2*i], segfault[2*i+1]);
}

int query(int lq, int rq, int idx=1, int lb=0, int rb=(1<<lays)-1, int acc=0)
{
	//for (int i=0; i<log2(idx); ++i) printf("|   "); printf("lq %d rq %d lb %d rb %d\n", lq, rq, lb, rb);
	if (rq < lb || rb < lq)
		return 1<<30;

	acc += addv[idx];
	if (lq <= lb && rb <= rq)
		return segfault[idx] + acc;

	const int lc = 2*idx;
	const int rc = 2*idx +1;
	const int mid = lb + (rb-lb)/2; // (lb+rb)/2 w/o overflow
	return min(
			query(lq, rq, lc, lb, mid, acc),
			query(lq, rq, rc, mid+1, rb, acc));
}

int update(int lq, int rq, int val, int idx=1, int lb=0, int rb=(1<<lays)-1)
{
	if (rq < lb || rb < lq) return segfault[idx];
	if (lq <= lb && rb <= rq)
	{
		addv[idx] += val; // FIX: add to addv not minv
		return segfault[idx] + addv[idx]; // FIX: return acutual not original
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
			
