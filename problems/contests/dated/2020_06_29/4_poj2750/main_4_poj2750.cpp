/*
 * Problem 4_poj2750 (contests/dated/2020_06_29/4_poj2750)
 * Create time: Fri 03 Jul 2020 @ 10:19 (PDT)
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
int N, M, arr[MX];
multiset<int> vals;
struct Node
{
    int tot;
    int max, lmax, rmax;
    int min, lmin, rmin;
    Node(v)
    {
        tot = v;
        max = lmax = rmax = v;
        min = lmin = rmin = v;
    }
} nd[MX];

void comb(int k)
{
    const Node &lc = nd[k<<1], &rc = nd[k<<1|1];
    nd[k].tot = lc.tot + rc.tot;
    nd[k].max = max(max(lc.max, rc.max), lc.rmax + rc.lmax);
    nd[k].lmax = max(lc.lmax, lc.tot + rc.lmax);
    nd[k].rmax = max(rc.rmax, rc.tot + lc.rmax);
    nd[k].min = min(min(lc.min, rc.min), lc.rmin + rc.lmin);
    nd[k].lmin = min(lc.lmin, lc.tot + rc.lmin);
    nd[k].rmin = min(rc.rmin, rc.tot + lc.rmin);
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &M);

	return 0;
}

