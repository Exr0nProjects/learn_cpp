/*
 * Problem 4_parity_game (contests/standard-xjoi/1543/4_parity_game)
 * Create time: Sat 01 Aug 2020 @ 16:25 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = -1;

int N, M;
unordered_map<int, int> djf;
unordered_map<int, list<pair<bool, int> > > adj;  // < weight, target >
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    djf[b] = a;
}

int dfs(int cur, int tar, int pre=0, int sum=0)
{
    if (cur == tar) return sum;
    for (auto e : adj[cur])
        if (e.s != pre)
            dfs(e.s, tar, cur, sum+e.f);
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    for (i=0; i<M; ++i)
    {
        int u, v, w=1; string s;
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        ++v;
        cin >> s;
        if (s[0] == 'e') w = 0;


        //printf("got %d %d %d\n", u, v, w);
        if (!djf.count(u)) djf[u] = u; // FIX: INIT DJS
        if (!djf.count(v)) djf[v] = v;

        if (find(u) != find(v)) // legal, nothing has locked this yet
        {
            //printf("not locked!\n");
            merge(u, v);
            adj[u].pb(mp(w, v));
            adj[v].pb(mp(w, u));
        }
        else if (dfs(u, v)%2 != w)
            break;
    }
    printf("%d\n", i);

	return 0;
}

