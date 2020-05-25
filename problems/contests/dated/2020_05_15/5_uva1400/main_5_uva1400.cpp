/*
TASK: 5_uva1400
LANG: C++14
*/

/*
 * Problem 5_uva1400 (contests/dated/2020_05_15/5_uva1400)
 * Create time: Mon 25 May 2020 @ 10:46 (PDT)
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

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "5_uva1400");

using namespace std;
const int MX = 500111;
int val[MX], tot[MX], lef[MX], rig[MX];
int N, M, D;

void build()
{
	scanf("%d%d", &N, &M);
	D = log2(N)+1;
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &tot[(1<<D)+i]);
		if (tot[(1<<D)+i] > 0)
			val[(1<<D)+i] = lef[(1<<D)+i] = rig[(1<<D)+i] = tot[(1<<D)+i];
	}
	for (int i=(1<<D)-1; i>0; --i)
	{
		tot[i] = tot[i*2] + tot[i*2+1];
		lef[i] = max(lef[i*2], tot[i*2]+lef[i*2+1]);
		rig[i] = max(rig[i*2+1], tot[i*2+1]+rig[i*2]);
		val[i] = max(
					max(
						tot[i],
						max(lef[i], rig[i])
					   ),
					max(
						rig[i*2]+lef[i*2+1],
						max(val[i*2], val[i*2+1])
					   )
				);
	}
	printf("\n");
	for (int i=1; i<(1<<D+1); ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("     (%3d %3d %3d %3d)", val[i], tot[i], lef[i], rig[i]);
	}
	printf("\n");
}

ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return val[k];
	const int mid = tl + (tr - tl)/2;
	return max(query(ql, qr, k*2, tl, mid), query(ql, qr, k*2+1, mid+1, tr));
}

int main()
{
	build();
	for (int i=0; i<M; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}

    return 0;
}

