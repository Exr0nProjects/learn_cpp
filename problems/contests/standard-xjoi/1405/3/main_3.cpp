/*
 * Problem 3 (contests/standard-xjoi/1405/3)
 * Create time: Thu 11 Jun 2020 @ 07:43 (PDT)
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
const int MX = 100111;
int N, M, delt[MX], pref[MX];
void rupdate(int bit[], int i, int v)
{
	//printf("rupdate %d with %d\n", i, v);
	for (; i<=N; i+=i&-i)
		bit[i] += v;		// FIX: typo bit[i] += v not bit += v
}
int rprefix(int bit[], int i)
{
	//printf("rquery %d\n", i);
	int tot = 0;
	for (; i; i-=i&-i)
		tot += bit[i];
	return tot;
}

int query(int l, int r)
{
	//printf("query %d %d\n", l, r);
	-- l;
	int ret = (r+1)*rprefix(delt, r) - rprefix(pref, r);
	//printf("query right: %d\n", ret);
	return ret - ((l+1)*rprefix(delt, l) - rprefix(pref, l));	// FIX: order of operations: subtract c - (a-b) = c-a+b, must parens or flip sign
}

//ll query(int l, int r)
//{
//    --l;
//    // TODO: understand this algebraic magic
//    ll tot = (r+1)*(ll)rprefix(delt, r) - (ll)rprefix(pref, r);
//    tot -= (l+1)*(ll)rprefix(delt, l) - (ll)rprefix(pref, l);
//    return (ll)tot;
//}

void update(int l, int r, int v=1)
{
	//printf("update %d %d\n", l, r);
	rupdate(delt, l, v);
	rupdate(delt, r+1, -v);
	rupdate(pref, l, l*v);
	rupdate(pref, r+1, (r+1)*-v);
}

/*
ll raw_prefix(ll bit[], int n)
{
	ll tot = 0;	// FIX: smah, missing ll here
	for (; n; n-=n&-n)
		tot += bit[n];
	return tot;
}

void raw_update(ll bit[], int n, ll v)
{
	for (; n<=N; n+=n&-n)
		bit[n] += v;
}

ll query(int l, int r)
{
	--l;
	// TODO: understand this algebraic magic
	ll tot = (ll)((ll)r+1LL)*(ll)raw_prefix(delt, r) - (ll)raw_prefix(pref, r);
	tot -= (ll)((ll)l+1LL)*(ll)raw_prefix(delt, l) - (ll)raw_prefix(pref, l);
	return (ll)tot;
}

void update(int l, int r, ll v)
{
	raw_update(delt, l, v);
	raw_update(delt, r+1, -v);			// +1 cuz thats the delta between arr[r] and arr[r+1]
	raw_update(pref, l, l*v);			// pref[i] = i*delt[i], TODO: why multiply?
	raw_update(pref, r+1, (r+1)*-v); 	// "undo" previous line
}
*/

void dump()
{
	return;
	printf("delt: ");
	for (int i=1; i<=N; ++i)
		printf("%3d", delt[i]);
	printf("\npref: ");
	for (int i=1; i<=N; ++i)
		printf("%3d", pref[i]);
	printf("\n");
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int c, l, r;
		scanf("%d%d%d", &c, &l, &r);
		if (c == 1) update(l, r-1);
		if (c == 2) printf("%d\n", query(l, r-1));
		dump();
	}

	return 0;
}

