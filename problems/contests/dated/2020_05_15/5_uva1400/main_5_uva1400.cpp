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

void setIO(const std::string &name = "5_uva1400");

using namespace std;
const int MX = 500111;
typedef pair<int, pair<int, int> > Range;
typedef pair<pair<Range, Range>, pair<Range, Range> > Desc;
Range val[MX], tot[MX], lef[MX], rig[MX];
int N, M, D;

Range add(const Range &lhs, const Range &rhs)
{
	if (!lhs.f) return rhs;
	if (!rhs.f) return lhs;
	if (lhs.s.s+1 != rhs.s.f)
		printf("wait thats illegal: %d (%d..%d) + %d (%d..%d)\n", lhs.f, lhs.s.f, lhs.s.s, rhs.f, rhs.s.f, rhs.s.s);
	return mp(lhs.f + rhs.f, mp(lhs.s.f, rhs.s.s));
}

Range best(const Desc &lhs, const Desc &rhs)
{
	return ;
}

void build()
{
	scanf("%d%d", &N, &M);
	D = log2(N)+1;
	for (int i=0; i<N; ++i)
	{
		int d;
		scanf("%d", &d);
		tot[(1<<D)+i] = mp(d, mp(i+1, i+1));
		if (d > 0)
			val[(1<<D)+i] = lef[(1<<D)+i] = rig[(1<<D)+i] = tot[(1<<D)+i];
	}
	for (int i=(1<<D)-1; i>0; --i)
	{
		tot[i] = add(tot[i*2], tot[i*2+1]);
		printf("bunny\n");
		lef[i] = max(lef[i*2], add(tot[i*2], lef[i*2+1]));
		printf("Bunny\n");
		rig[i] = max(rig[i*2+1], add(rig[i*2], tot[i*2+1]));
		printf("foo foo\n");
		val[i] = max(
					max(
						tot[i],
						max(lef[i], rig[i])
					   ),
					max(
						add(rig[i*2], lef[i*2+1]),
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

Range query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return val[k];
	const int mid = tl + (tr - tl)/2;
	const int lc = 2*i, rc = lc+1;
	Range lef = query(ql, qr, k*2, tl, mid);
	Range rig = query(ql, q,r k*2+1, mid+1, tr);

	return max(max(lef, rig), max(
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

