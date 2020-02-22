/*
ID: spoytie2
TASK: rental
LANG: C++14
*/

/*
 * Problem rental ([!meta:srcpath!])
 * Create time: Fri 21 Feb 2020 @ 18:37 (PST)
 * Accept time: Fri 21 Feb 2020 @ 20:07 (PST)
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
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "rental");

using namespace std;
const int MX = 1000010;
int N, M, R;
int production[MX], rental[MX];
vii shops;
ll milk_profit[MX]; // profit if we use the i cows for milk/rent

int main()
{
    setIO();
    scanf("%d%d%d", &N, &M, &R);
    FOR(i, N) scanf("%d", &production[i]);
    FOR(i, M) { int a, p; scanf("%d%d", &a, &p); shops.emplace_back(p, a); }
    FOR(i, R) scanf("%d", &rental[i]);

    sort(production, production+N, greater<int>{});
    sort(shops.begin(), shops.end(), greater<pair<int, int> >{}); // FIX: sort shops in increasing order

    //printf("production: "); FOR(i, N) printf("%3d", production[i]); printf("\n");
    //printf("shops:\n"); FOR(i, M) printf("    buy %d at %d\n", shops[i].S, shops[i].F);

    int shop_idx=0;
    FOR(i, N) // calculate milk profit
    {
        milk_profit[i+1] = milk_profit[i]; // dp
        while (shop_idx < M && production[i] >0)
        {
            ll sold = min(shops[shop_idx].S, production[i]);
            milk_profit[i+1] += sold*shops[shop_idx].F; // milk_profit[i+1] because milk_profit[0] is the profit if we keep the 0 best cows which is zero
            shops[shop_idx].S -= sold;
            production[i] -= sold;
            if (shops[shop_idx].S == 0) ++shop_idx;
        }
    }

    sort(rental, rental+R, greater<int>{});
    ll rent_profit=0, rent_idx=0;
    FORR(i, N)
    {
        if (N-i-1 >= R) break;
        rent_profit += rental[N-i-1];
        //printf("%d = rent: %d + milk: %d\n", milk_profit[i]+rent_profit, rent_profit, milk_profit[i]);
        milk_profit[i] += rent_profit;
        ++rent_idx;
    }
    //ll rent_profit=0, ret=0;
    //FOR(i, R) // caluculate rent profit
    //{
        //rent_profit[i+1] = rent_profit[i] + rental[i]; // FIX: add rental[i] not rental[i+1], because otherwise rental[0] isn't even considered
    //}

    ll ret=0;
    FOR(i, N+1) // FIX: fencepost, dp actually goes one further
    {
        //printf("%d = %d + %d\n", milk_profit[i] + rent_profit[N-i], milk_profit[i], rent_profit[N-i]);
        ret = max(ret, milk_profit[i]);
    }
    printf("%lld\n", ret);

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
