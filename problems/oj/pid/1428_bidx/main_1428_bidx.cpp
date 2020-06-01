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
const ll MX = 100111;

ll T, N, bit[MX], c[MX], d[MX];

//void update(ll i, ll v)
//{
//    if (!i) return;	// FIX: can't update zero
//    for (; i<=MX; i += i&(-i))	// FIX: MX not N, since we are doing the counting sort thing
//        bit[i] += v;
//}
////ll query(int l, int r)
////{
////    //printf("query %lld %lld, r<l: %lld\n", l, r, r < l);
////    if (r < l) return 0;	// FIX: invalid range detection

////    ll tot=0; --l;			// FIX: init tot; --l for inclusive inclusive
////    for (; r>l; r-=r&-r)
////        tot += bit[r];
////    for (; l>r; l-=l&-l)
////        tot -= bit[l];
////    return tot;
////}
//ll query(int i)
//{
//    ll tot = 0;
//    for (; i; i-=i&(-i))
//        tot += i;
//    return tot;
//}

int low_bit(int x) {
    return x & (-x);
}

void update(int idx) {
    if (idx >= N) return;
    bit[idx]++;
    update(idx + low_bit(idx));
}

int query(int idx) {
    if (idx == 0) return 0;
    return bit[idx] + query(idx - low_bit(idx));
}

void dump()
{
	return;
	for (int i=1; i<=MX; ++i)
		printf("%3lld ", bit[i]);
	printf("\n");
}

void solve()
{
	scanf("%lld", &N);
	memset(bit, 0, sizeof bit);
	memset(c, 0, sizeof c);
	memset(d, 0, sizeof d);
	vector<pair<ll, ll> > sorted;
	sorted.reserve(N);
	//printf("epic"); fflush(stdout);
	for (ll i=0; i<N; ++i)
	{
		ll t; scanf("%lld", &t);
		//printf("t: %lld, t-1: %lld\n", t, t-1);

		c[i] = query(t-1);
		//printf("c[%d] = %d\n", i, c[i]);
		sorted.eb(t, i);

		//printf("uh"); fflush(stdout);
		update(t);
		dump();
	}
	sort(sorted.begin(), sorted.end());
	for (ll i=0; i<sorted.size(); ++i)
		d[sorted[i].s] = i - c[sorted[i].s];

	//for (int i=0; i<N; ++i)
	//    printf("%d: c %4lld right %4lld\n", i, c[i], d[i], c[i]*(N-d[i]-i-1) + (i-c[i])*d[i]);

	ll tot = 0;
	for (ll i=0; i<N; ++i)
		tot += c[i]*(N-d[i]-i-1) + (i-c[i])*d[i];
	printf("%lld\n", tot);
}

int main()
{
	//N = 20;
	//memset(bit, 0, sizeof bit);
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

