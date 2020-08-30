/*
 * Problem book_shop_down (cses/dp/book_shop_down)
 * Create time: Sat 29 Aug 2020 @ 17:56 (PDT)
 * Accept time: Sat 29 Aug 2020 @ 18:43 (PDT)
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
const ll MX = 1e3+11;
const int MXV = 1e5+11;

int N, X, v[MX], w[MX], dp[MX][MXV];

int kdp(int i, int j)
{
    if (j < 0) return -1e8; // FIX: logic--this line before below because negative is worse than zero
    if (i == 0) return 0;
    int &ret = dp[i][j];
    if (ret) return ret;
    ret = max(kdp(i-1, j), kdp(i-1, j-w[i])+v[i]);
    return ret;
}

int main()
{
    scanf("%d%d", &N, &X);
    for (int i=1; i<=N; ++i) scanf("%d", w+i);
    for (int i=1; i<=N; ++i) scanf("%d", v+i);

    //int mx = 0;
    //for (int i=0; i<=X; ++i) mx = max(mx, kdp(N, i));
    //printf("%d\n", mx);
    printf("%d\n", kdp(N, X));

	return 0;
}

