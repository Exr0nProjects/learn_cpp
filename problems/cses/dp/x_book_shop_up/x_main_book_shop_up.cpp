/*
 * Problem book_shop_up (cses/dp/book_shop_up)
 * Create time: Sat 29 Aug 2020 @ 17:52 (PDT)
 * Accept time: Sat 29 Aug 2020 @ 17:56 (PDT)
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
const int MXV = 1e5+10;

int N, X, v[MX], w[MX], dp[MXV];

int main()
{
    scanf("%d%d", &N, &X);
    for (int i=1; i<=N; ++i) scanf("%d", w+i);
    for (int i=1; i<=N; ++i) scanf("%d", v+i);

    for (int i=1; i<=N; ++i)
        for (int j=X; j>=w[i]; --j)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);

    int mx = 0;
    for (int i=0; i<=X; ++i) mx = max(mx, dp[i]);
    printf("%d\n", mx);

	return 0;
}

