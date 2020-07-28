/*
 * Problem 13 (contests/teamscode/2020summer/tc2020/13)
 * Create time: Tue 28 Jul 2020 @ 11:12 (PDT)
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
const ll MX = 40;

int N, T, si, sj, tot=0;
char grid[MX][MX];

void dfs(int i, int j, int r=T)
{
    printf("    i %d j %d -> '%c'  r %d\n", i, j, grid[i][j], r);
    if (grid[i][j] != '*') return;
    grid[i][j] = 'X';
    if (!~r) { printf("got %d %d\n", i, j); ++tot; }    // FIX: move until -1 not move until 0
    else
    {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int d=0; d<4; ++d)
            dfs(i+dy[d], j+dx[d], r-1);
    }
}

int main()
{
    memset(grid, '#', sizeof grid);
    scanf("%d%d", &N, &T);
    for (int i=1; i<=N; ++i)
    {
        getchar();
        for (int j=1; j<=N; ++j)
        {
            grid[i][j] = getchar();
            if (grid[i][j] == 'Z')
                si = i, sj = j, grid[i][j] = '*';   // FIX: set start pos to legit
        }
    }

    //for (int i=0; i<=1+N; ++i) { for (int j=0; j<=1+N; ++j) printf("%c", grid[i][j]); printf("\n"); }
    queue<pair<int, pair<int, int>> > q;
    q.push(mp(T+1, mp(si, sj)));
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        //printf("    i %d j %d -> '%c'  r %d\n", cur.s.f, cur.s.s, grid[cur.s.f][cur.s.s], cur.f);
        if (grid[cur.s.f][cur.s.s] != '*') continue;
        grid[cur.s.f][cur.s.s] = '#';
        if (cur.f == 0) ++tot;
        else
        {
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int d=0; d<4; ++d)
                q.push(mp(cur.f - 1, mp(cur.s.f + dy[d], cur.s.s + dx[d])));
        }
    }

    //for (int i=0; i<=1+N; ++i) { for (int j=0; j<=1+N; ++j) printf("%c", grid[i][j]); printf("\n"); }
    printf("%d\n", tot);

	return 0;
}

