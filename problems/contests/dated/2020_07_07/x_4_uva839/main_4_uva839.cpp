/*
 * Problem 4_uva839 (contests/dated/2020_07_07/4_uva839)
 * Create time: Tue 07 Jul 2020 @ 14:18 (PDT)
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

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = -1;

bool check(int &w)
{
    int wl, dl, wr, dr;
    bool ok = 1;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
    if (!wl) ok &= check(wl);
    if (!wr) ok &= check(wr);
    w = wl + wr;
    return ok && wl*dl == wr*dr;
}

int main()
{
    int kase; scanf("%d", &kase);
    bool gone = 0;
    while (kase--)
    {
        int tot;
        if (gone) printf("\n");
        else gone = 1;
        if (check(tot)) printf("YES\n");
        else printf("NO\n");
    }

	return 0;
}

