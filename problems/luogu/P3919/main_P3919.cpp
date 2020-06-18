/*
 * Problem P3919 (luogu/P3919)
 * Create time: Thu 18 Jun 2020 @ 09:25 (PDT)
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
ll N, D, M, segt[MX<<5], sett[MX<<5];
ll alloc=1, lc[MX<<5], rc[MX<<5], rt[MX];

void dump(ll k)
{
	ll d = D+1;
	queue<int> bfs;
	bfs.push(k);
	for (ll i=1; i<1<<1+D; ++i)
	{
		k = bfs.front(); bfs.pop();
		bfs.push(lc[k]);
		bfs.push(rc[k]);
		if (__builtin_popcount(i) == 1) { --d; printf("\n"); }
		printf("%-2d: %2d =%-2d(%-2d %2d)  ", k, segt[k], sett[k], lc[k], rc[k]);
		for (int i=1; i<1<<d; ++i) printf("                   ");
	}
	printf("\n");
}
void dupe(ll &k)
{
	segt[alloc] = segt[k];
	sett[alloc] = sett[k];
	lc[alloc] = lc[k];
	rc[alloc] = rc[k];
	k = alloc++;
}

void apply(ll setv, ll &k, ll tl, ll tr)
{
	dupe(k);
	sett[k] = setv;
	segt[k] = setv * (tr-tl+1);
}
void push(ll &k, ll tl, ll tr)
{
	dupe(k);
	if (sett[k] < 0) return;
	ll mid = tl + (tr-tl>>1);
	apply(sett[k], lc[k], tl, mid);
	apply(sett[k], rc[k], mid+1, tr);
	sett[k] = -1;
}
void combo(ll k)
{
	segt[k] = segt[lc[k]] + segt[rc[k]];
}

void update(ll ql, ll qr, ll setv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) return apply(setv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, setv, lc[k], tl, mid);
	update(ql, qr, setv, rc[k], mid+1, tr);
	combo(k);
}
ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D)	// TODO: take k as refrence?
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <+ qr) return segt[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	return query(ql, qr, lc[k], tl, mid) + query(ql, qr, rc[k], mid+1, tr);
}

int main()
{
	scanf("%d%d", &N, &M);
	D = log2(N) +1;
	memset(sett, -1, sizeof sett);

	rt[0] = alloc++;
	for (int i=1; i<1<<D; ++i)
	{
		lc[i] = alloc++;
		rc[i] = alloc++;
	}
	for (int i=1; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		update(i, i, d, rt[0]);
	}
	for (int i=1; i<=M; ++i)
	{
		dump(rt[i-1]); printf("\n\n$ ");
		int t, c, p;	// QUIC noises
		scanf("%d%d%d", &t, &c, &p);
		rt[i] = rt[t];
		if (c == 1)
		{
			int v; scanf("%d", &v);
			update(i, i, v, rt[i]);
		}
		if (c == 2)
		{
			printf("%d\n", query(i, i, rt[t]));
		}
	}

	return 0;
}

