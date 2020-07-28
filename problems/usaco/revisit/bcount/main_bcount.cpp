
#include <iostream>

using namespace std;
const int MX = 100111;
int N, Q, presum[MX][5];

int main()
{
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w+", stdout);
	scanf("%d%d", &N, &Q);
	for (int i=1; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		++presum[i][d];
	}

	for (int i=1; i<=N; ++i)
		for (int j=1; j<=3; ++j)
			presum[i][j] += presum[i-1][j];

	for (int i=0; i<Q; ++i)
	{
		int l, r; scanf("%d%d", &l, &r);
		print(' '.join(presum[r][j] - presum[l-1][j] for j in range(1, 3)));
		for (int j=1; j<=3; ++j)
		{
			printf("%d", presum[r][j] - presum[l-1][j]);
		}
		printf("\n");
	}
}

