/*
TASK: 1428_bidx
LANG: C++14
*/

/*
 * Problem 1428_bidx (oj/pid/1428_bidx)
 * Create time: Sun 31 May 2020 @ 10:22 (PDT)
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

void setIO(const std::string &name = "1428_bidx");

using namespace std;
const int MX = 100111;

ll T, N, bidx[MX], lef[MX], rig[MX];

void update(ll i, ll v)
{
	if (!i) return;	// FIX: can't update zero
	for (; i<=N; i += i&-i)
		bidx[i] += v;
}
ll query(int l, int r)
{
	//printf("query %lld %lld, r<l: %lld\n", l, r, r < l);
	if (r < l) return 0;	// FIX: invalid range detection

	ll tot; --l;			// FIX: --l for inclusive inclusive
	for (; r>l; r-=r&-r)
		tot += bidx[r];
	printf("tot: %lld\n", tot);
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}
void dump()
{
	for (int i=1; i<=N; ++i)
		printf("%3lld ", bidx[i]);
	printf("\n");
}

void solve()
{
	scanf("%lld", &N);
	memset(bidx, 0, sizeof bidx);
	memset(lef, 0, sizeof lef);
	memset(rig, 0, sizeof rig);
	vector<pair<ll, ll> > sorted;
	//printf("epic"); fflush(stdout);
	for (ll i=1; i<=N; ++i)
	{
		ll t; scanf("%lld", &t);
		//printf("t: %lld, t-1: %lld\n", t, t-1);

		lef[i-1] = query(1, t-1);	// FIX: i-1
		sorted.eb(t, i-1);			// FIX: here too

		//printf("uh"); fflush(stdout);
		update(t, 1);
		dump();
	}
	sort(sorted.begin(), sorted.end());
	for (ll i=0; i<sorted.size(); ++i)
		rig[sorted[i].s] = i - lef[sorted[i].s];

	for (int i=0; i<N; ++i)
		printf("%d: left %4lld right %4lld\n", i, lef[i], rig[i]);

	ll tot = 0;
	for (ll i=0; i<N; ++i)
		tot += lef[i]*(N-rig[i]-i-1) + (i-lef[i])*rig[i];
	printf("%lld\n", tot);
}

int main()
{
	//N = 20;
	//memset(bidx, 0, sizeof bidx);
	//while (true)
	//{
	//    char c =' ';while (c<'a'||c>'z') scanf("%c", &c);
	//    int a, b; scanf("%d%d", &a, &b);
	//    if (c == 'u') update(a, b);
	//    if (c == 'q') printf("%d\n", query(a, b));
	//    dump();
	//}
	scanf("%lld", &T);
	for (int t=0; t<T; ++t)
		solve();

	return 0;
}

