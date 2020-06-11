/*
 * Problem 3584 (hdu/3584)
 * Create time: Sun 07 Jun 2020 @ 16:18 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 111;

int N, Q, delt[MX][MX][MX];

void rupdate(int i, int _j, int _k, int v=1)
{
	for (; i<=N; i+=i&-i)
		for (int j=_j; j<=N; j+=j&-j)
			for (int k=_k; k<=N; k+=k&-k)
				delt[i][j][k] += v;
				//delt[i][j][k] = !delt[i][j][k];
}

int query(int i, int _j, int _k)
{
	int tot = 0;
	for (; i; i-=i&-i)
		for (int j=_j; j; j-=j&-j)
			for (int k=_k; k; k-=k&-k)
			{
				//printf("    adding %d %d\n", i, j);
				tot += delt[i][j][k];
				//tot ^= delt[i][j][k];
				//if (delt[i][j][k]) tot = !tot;
			}
	return tot;	// FIX: don't forget to return
}

void update(int i1, int j1, int k1, int i2, int j2, int k2, int v=1)
{
	++i2; ++j2; ++k2;
	// magenta
	rupdate(i2, j2, k2, -v);
	// blue
	rupdate(i2, j2, k1, v);
	rupdate(i2, j1, k2, v);
	rupdate(i1, j2, k2, v);
	// yellow
	rupdate(i2, j1, k1, -v);
	rupdate(i1, j2, k1, -v);
	rupdate(i1, j1, k2, -v);
	// orange
	rupdate(i1, j1, k1, v);
}

int main()
{
	while (scanf("%d%d", &N, &Q))
	{
		for (int i=0; i<Q; ++i)
		{
			int c, x1, y1, z1;
			scanf("%d%d%d%d", &c, &x1, &y1, &z1);
			if (c)
			{
				int x2, y2, z2;
				scanf("%d%d%d", &x2, &y2, &z2);
				update(x1, y1, z1, x2, y2, z2);
			}
			else
			{
				printf("%d\n", query(x1, y1, z1)%2);	// FIX: output ll (long long)?
			}
		}
	}

	return 0;
}

