/*
TASK: 1_uva1428
LANG: C++14
*/

/*
 * Problem 1_uva1428 (contests/dated/2020_05_15/1_uva1428)
 * Create time: Mon 25 May 2020 @ 09:07 (PDT)
 * Accept time: Fri 29 May 2020 @ 16:00 (PDT)
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=4174
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <vector>
#include <math.h>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 200111;
const int TREE = 1000111;	// TODO: put back
//const int TREE = 100;
int N, D, sval[2*TREE], skill[MX], lef[MX], rig[MX];

void dump()
{
	for (int i=1; i<(1<<D+1); ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("%3d", sval[i]);
	}
	printf("\n");
}

ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D, int lay=0)
{
	//for (int i=0; i<lay; ++i) printf("    "); printf("query %d %d : %d %d..%d\n", ql, qr, k, tl, tr);
	if (qr < ql) return 0;
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr)
	{
		//for (int i=0; i<lay; ++i) printf("    "); printf("direct => %d\n", sval[k], sval[k]);
		return sval[k];	// FIX: (tr-tl+1) not (tr-tl) cuz its inc inc
	}
	const int mid = tl + (tr - tl)/2;
	ll ret= query(ql, qr, 2*k, tl, mid, lay+1) + query(ql, qr, 2*k+1, mid+1, tr, lay+1);
	//for (int i=0; i<lay; ++i) printf("    "); printf("=> %d\n", ret);
	return ret;
}
//ll update_range(ll ql, ll qr, ll v, ll k=1, ll tl=1, ll tr=1<<D)
//{
//    //printf("update %d %d +%d: %d %d..%d\n", ql, qr, v, k, tl, tr);
//    if (qr < ql) return 0;
//    if (qr < tl || tr < ql) return sval[k] + sadd[k]*(tr-tl+1);
//    if (ql <= tl && tr <= qr)
//    {
//        sadd[k] += v;
//        return sval[k] + sadd[k]*(tr-tl+1);
//    }
//    const int mid = tl + (tr-tl)/2;
//    sval[k] = update_range(ql, qr, v, 2*k, tl, mid) + update_range(ql, qr, v, 2*k+1, mid+1, tr);
//    return sval[k] + sadd[k]*(tr-tl+1);
//}

void update(ll q, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (tl == tr)
	{
		++sval[k];
		return;
	}
	const int mid = tl + (tr-tl)/2;
	if (q <= mid) update(q, k*2, tl, mid);
	if (q > mid) update(q, k*2+1, mid+1, tr);
	sval[k] = sval[k*2] + sval[k*2+1];
}

void solve()
{
	memset(sval, 0, sizeof sval);
	memset(skill, 0, sizeof skill);
	D = log2(TREE/5) +1;

	memset(lef, 0, sizeof lef);
	memset(rig, 0, sizeof rig);

	vector<pair<int, int> > sorted;

	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &skill[i]);
		//dump();
		lef[i] = query(1, skill[i]-1);
		//printf("%d (%d): c%3d\n", i, skill[i], lef[i]);
		update(skill[i]);	// FIX: don't update range, just update one. segtree takes care of range
		sorted.pb(mp(skill[i], i));
	}
	sort(sorted.begin(), sorted.end());
	for (int i=0; i<sorted.size(); ++i)
	{
		//printf("sorted %d: (%3d #%3d) c%3d d%3d\n", i, sorted[i].f, sorted[i].s, lef[sorted[i].s], i-lef[sorted[i].s]);
		rig[sorted[i].s] = i-lef[sorted[i].s];
	}
	ll tot=0;
	for (int i=0; i<N; ++i)
	{
		const int val = lef[i]*(N-rig[i]-i-1) + (i-lef[i])*rig[i];
		//printf("%d (%d): c%3d d%3d     += %d\n", i, skill[i], lef[i], rig[i], val);
		tot += val;
	}
	printf("%lld\n", tot);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=0; i<T; ++i) solve();

    return 0;
}

