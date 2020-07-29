/*
 * Problem 8 (contests/teamscode/2020summer/tc2020/8)
 * Create time: Wed 29 Jul 2020 @ 12:40 (PDT)
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
const int MX = 10111;
const int MXL = 30<<1;

int N, len[MX];
char sched[MX][MXL];

int main()
{
    scanf("%d", &N);
    for (int i=0; i<=N; ++i) scanf("%d", &len[i]); getchar();
    for (int i=0; i<=N; ++i) cin.getline(sched[i], MXL);
    for (int i=0; i<=N; ++i)
        for (int j=1; j<len[i]; ++j)
            sched[i][j] = sched[i][j<<1];

    int tot=0;
    for (int i=1; i<=N; ++i)
    {
        int mx=0;
        for (int s=-26; s<=26; ++s)
        {
            int cnt=0;
            for (int j=0; j<len[i]; ++j)
                if (j+s >= 0 && j+s < len[0] && sched[0][j+s] == sched[i][j])
                    ++cnt;
                //if (j+s+1 >= 0 && j+s+1 < len[i]
                //        && sched[0][j] == sched[i][j+s]
                //        && sched[0][j+1] == sched[i][j+s+1])
                //    cnt += 1 + (j != pre), pre = j+1;
            mx = max(mx, cnt);
            //printf("shift for %d, %d: %d\n", i, s, cnt);
        }
        tot += mx;
    }
    printf("%d\n", tot);

	return 0;
}

