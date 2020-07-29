/*
 * Problem 14 (contests/teamscode/2020summer/tc2020/14)
 * Create time: Tue 28 Jul 2020 @ 11:42 (PDT)
 * Accept time: Wed 29 Jul 2020 @ 10:16 (PDT)
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
const ll MX = 1e7+10;
const ll MXL = 1e5+10;

bool siv[MX];
int pri[MX], pcnt=0;
void sieve()
{
    siv[0] = siv[1] = 1;
    for (int i=2; i<MX; ++i)
    {
        if (!siv[i]) pri[pcnt++] = i;
        for (int j=0; i*pri[j] < MX && j<pcnt; ++j)
        {
            siv[i*pri[j]] = i;
            if (i%pri[j] == 0) break;
        }
    }
}

int N, dp[MXL]; // dp[i] = min partitions for first i chars
char str[MXL];

bool isprime(int l, int r)
{   // TODO: could optimize by combining with call site, avoid re-adding previous chars
    // (add multiples of pows of 10 directly)
    int tot=0;
    if (r - l > 6) return 0;
    for (int i=l; i<=r; ++i)
        tot = (tot + str[i]-'0')*10;
    //printf("tot %d\n", tot/10);
    return !siv[tot/10];
}

int main()
{
    sieve();
    scanf("%s", str);
    N = strlen(str);

    //dp[0] = 0;
    for (int i=1; i<=N; ++i)
    {
        dp[i] = 1e8;
        for (int ln=1; ln<=7 && ~(i-ln); ++ln)
            if (isprime(i-ln, i-1)) // FIX: i-ln < i-1 so i-ln should be left, not right
                dp[i] = min(dp[i], dp[i-ln]+1);
        //printf("%3d", dp[i]);
    }
    if (dp[N] > 1e7) printf("-1\n");
    else printf("%d\n", dp[N]);

	return 0;
}

