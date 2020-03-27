/*
TASK: split
LANG: C++14
*/

/*
 * Problem split (usaco/gold/2016open/split)
 * Create time: Fri 27 Mar 2020 @ 10:36 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "split");

using namespace std;
const int MX = 50111;
int N, hipre[MX], hipost[MX], lopre[MX], lopost[MX];
vector<pair<int, int> > cows;

ll solve()
{
    // prefix sums
    memset(hipre, 0, sizeof(hipre)); hipre[0] = cows[0].S;
    memset(hipost, 0, sizeof(hipost)); hipost[N-1] = cows[N-1].S;
    memset(lopre, 0x40, sizeof(lopre)); lopre[0] = cows[0].S;
    memset(lopost, 0x40, sizeof(lopost)); lopost[N-1] = cows[N-1].S;
    FOR_(i, 1, N)
    {
        hipre[i] = max(hipre[i-1], cows[i].S);
        lopre[i] = min(lopre[i-1], cows[i].S);
    }
    FORR(i, N-1)
    {
        hipost[i] = max(hipost[i+1], cows[i].S);
        lopost[i] = min(lopost[i+1], cows[i].S);
    }
    // printf("hipre"); FOR(i, N) printf("%3d", hipre[i]); printf("\n");
    // printf("hipost"); FOR(i, N) printf("%3d", hipost[i]); printf("\n");
    // printf("lopre"); FOR(i, N) printf("%3d", lopre[i]); printf("\n");
    // printf("lopost"); FOR(i, N) printf("%3d", lopost[i]); printf("\n");

    // sweep
    ll ret=(ll)1<<60;
    FOR(i, N-1)
    {
        ret = min(ret, (ll)(cows[i  ].F-cows[0  ].F)*(ll)(hipre[i  ] -lopre[i  ] )
                     + (ll)(cows[N-1].F-cows[i+1].F)*(ll)(hipost[i+1]-lopost[i+1]));
        // printf("%3d\n", ret);
    }

    return ret;
}

int main()
{
    setIO();
    scanf("%d", &N);
    cows.reserve(N);
    int hix=0, hiy=0, lox=1<<30, loy=1<<30;
    FOR(i, N)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        cows.eb(x, y);
        hix = max(hix, x);
        lox = min(lox, x);
        hiy = max(hiy, y);
        loy = min(loy, y);
    }

    ll ret = (ll)1<<60;

    sort(cows.begin(), cows.end());
    ret = min(ret, solve());

    FOR(i, N) swap(cows[i].F, cows[i].S);
    sort(cows.begin(), cows.end());
    ret = min(ret, solve());

    printf("%lld\n", (ll)(hix-lox)*(ll)(hiy-loy) - ret);

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
