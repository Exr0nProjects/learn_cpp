/*
 * Problem 1_union-find (contests/standard-xjoi/1543/1_union-find)
 * Create time: Sat 01 Aug 2020 @ 15:04 (PDT)
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
const ll MX = 10111;

int djs[MX], djf[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
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
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0; i<=N; ++i)
        djs[i] = 1, djf[i] = i;
    for (int i=0; i<M; ++i)
    {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if (c == 1) merge(a, b);
        else printf("%c\n", find(a) == find(b) ? 'Y' : 'N');
    }

	return 0;
}

