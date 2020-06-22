/*
 * Problem P3919 (luogu/P3919)
 * Create time: Mon 22 Jun 2020 @ 11:22 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
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
const ll MX = 1000111;
ll N, D, Q, val[MX<<5];
ll alc=1, lc[MX<<5], rc[MX<<5], rt[MX];

void dupe(ll &k)
{
	val[alc] = val[k];
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
}
void update(ll q, ll setv, ll &k, ll tl=1, ll tr=1<<D)
{
	dupe(k);
	if (tl == tr) { val[k] = setv; return; }

	ll mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, setv, lc[k], tl, mid);
	else update(q, setv, rc[k], mid+1, tr);
}
ll query(ll q, ll k, ll tl=1, ll tr=1<<D)
{
	//printf("query %d @ %d(%d..%d)\n", q, k, tl, tr);
	if (tl == tr) return val[k];
	ll mid = tl + (tr-tl>>1);

	if (q <= mid) return query(q, lc[k], tl, mid);
	else return query(q, rc[k], mid+1, tr);
}

int main()
{
	scanf("%lld%lld", &N, &Q);
	D = log2(N)+1;
	rt[0] = alc++;
	for (ll i=1; i<1<<D; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
	}

	for (ll i=0; i<N; ++i)
	{
		scanf("%lld", &val[i+(1<<D)]);
	}

	for (ll q=1; q<=Q; ++q)
	{
		ll t, c, p; scanf("%lld%lld%lld", &t, &c, &p);
		rt[q] = rt[t];
		if (c == 2) printf("%lld\n", query(p, rt[q]));
		if (c == 1)
		{
			ll d; scanf("%lld", &d);
			update(p, d, rt[q]);
		}
	}

	return 0;
}

