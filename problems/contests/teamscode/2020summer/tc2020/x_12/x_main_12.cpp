/*
 * Problem 12 (contests/teamscode/2020summer/tc2020/12)
 * Create time: Tue 28 Jul 2020 @ 11:07 (PDT)
 * Accept time: Wed 29 Jul 2020 @ 10:14 (PDT)
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
int N, C, grid[MX][MX];

int main()
{
    scanf("%d%d", &N, &C);
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
        {
            grid[i][j] = -1e8;
            grid[0][0] = 0;
            if (i) grid[i][j] = max(grid[i][j], grid[i-1][j]);
            if (j) grid[i][j] = max(grid[i][j], grid[i][j-1]);
            int d; scanf("%d", &d); grid[i][j] += d;
        }

    printf("%d\n", grid[N-1][N-1] + C);

	return 0;
}

