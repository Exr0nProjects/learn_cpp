/*
 * Problem 5_uva1331 (contests/dated/2020_07_07/5_uva1331)
 * Create time: Sat 11 Jul 2020 @ 10:26 (PDT)
 * Accept time: Sat 11 Jul 2020 @ 20:19 (PDT)
 *  NOTE: this problem passes even though it sometimes creates illegal chords
 *      because it checks whether a triangle of chords is legal by checking
 *      if any verticies lie within the triangle
 *      However, you can still have countercases to that (edges of triangle
 *      intersect with another edge of polygon) even if there are no vertecies
 *      inside the triangle. One way is to precompute all legal pairs to draw
 *      chords between in N^3, by checking that all verticies on either side
 *      have the same is_left, thus no line can cross the chord.
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
int N;
dl tab[MX][MX]; // FIX: this should be dl smah
pair<dl, dl> pts[MX];

inline dl dist(int i, int j)
{
    return sqrt(pow(pts[i].f-pts[j].f, 2) + pow(pts[i].s-pts[j].s, 2));
}
inline dl size(int i, int j, int k)
{
    dl a = dist(i, j);
    dl b = dist(j, k);
    dl c = dist(i, k);
    dl s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

inline bool isleft(int i, int j, int k)
{
    if (pts[i].f == pts[j].f) return pts[k].f == pts[i].f   // when i->j vertical, yes if on the line
        || (pts[k].f < pts[i].f) == (pts[i].s < pts[j].s);  // FIX: else depends on direction
    //if (pts[i].f > pts[j].f) swap(i, j);  // FIX: forgot to comment this out smah
    dl m = (dl)(pts[i].s-pts[j].s)/(pts[i].f-pts[j].f);
    dl pos = m*(pts[k].f-pts[i].f)+pts[i].s;
    if (pts[i].f < pts[j].f) return pts[k].s >= pos;
    else return pts[k].s <= pos;
}
inline bool contains(int i, int j, int k)
{
    for (int p=0; p<N; ++p)
        if (p!=i && p!=j && p!=k)
        {
            bool ij = isleft(i, j, p);
            if (ij == isleft(k, i, p) && ij == isleft(j, k, p))
                return true;
        }
    return false;
}

dl dp(int i, int j, int lay=1)
{
    if (i+1 == j) return 0;
    if (tab[i][j]) return tab[i][j];
    dl mn = 1<<30;
    for (int k=i+1; k<j; ++k)
        if (!contains(i, j, k))
        {
            dl ik = dp(i, k, lay+1);
            dl kj = dp(k, j, lay+1);
            mn = min(mn, max(size(i, k, j), max(ik, kj)));
        }
    tab[i][j] = mn;
    return mn;
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        memset(tab, 0, sizeof tab);
        for (int i=0; i<MX; ++i) pts[i] = {};
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
            scanf("%lf%lf", &pts[i].f, &pts[i].s);

        printf("%.1lf\n", dp(0, N-1));
    }

	return 0;
}

