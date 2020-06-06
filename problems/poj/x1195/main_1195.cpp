/*
 * Problem 1195 (poj/1195)
 * Create time: Sat 06 Jun 2020 @ 12:07 (PDT)
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
const int MX = 1111;
int N, bidx[MX][MX];

int prefix(int y, int _x)
{
	int ret=0;
	for (; y; y-=y&-y)				// FIX: += bidx[y] not += y smah
		for (int x=_x; x; x-=x&-x)	// FIX: reset x for inner loop
			ret += bidx[y][x];
	return ret;
}

int query(int l, int b, int r, int t)
{
	--l; --b;
	l = max(l, 0);
	b = max(b, 0);

	//printf("query (%3d %3d) (%3d %3d)\n", l, b, r, t);
	//printf("    + %3d %3d: %3d\n", r, t, prefix(r, t));
	//printf("    - %3d %3d: %3d\n", l, t, prefix(l, t));
	//printf("    - %3d %3d: %3d\n", r, b, prefix(r, b));
	//printf("    + %3d %3d: %3d\n", l, b, prefix(l, b));
	//printf("=> %d\n", prefix(r, t) - prefix(l, t) - prefix(r, b) + prefix(l, b));

	// principle inclusion exclusion
	return prefix(r, t)
		 - prefix(l, t)
		 - prefix(r, b)
		 + prefix(l, b);
}

void update(int y, int _x, int v)
{
	//printf("updating %d %d\n", y, _x);
	for (; y<=N; y+=y&-y)
		for (int x=_x; x<=N; x+=x&-x)	// FIX: reset x for inner loop
		{
			//printf("    adding to %d %d\n", y, x);
			bidx[y][x] += v;
		}
}

void pdump()
{
	for (int i=1; i<=N; ++i)
	{
		for (int j=1; j<=N; ++j)
			//printf("%3d", query(i, j, i, j));
			//printf("%3d", prefix(i, j));
			printf("%3d", bidx[i][j]);
		printf("\n");
	}
}

int main()
{
	//int Q;
	//scanf("%d%d", &N, &Q);
	//for (int i=1; i<=N; ++i)
	//    for (int j=1; j<=N; ++j)
	//    {
	//        int d; scanf("%d", &d);
	//        update(i, j, d);
	//        pdump();
	//        printf("\n");
	//    }

	//for (int i=0; i<Q; ++i)
	//{
	//    int l, b, r, t;
	//    scanf("%d%d%d%d", &l, &b, &r, &t);
	//    printf("query(%d, %d; %d, %d) %d\n", l, b, r, t, query(l, b, r, t));
	//    printf("prefix(%d, %d) %d\n", l, b, prefix(l, b));
	//    pdump();
	//}

	while (true)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 0)
		{
			scanf("%d", &N);
			memset(bidx, 0, sizeof bidx);
		}
		if (cmd == 1)
		{
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			update(x+1, y+1, v);
		}
		if (cmd == 2)
		{
			int l, b, r, t;
			scanf("%d%d%d%d", &l, &b, &r, &t);
			printf("%d\n", query(l+1, b+1, r+1, t+1));
		}
		if (cmd == 3)
		{
			break;
		}
		//pdump();
	}

	return 0;
}

