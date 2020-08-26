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

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 3e5;

int N, M, a[MX], djf[MX];
int has[MX];

int find(int n)
{
    while (djf[n] != n)
        n = djf[n];
    return n;
}
void merge(int a, int b)
{
    if (!a || !b) return;
    a = find(a);
    b = find(b);
    if (a == b) return;
    djf[a] = b;
    merge(has[a], has[b]);
}

int main()
{
    for (int i=1; i<MX; ++i)
        //djs[i] = 1,
        djf[i] = i;

    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(v, has[u]);           // merge `v` with the group that admires `u`
        if (!has[u]) has[u] = v;
    }

    int cnt=0;
    for (int i=1; i<=N; ++i)
    {
        if (!a[find(i)]) a[find(i)] = ++cnt;
        printf("%d\n", a[find(i)]);
    }

	return 0;
}

