/*
 * Problem 5_uva1331 (contests/dated/2020_07_07/5_uva1331)
 * Create time: Sat 11 Jul 2020 @ 10:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 61;
int N, tab[MX][MX];
pair<int, int> pts[MX];

inline dl dist(int i, int j)
{
    return sqrt(pow(pts[i].f-pts[j].f, 2) + pow(pts[i].s-pts[j].s, 2));
}

inline dl size(int i, int j, int k)
{
    printf("i(%d) = %d, %d\n", i, pts[i].f, pts[i].s);
    printf("j(%d) = %d, %d\n", j, pts[j].f, pts[j].s);
    printf("k(%d) = %d, %d\n", k, pts[k].f, pts[k].s);
    dl a = dist(i, j);
    dl b = dist(j, k);
    dl c = dist(i, k);
    printf("ij %7lf jk %7lf ik %7lf\n", a, b, c);
    dl s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

dl dp(int i, int j)
{
    if (i+1 == j) return 0;
    if (tab[i][j]) return tab[i][j];
    dl mn = 1<<30;
    for (int k=i+1; k<j; ++k)
        mn = min(mn, max(size(i, k, j), max(dp(i, k), dp(k, j))));
    tab[i][j] = mn;
    return mn;
}

int main()
{
    while (true)
    {
        memset(tab, 0, sizeof tab);
        for (int i=0; i<MX; ++i) pts[i] = {};
        N = 3;
        for (int i=0; i<N; ++i)
            scanf("%d%d", &pts[i].f, &pts[i].s);
        printf("area: %lf\n", size(0, 1, 2));
    }

	return 0;
}

