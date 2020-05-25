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
//Desc st[MX];	// best, tot, lef, rig
int N, M, D;

void print(const Range &r)
{
	printf(" %d(%d..%d)", r.f, r.s.f, r.s.s);
}
void print(const Desc &r)
{
	printf("  (");
	printf(" v"); print(r.f.f);
	printf(" t"); print(r.f.s);
	printf(" l"); print(r.s.f);
	printf(" r"); print(r.s.s);
	printf(" ) ");
}

Range add(const Range &lhs, const Range &rhs)
{
	if (!lhs.f) return rhs;
	if (!rhs.f) return lhs;
	if (lhs.s.s+1 != rhs.s.f)
		printf("wait thats illegal: %d (%d..%d) + %d (%d..%d)\n", lhs.f, lhs.s.f, lhs.s.s, rhs.f, rhs.s.f, rhs.s.s);
	return mp(lhs.f + rhs.f, mp(lhs.s.f, rhs.s.s));
}

Desc combine(const Desc &lhs, const Desc &rhs)
{
	printf("combining"); print(lhs); print(rhs); printf("...\n");
	Range tot = add(lhs.f.s, rhs.f.s);
	printf("bunny ");
	Range lef = max(lhs.s.f, add(lhs.f.s, rhs.s.f));
	printf("bunny ");
	Range rig = max(rhs.s.s, add(lhs.s.s, rhs.f.s));
	printf("foo ");
	Range val = max(max(lhs.f.f, rhs.f.f), add(lhs.s.s, rhs.s.f));
	printf("foo ");
	return mp(mp(val, tot), mp(lef, rig));
}

void build()
{
	scanf("%d%d", &N, &M);
	D = log2(N)+1;
	for (int i=0; i<N; ++i)
	{
		int d, j = (1<<D)+i;
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
	if (qr < tl || tr < ql) return mp(0, mp(0, 0));
	if (ql <= tl && tr <= qr) return val[k];
	const int mid = tl + (tr - tl)/2;
	const int lc = 2*k, rc = lc+1;
	Range lef = query(ql, qr, k*2, tl, mid);
	Range rig = query(ql, qr, k*2+1, mid+1, tr);

	//return max(max(lef, rig), max(// TODO
}

int main()
{
	Range left = mp(7, mp(1, 5));
	Range right = mp(3, mp(3, 3));
	print(left); printf(" + "); print(right);
	printf(" = "); print(add(left, right)); printf("\n");

	Desc LEFT = Desc{mp(Range(7, mp(1, 4)), Range(-2, mp(1, 5))), mp(Range(7, mp(1, 4)), Range(0, mp(0, 0)))};
	Desc RIGHT = Desc{mp(Range{12, mp(6, 8)}, Range{12, mp(6, 8)}), mp(Range{12, mp(6, 8)}, Range{12, mp(6, 8)})};
	printf("  "); print(LEFT); printf("\n +"); print(RIGHT); printf("\n => "); print(combine(LEFT, RIGHT)); printf("\n");

	return 0;

	build();
	for (int i=0; i<M; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}

    return 0;
}

