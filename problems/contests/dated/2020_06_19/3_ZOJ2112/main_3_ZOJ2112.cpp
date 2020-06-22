/*
 * Problem 3_ZOJ2112 (contests/dated/2020_06_19/3_ZOJ2112)
 * Create time: Sat 20 Jun 2020 @ 09:22 (PDT)
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
const ll MX = 50111;
ll N, D, Q, arr[MX];

struct Node
{
	int d, w, k;
	Node *c[2] = {};
	Node(int d, int idx): d(d), w(rand()%1000), k(idx) {}
} *treaps[MX];
void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}
Node *insert(Node *&cur, int d, int idx)
{
	if (!cur) return cur = new Node(d, idx);
	Node *&stp = cur->c[cur->d < d];
	Node *ins = insert(stp, d, idx);
	if (cur->w < stp->w)
		rotate(cur, cur->d<d);
	return ins;
}
void remove(Node *&cur, int d)
{
	if (!cur) return;
	if (cur->d == d)
	{
		if (cur->c[0] && cur->c[1])
		{
			bool dir = cur->c[0]->w < cur->c[1]->w;
			rotate(cur, dir);
			remove(cur->c[1-dir], d);
		}
		else
		{
			Node *thn = cur;
			cur = cur->c[0] ? cur->c[0] : cur->c[1];
			delete thn;
		}
	}
	else
	{
		remove(cur->c[cur->d<d], d);
	}
}
Node *bound(Node *cur, int d, int dir=0)
{
	if (!cur || cur->d == d) return cur;
	Node *got = bound(cur->c[cur->d<d], d, dir);
	if (got) return got;
	return cur->d < d == dir ? nullptr : cur;	// FIX: equation--return cur if opposite direction
}

//#define RESET "\033[0m"
//#define BLACK "\x1b[38;5;239m"
//void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
//{
//    if (lay == 1) printf("dump:\n");
//    if (!cur) return;
//    dump(cur->c[1], lay+1);
//    for (int i=0; i<lay; ++i)
//        printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
//    printf("%d %s(%4d @ %x)%s\n", cur->d, BLACK, cur->w, cur, RESET);
//    dump(cur->c[0], lay+1);
//}

inline ll at(ll v, ll t)
{	// allow segtree to use treap
	return bound(treaps[v], t)->k;
}

ll alc=1, segt[MX<<6], addt[MX<<6];
// k = raw index in presistent segtree storage
// v = segtree node id (heap array storage index)
// t = time
ll dupe(ll v, ll t)
{
	ll k = at(v, t);
	segt[alc] = segt[k];
	addt[alc] = addt[k];
	insert(treaps[v], t, alc);
	return alc++;
}
ll apply(ll addv, ll v, ll t, ll tl, ll tr)
{
	if (!addv) return at(v, t);
	ll k = dupe(v, t);
	addt[k] = addv;
	segt[k] += addv * (tr-tl+1);
	return k;
}
ll push(ll v, ll t, ll tl, ll tr)
{
	ll k = dupe(v, t);
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], v<<1, t, tl, mid);
	apply(addt[k], v<<1|1, t, mid+1, tr);
	addt[k] = 0;
	return k;
}
void comb(ll k, ll v, ll t)
{
	segt[k] = segt[at(v<<1, t)] + segt[at(v<<1|1, t)];
}

void update(ll ql, ll qr, ll addv, ll v, ll t, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) { apply(addv, v, t, tl, tr); return; }
	ll k = push(v, t, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, addv, v<<1, t, tl, mid);
	update(ql, qr, addv, v<<1|1, t, mid+1, tr);
	comb(k, v, t);	// should be equivalent to `comb(k);`
}
//ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D, ll setv=-1)
//{
//    if (qr < tl || tr < ql) return;
//    if (setv < 0) setv = sett[k];
//    if (ql <= tl && tr <= qr) return setv < 0 ? segt[k] : setv*(tr-tl+1);
//    ll mid = tl + (tr-tl>>1);
//    return query(ql, qr, lc[k], tl, mid, setv)
//         + query(ql, qr, rc[k], mid+1, tr, setv);
//}
ll querykth(ll v, ll t1, ll t2, ll kth, ll tl=1, ll tr=1<<D)
{
	printf("query %dth (%d and %d @%d (%d..%d))\n", kth, t1, t2, v, tl, tr);
	if (tl == tr) return tl;
	push(v, t1, tl, tr); push(v, t2, tl, tr);
	ll mid = tl + (tr-tl>>1);
	ll lsize = segt[at(v<<1, t2)] - segt[at(v<<1, t1)];
	printf("%d - %d = %d\n", segt[at(v, t2)], segt[at(v, t1)], lsize);
	if (lsize >= kth)
		return querykth(v<<1, t1, t2, kth, tl, mid);
	else
		return querykth(v<<1|1, t1, t2, kth-lsize, mid+1, tr);
}

void dump_segt(ll v, ll t)
{
	ll d = D+1;
	queue<pair<ll, ll> > bfs; bfs.push(mp(v, t));
	for (ll i=1; i<1<<1+D; ++i)
	{
		auto p = bfs.front(); bfs.pop();
		bfs.push(mp(p.f<<1, p.s)); bfs.push(mp(p.f<<1|1, p.s));
		ll k = at(p.f, p.s);
		if (__builtin_popcount(i) == 1) { --d; printf("\n"); }
		printf("%2d: %2d +%-2d   ", k, segt[k], addt[k]);
		for (ll i=1; i<1<<d; ++i) printf("             ");
	}
	printf("\n");
}

void bigdump(ll time)
{
	ll last[MX] = {};
	for (ll t=0; t<=time; ++t)
	{
		printf("t=%-3d", t);
		for (ll v=1; v<1<<1+D; ++v)
		{
			ll got = at(v, t);
			if (got != last[t])
			{
				printf("%5d", got);
				last[t] = got;
			}
		}
		printf("\n");
	}

	for (ll t=0; t<=time; ++t)
		dump_segt(1, t);
}

int main()
{
	//while (true)
	//{
	//    char c=0; while(c<'a' || c>'z') scanf("%c", &c);
	//    ll v, d; scanf("%lld%lld", &v, &d);
	//    if (c == 'i') insert(treaps[v], d, d);
	//    if (c == 'r') remove(treaps[v], d);
	//    if (c == 'b') printf("=> %d\n", bound(treaps[v], d)->idx);
	//    printf("treap %d:\n", v); dump(treaps[v]);
	//}

	ll T; scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &Q);
		D = log2(N) +1;
		memset(segt, 0, sizeof segt);
		memset(addt, 0, sizeof addt);

		for (ll v=1; v<1<<1+D; ++v)
		{
			insert(treaps[v], 0, alc++);
		}
		for (ll i=1; i<=N; ++i)
		{
			scanf("%lld", &arr[i]);
			update(arr[i]+1, arr[i]+1, 1, 1, i);
		}

		for (ll i=i; i<=Q; ++i)
		{
			bigdump(i); printf("\n\n$ ");
			char c=0; scanf("\n%c", &c);
			ll l, r; scanf("%lld%lld", &l, &r);
			if (c == 'Q')
			{
				ll kth; scanf("%lld", &kth);
				printf("%lld\n", querykth(1, l-1, r, kth)-1);
			}
			else if (c == 'C')
			{
				for (ll v=arr[i]+(1<<D), newv=r+(1<<D); v>1; v>>=1, newv>>=1)
				{
					ll k = at(v, l);
					remove(treaps[v], l);
					insert(treaps[newv], l, k);
					if (v < 1<<D) comb(k, v, l);	// TODO: is this enough to update the node?
				}
			}
			else printf("got char '%c'\n", c);
		}
	}
	return 0;
}

