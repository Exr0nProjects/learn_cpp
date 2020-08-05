/*
 * Problem 10618down (uva/10618down)
 * Create time: Wed 05 Aug 2020 @ 12:43 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 100;
char inp[MX];
// 0 = up, 1 = right, 2 = left, 3 = down
int N, dp[MX][4][4][3]; // time, left pos, right pos, previous move (0 = none, 1 = left, 2 = right)

void solve(int i, int l, int r, int p)
{
    int &ans = dp[i][l][r][p];
    if (ans < 1e8) return ans;

    if (!p) ans = min(ans, dp[i-1][l][r][0, 1, 2]);    // do nothing
    ans = min(ans, min(dp[i-1][1][r][p])          // uncross
    {   // move left foot
    }
}

int main()
{

	return 0;
}

