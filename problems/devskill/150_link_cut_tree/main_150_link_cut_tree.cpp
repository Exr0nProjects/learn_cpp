/*
 * Problem 150_link_cut_tree (devskill/150_link_cut_tree)
 * Create time: Tue 12 Jan 2021 @ 12:59 (PST)
 * Accept time: [!meta:end!]
 *  simulate link cut tree operations offline with djs/dsu
 */

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const ll MX = 1e5+10;

ll N, M, par[MX], cost[MX];
ll qt[MX], qv[MX];
ll djf[MX], djd[MX];
bool startscut[MX];
pair<ll, ll> find(ll n)
{
    ll g = 0;
    if (djf[n] != n) tie(djf[n], g) = find(djf[n]);
    //db("   find %d (%d) got %d, %d\n", n, djd[n], djf[n], djd[n]+g);
    return make_pair(djf[n], djd[n] += g);
}
void merge(ll a, ll b)
{
    //db("merging %d <- %d (%d,%d -> %d,%d)\n", a, b, djf[b], djd[b], a, djd[a]+cost[b]),
    djf[b] = a;
    djd[b] = cost[b];
}

int main()
{
    scanf("%lld", &N);
    for (int i=2; i<=N; ++i) scanf("%lld", &par[i]);
    for (int i=2; i<=N; ++i) scanf("%lld", &cost[i]);
    scanf("%lld", &M);
    for (int i=1; i<=M; ++i) scanf("%lld%lld", qt+i, qv+i);

    for (int i=1; i<=N; ++i) djf[i] = i;

    // merge all starting trees
    for (int i=1; i<=M; ++i) if (qt[i] == 1) startscut[qv[i]] = 1;
    for (int i=2; i<=N; ++i) if (!startscut[i])
        merge(par[i], i);

    vector<pair<ll, ll> > ans;
    for (int i=M; i; --i)
    {
        if (qt[i] == 1) merge(par[qv[i]], qv[i]);
        else ans.push_back(find(qv[i]));
    }
    for (auto it=ans.rbegin(); it!=ans.rend(); ++it)
        printf("%lld %lld\n", it->first, it->second);
}


