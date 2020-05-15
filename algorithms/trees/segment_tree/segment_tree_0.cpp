// 14 May 2020

#include <iostream>
using namespace std;

const int MX = 100111;
int N, lays, segfault[2*MX], addv[2*MX];

void build()
{
	scanf("%d", &N);
	lays = ceil(log2(N));
	for (int i=0; i<N; ++i)
		scanf("%d", &segfault[i+ (1<<lays)]);
	for (int i=lays; i>0; --i)
		segfault[i] = min(segfault[2*i], segfault[2*i+1]);

	for (int i=0; i<2*N; ++i)
	{
		if (__bultin_popcount(i) == 1) printf("\n");
		printf("%3d", segfault[i]);
	} printf("\n");
}

int query(int lq, int rq, int idx=1, int lb=0, int rb=1<<lays)
{
	if (rq < lb || lq > rb) return 1<<30;
	if (lq <= lb && rq >= rb) return segfault[idx];

	const int lc = 2*idx;
	const int rc = 2*idx +1;
	const int mid = lb + (rb-lb)/2; // (lb+rb)/2 w/o overflow
	return min(query(lq, rq, lc, lb, mid), query(lq, rq, rc, mid+1, rb));
}

