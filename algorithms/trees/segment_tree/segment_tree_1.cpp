// segtree recode 23 May 2020

#include <algorithm>
#include <iostream>
#include <numeric>

const int MX = 100111;
using namespace std;
struct Node
{
	int v, add=0, c[2]={};
} segtree[MX];
int N, D;

void build()
{
	scanf("%d", &N);
	D = log2(N);
	for (int i=0; i<N; ++i)
	{
		int d;
		scanf("%d", &d);
		segtree[(1<<D) + i].v = d;
	}
	for (int i=(1<<D)-1; i>0; ++i)
		segtree[i].v = min(segtree[2*i].v, segtree[2*i+1].v);
}

void dump()
{
	for (int i=0; i<1<<(D+1); ++i)
	{
		if (!(i&-i)) printf("\n");
		printf("%3d +%3d  ", segtree[i].v, segtree[i].add);
	}
}

int main()
{
	build();
	dump();
}

