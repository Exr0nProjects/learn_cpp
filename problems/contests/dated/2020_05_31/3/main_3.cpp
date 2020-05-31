/*
 * Problem 3 (contests/dated/2020_05_31/3)
 * Create time: Sun 31 May 2020 @ 14:37 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 60111;

int N, S, R, D, segt[2*MX], addv[2*MX];
void dump()
{
	for (int i=1; i<2<<D; ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("%3d", segt[i]);
	}
	printf("\n");
}
void build()
{
	D = log2(N)+1;
	memset(segt, 0, sizeof segt);
	memset(addv, 0, sizeof addv);
}
void update(int ql, int qr, int v, int k=1, int tl=1, int tr=1<<D)
{
	//printf("update %d..%d +%d   @%d (%d %d)\n", ql, qr, v, k, tl, tr);
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		addv[k] += v;
		segt[k] += v;
		return;
	}
	int mid = tl + (tr-tl)/2;
	update(ql, qr, v, k*2, tl, mid);
	update(ql, qr, v, k*2+1, mid+1, tr);
	segt[k] = max(segt[k*2], segt[k*2+1]);
}
int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D, int acc=0)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k] + acc;
	acc += addv[k];
	int mid = tl + (tr-tl)/2;
	return max(query(ql, qr, k*2, tl, mid, acc), query(ql, qr, k*2+1, mid+1, tr, acc));
}

int main()
{
	scanf("%d%d%d", &N, &S, &R);
	build();
	//while (true)
	//{
	//    char c=' '; while (c<'a'||c>'z') scanf("%c", &c);
	//    int a, b; scanf("%d%d", &a, &b);
	//    if (c == 'q') printf("%d\n", query(a, b));
	//    if (c == 'u')
	//    {
	//        int v; scanf("%d", &v);
	//        update(a, b, v);
	//    }
	//    dump();
	//}
	for (int i=0; i<R; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		//printf("\n%d..%d: max %d\n", u, v, query(u, v));
		if (query(u, v) + w <= S)
		{
			printf("T\n");
			update(u, v, w);
		}
		else
			printf("N\n");
	}

	return 0;
}

