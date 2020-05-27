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
#include <numeric>
#include <utility>
#include <cmath>

#define ll long long
#define dl double

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 5000111;
typedef pair<ll, pair<ll, ll> > Range;
typedef pair<pair<Range, Range>, pair<Range, Range> > Desc;
//Range val[MX], tot[MX], lef[MX], rig[MX];
Desc st[MX];	// best, tot, lef, rig
int N, M, D;
Range RMIN = {-100000000000000, {0, 0}};
Desc DMIN = { {RMIN, RMIN}, {RMIN, RMIN} };

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

Range best(const Range &lhs, const Range &rhs)
{
	if (lhs.f != rhs.f) return lhs.f > rhs.f ? lhs : rhs;
	if (lhs.s.f != rhs.s.f) return lhs.s.f < rhs.s.f ? lhs : rhs;
	return lhs.s.s < rhs.s.s ? lhs : rhs;
}

Range add(const Range &lhs, const Range &rhs)
{
	if (!lhs.s.f) return rhs;
	if (!rhs.s.f) return lhs;
	if (lhs.s.s+1 != rhs.s.f)
		printf("wait thats illegal: %d (%d..%d) + %d (%d..%d)\n", lhs.f, lhs.s.f, lhs.s.s, rhs.f, rhs.s.f, rhs.s.s);
	return mp(lhs.f + rhs.f, mp(lhs.s.f, rhs.s.s));
}

Desc combine(const Desc &lhs, const Desc &rhs)
{
	Range tot = add(lhs.f.s, rhs.f.s);
	Range lef = best(lhs.s.f, add(lhs.f.s, rhs.s.f));
	Range rig = best(rhs.s.s, add(lhs.s.s, rhs.f.s));
	Range val = best(best(lhs.f.f, rhs.f.f), add(lhs.s.s, rhs.s.f));
	Desc ret = mp(mp(val, tot), mp(lef, rig));
	return ret;
}

void build()
{
	D = log2(N)+1;
	for (int i=0; i<N; ++i)
	{
		int d, j = (1<<D)+i;
		scanf("%d", &d);
		st[j].f.s = mp(d, mp(i+1, i+1));
		st[j].f.f = st[j].s.f = st[j].s.s = st[j].f.s;
	}
	for (int i=(1<<D)-1; i>0; --i)
		st[i] = combine(st[i*2], st[i*2+1]);

//	printf("\n");
//	for (int i=1; i<(1<<D+1); ++i)
//	{
//	    if (__builtin_popcount(i) == 1) printf("\n");
//	    print(st[i]);
//	}
//	printf("\n");
}

Desc query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	//printf("query %d..%d @ %d (%d..%d)\n", ql, qr, k, tl, tr);
	if (qr < tl || tr < ql) return DMIN;
	if (ql <= tl && tr <= qr) return st[k];
	const int mid = tl + (tr - tl)/2;
	const int lc = 2*k, rc = lc+1;
	Desc lef = query(ql, qr, k*2, tl, mid);
	Desc rig = query(ql, qr, k*2+1, mid+1, tr);

	return combine(lef, rig);
}

int main()
{
	int kase=0;

	while (scanf("%d%d", &N, &M) == 2)
	{
		build();
		printf("Case %d:\n", ++kase);
		for (int i=0; i<M; ++i)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			Range opm = query(l, r).f.f;
			//printf("%d %d (%d)\n", opm.s.f, opm.s.s, opm.f);	// FIX: print both, not just opm.s.s smah
			printf("%lld %lld\n", opm.s.f, opm.s.s);
		}
	}

	return 0;
}

/*
   10 100
   10 2 -9 5 3 -12 -2 1 10 7

   10 100
   12 -9 3 4 -2 8 7 -6 2 5
   */
