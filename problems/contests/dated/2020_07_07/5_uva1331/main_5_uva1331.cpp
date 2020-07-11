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
pair<dl, dl> pts[MX];

inline dl dist(int i, int j)
{
    //printf("%d^2 + %d^2\n", pts[i].f-pts[j].f, pts[i].s-pts[j].s);
    return sqrt(pow(pts[i].f-pts[j].f, 2) + pow(pts[i].s-pts[j].s, 2));
}
inline dl size(int i, int j, int k)
{
    //printf("i(%d) = %d, %d\n", i, pts[i].f, pts[i].s);
    //printf("j(%d) = %d, %d\n", j, pts[j].f, pts[j].s);
    //printf("k(%d) = %d, %d\n", k, pts[k].f, pts[k].s);
    dl a = dist(i, j);
    dl b = dist(j, k);
    dl c = dist(i, k);
    //printf("ij %7lf jk %7lf ik %7lf\n", a, b, c);
    dl s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

inline bool isleft(int i, int j, int k)
{
    if (pts[i].f == pts[j].f) return pts[k].f <= pts[i].f;
    //if (pts[i].f > pts[j].f) swap(i, j);  // FIX: forgot to comment this out smah
    //if (pts[j].f == pts[k].f) return pts[k].s >= pts[j].s;
    dl m = (dl)(pts[i].s-pts[j].s)/(pts[i].f-pts[j].f);
    dl pos = m*(pts[k].f-pts[i].f)+pts[i].s;
    //printf("m = %lf, h = %lf k = %lf\n", m, pts[i].f, pts[i].s);
    //printf("pos at %d: %lf = %lf\n", k, pts[k].f, pos);
    //printf("i.f %lf j.f %lf\n", pts[i].f, pts[j].f);
    if (pts[i].f < pts[j].f) return pts[k].s >= pos;
    else return pts[k].s <= pos;
}
inline bool contains(int i, int j, int k)
{
    printf("i %d j %d k %d\n", i, j, k);
    for (int p=0; p<N; ++p)
        if (p!=i && p!=j && p!=k)
        {
            printf("p = %d: %d %d %d\n", p, isleft(i, j, p), isleft(j, k, p), isleft(k, i, p));
            bool ij = isleft(i, j, p);
            if (ij == isleft(k, i, p) && ij == isleft(j, k, p))
                return true;
        }
    return false;
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
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
            scanf("%lf%lf", &pts[i].f, &pts[i].s);
        while (true)
        {
            int i, j, k; scanf("%d%d%d", &i, &j, &k);
            printf("does it contain? %d\n", contains(i, j, k));
        }
        //N = 3;
        //for (int i=0; i<N; ++i)
        //    scanf("%lf%lf", &pts[i].f, &pts[i].s);
        //printf("is %2lf %2lf left of %2lf %2lf -> %2lf %2lf ?      %d\n", pts[2].f, pts[2].s,
        //        pts[0].f, pts[0].s, pts[1].f, pts[1].s, isleft(0, 1, 2));
        //printf("best: %lf\n", dp(0, N-1));
        //printf("area: %lf\n", size(0, 1, 2));
    }

	return 0;
}

