/*
 * Problem 1_hdu3183 (contests/dated/2020_06_26/1_hdu3183)
 * Create time: Mon 29 Jun 2020 @ 21:54 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
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

using namespace std;
const ll MX = 1011;
ll N, M;
char buf[MX];
bool del[MX];

int main()
{
    bool isfirst = 1;
    while (~scanf("%1010s%lld", buf, &M))       // FIX: don't use scanf %n cuz its baaaaad
    {
        memset(del, 0, sizeof del);
        N = strlen(buf);
        for (ll i=0; i<N; ++i)
            if (buf[i+1] < buf[i])
                for (ll j=i; j>=0 && M; --j)    // FIX: equ--don't stop if del[j], since might be at very end and have extra to delete
                {
                    if (buf[j] <= buf[i+1])     // FIX: equ--break backtracking even if le not lt, cuz multiple of same num is ok
                        break;
                    if (!del[j]) --M;
                    del[j] = 1;
                }

        bool gone=0;
        for (ll i=0; i<N; ++i)
            if (!del[i] && (gone || buf[i] > '0'))
            {
                putchar(buf[i]);
                gone=1;
            }
        if (!gone) putchar('0');
        putchar('\n');
    }

	return 0;
}

