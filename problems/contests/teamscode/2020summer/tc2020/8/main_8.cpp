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
char me[MXL], you[MXL];

int main()
{
    scanf("%d", &N);
    for (int i=0; i<=N; ++i) scanf("%d", &len[i]); getchar();
    for (int i=0; i<len[0]; ++i) cin >> me[i];

    int tot=0;
    for (int i=1; i<=N; ++i)
    {
        for (int j=0; j<len[i]; ++j) cin >> you[j]; // FIX: use alexc input, not cin.getline()
        you[len[i]] = 0;
        int mx=0;
        for (int s=-26; s<=26; ++s)
        {   // -11 vs -12
            int cnt=0;
            for (int j=0; j<len[i]; ++j)
                if (j+s >= 0 && j+s < len[0] && me[j+s] == you[j])
                    ++cnt;
            mx = max(mx, cnt);
            //printf("shift for %d, %d: %d\n", i, s, cnt);
        }
        tot += mx;
    }
    printf("%d\n", tot);

	return 0;
}

