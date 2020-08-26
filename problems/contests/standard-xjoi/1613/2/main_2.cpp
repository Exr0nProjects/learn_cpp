/*
 * Problem 2 (contests/standard-xjoi/1613/2)
 * Create time: Tue 25 Aug 2020 @ 17:19 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <set>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <chrono>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 2e5+10;

int N, M, a[MX<<1], djs[MX<<1], djf[MX<<1];

int find(int n)
{
    while (djf[n] != n)
        n = djf[n];
    return n;
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
}

int main()
{
    for (int i=1; i<MX<<1; ++i)
        djs[i] = 1, djf[i] = i;

    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(v, u+MX); // merge v with the group that admires u
    }

    int cnt=0;
    for (int i=1; i<=N; ++i)
    {
        if (!a[find(i)]) a[find(i)] = ++cnt;
        printf("%d\n", a[find(i)]);
    }

	return 0;
}

