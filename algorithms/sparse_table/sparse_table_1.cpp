// recode sumation sparse table, 23 may 2020

#include <iostream>
#include <numeric>

const int MX = 100111;
int N, D, table[20][MX];

void init()
{
	scanf("%d", &N);
	D = log2(N)+1;
	memset(table, 0, sizeof table);
	for (int i=0; i<N; ++i)
		scanf("%d", &table[0][i]);
	for (int j=1; j<D; ++j)
		for (int i=0; i+(1<<j)<=N; ++i)	// FIX: <=N cuz +(1<<j) adds the exc r fencepost
			table[j][i] = table[j-1][i] + table[j-1][i+(1<<j-1)];
	
	for (int j=0; j<D; ++j)
	{
		for (int i=0; i<N; ++i)
			printf("%3d", table[j][i]);
		printf("\n");
	}
}

int query(int l, int r) // inc l exc r
{	// works for sum, no overlap
	if (l > r) return -1;	// not needed
	int dif=r-l, ret=0;
	for (int bit=0; bit<32; ++bit)
		if (dif & (1<<bit))
		{
			printf("%d..%d\n", l, l+(1<<bit));
			ret += table[bit][l];
			l += (1<<bit);
		}
	return ret;
}

int main()
{
	init();
	int Q;
	scanf("%d", &Q);
	for (int q=0; q<Q; ++q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}

