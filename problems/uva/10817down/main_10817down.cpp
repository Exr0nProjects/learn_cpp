/*
 * Problem 10817down (uva/10817down)
 * Create time: Wed 22 Jul 2020 @ 15:27 (PDT)
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
const int MX = 150;
const int MXS = 8;

string print(int x)
{
    string ret = "";
    for (int i=20; i>=0; --i)
        ret += x&(1<<i) ? '1' : '.';
    return ret;
}

int S, M, N, cost[MX], sub[MX], dp[MX][1<<MXS][1<<MXS];
int op(int cur, array<int, 3> stat)
{
    if (dp[cur][stat[1]][stat[2]]) return dp[cur][stat[1]][stat[2]];
    if (cur > N+M) return stat[2] == (1<<MXS)-1 ? 0 : 1<<25;
    int ret = 1<<25;
    if (cur > M) ret = op(cur+1, stat);     // don't hire this teacher
    int flip=0;
    for (int i=0; i<3; ++i) printf("%s\n", print(stat[i]).c_str());
    for (int i=0; i<3; ++i)
    {
        if (i < 2) flip ^= stat[i] & sub[cur];
        stat[i] ^= flip;
        if (i) flip ^= stat[i-1] & sub[cur];
    }
}

int main()
{
    while (~scanf("%d%d%d", &S, &M, &N) && S)
    {
        memset(dp, 0, sizeof dp);
        getchar();
        for (int i=1; i<=M+N; ++i)
        {
            string ln;
            getline(cin, ln);
            stringstream ss(ln);
            ss >> cost[i];
            for (int x; ss >> x;) sub[i] |= 1<<x-1;
            printf("%d: %s\n", i, print(sub[i]).c_str());
        }
    }

	return 0;
}

