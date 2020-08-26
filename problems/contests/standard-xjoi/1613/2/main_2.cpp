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
const ll MX = 3e5;

int N, M, a[MX<<1], /*djs[MX<<1],*/ djf[MX<<1];
int has[MX<<1];

int find(int n)
{
    while (djf[n] != n)
        n = djf[n];
    return n;
}
void merge(int a, int b)
{
    printf("merge %6d and %6d", a, b);
    int _a = find(a);
    b = find(b);
    if (!_a || !b || !(_a-MX) || !(b-MX)) { printf(" is redundant!\n", a, b, a, has[b]); return; }
    if (_a == b) { printf(" is redundant!\n", a, b, a, has[b]); return; }
    //if (djs[a] < djs[b]) swap(a, b);
    //djs[a] += djs[b];
    djf[_a] = b;
    printf(" aka %6d and %6d, now merging %d* and %d*\n", _a, b, a, has[b]);
    //if (a < MX) {
    //    merge(a+MX, has[b]+MX);
    //    if (b > MX) has[b] = a;
    //    printf("      has %d = %d\n", b, a);
    //} else
    merge(has[a]+MX, has[b]+MX);
    if (a < MX && b > MX) has[b] = a;
}

int main()
{
    for (int i=1; i<MX<<1; ++i)
        //djs[i] = 1,
        djf[i] = i;
    for (int i=1; i<MX; ++i)
        has[i] = i;

    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(v, u+MX); // merge `v` with the group that admires `u`
        printf("\n");
    }

    int cnt=0;
    for (int i=1; i<=N; ++i)
    {
        if (!a[find(i)]) a[find(i)] = ++cnt;
        printf("%d\n", a[find(i)]);
    }

	return 0;
}

