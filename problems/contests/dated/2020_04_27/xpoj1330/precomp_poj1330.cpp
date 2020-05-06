// AC 5 May 2020 @ 17:12 (PDT)
#include <iostream>

const int MX = 10111;
int T, parent[MX], vis[MX];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		memset(parent, 0, sizeof parent);
		memset(vis, 0, sizeof vis);

		for (int i=1; i<N; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			parent[v] = u;
		}

		int a, b, c;
		scanf("%d%d", &a, &b);
		for (c=a; parent[c]; c = parent[c])
			vis[c] = 1;
		for (c=b; parent[c] && !vis[c]; c = parent[c]);

		printf("%d\n", c);
	}
}

