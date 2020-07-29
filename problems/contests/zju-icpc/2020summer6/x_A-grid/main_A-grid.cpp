/*
 * Problem A-grid (contests/zju-icpc/2020summer6/A-grid)
 * Create time: Wed 29 Jul 2020 @ 13:53 (PDT)
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
const ll MX = 2011;
int N, M, grid[MX][MX];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            grid[(j+i)%N][j] = i*N+j+1;

    printf("%d\n", (N-M)*N); // math, proof is by magic
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

	return 0;
}

