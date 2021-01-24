/*
 * Problem 1079 (usaco/gold/2021jan/1079)
 * Create time: Sun 24 Jan 2021 @ 12:46 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
// #define db(...) (1)
using namespace std;

const ll MX = 2e5+10;

ll N, K, M;
ll arr[MX], arr2[MX];
ll swapl[MX], swapr[MX];

set<ll> been[MX], chain[MX], snap[MX];
ll ans[MX];
bool chainvis[MX];

void kchain(ll i, ll d)
{
	if (!d || chainvis[i]) return; chainvis[i] = 1;
	kchain(arr[i], d-1);
	db("chain %d at %d remains %d\n", arr[i], i, d);
	db("    "); for (auto x : chain[arr[i]]) db("%3d", x); db("\n");
	db("   +"); for (auto x : been[i])  db("%3d", x); db("\n");
	for (auto x : been[i]) chain[arr[i]].insert(x);
	db("   ="); for (auto x : chain[arr[i]]) db("%3d", x); db("\n");
}

int main()
{
	scanf("%lld%lld%lld", &N, &K, &M);
	F(i, K) scanf("%lld%lld", &swapl[i], &swapr[i]);

	F(i, N) arr[i] = i;
	F(i, K) {
		swap(arr[swapl[i]], arr[swapr[i]]);
		been[arr[swapl[i]]].insert(swapl[i]);
		been[arr[swapr[i]]].insert(swapr[i]);
		// db("%d %d==%d\n", i, i-1, M%K);
		if (i%K == M%K) F(i, N) {
				ans[i] = been[i].size();
				for (auto x : been[i])
					snap[i].insert(x);
			}
		if (i >= M) break;
	}
	if (M <= K) {
		F(i, N) printf("%lld\n", ans[i]+1);
		db("im out\n");
		return 0;
	}
	F(i, N) for (auto x : been[i]) chain[i].insert(x);
	F(i, N) chain[i].insert(i);
	F(i, N) kchain(i, M/K-1);
	// memcpy(arr2, arr, sizeof arr2);
	F(i, N) arr2[i] = arr[i];
	F(i, (M-1)/K-1) F(i, N) arr2[i] = arr[arr2[i]];
	db("arr2 = "); F(i, N) db("%3d", arr2[i]); db("\n");
	F(i, N) for (auto x : snap[i]) chain[arr2[i]].insert(x);
	F(i, N) printf("%lld\n", chain[i].size());
}
