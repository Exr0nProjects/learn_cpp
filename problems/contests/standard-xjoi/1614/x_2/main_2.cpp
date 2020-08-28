/*
 * Problem 2 (contests/standard-xjoi/1614/2)
 * Create time: Fri 28 Aug 2020 @ 16:07 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+10;
const int MOD = 1e9 + 7;

int N, tot=0, xp[MX], dlt[MX<<1], src[MX];  // FIX: bounds-- MX<<1 because its 2*N

int main()
{
    freopen("help.in", "r", stdin);
    freopen("help.out", "w+", stdout);
    scanf("%d", &N);
    xp[0] = 1;
    for (int i=1; i<=N; ++i) xp[i] = (xp[i-1]<<1) % MOD;
    for (int i=1; i<=N; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ++dlt[l], --dlt[r+1];
        src[i] = l;
    }
    for (int i=1; i<MX<<1; ++i) dlt[i] += dlt[i-1]; // FIX: boundchange-- MX<<1 because its 2*N
    for (int i=1; i<=N; ++i)
        tot = (tot + xp[N-dlt[src[i]]]) % MOD;
    printf("%d\n", tot);
	return 0;
}

