/*
 * Problem 2 (contests/standard-xjoi/2)
 * Create time: Sat 22 Aug 2020 @ 21:20 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 111;
int N, s[MX], f[MX], dp[MX][MX*1000][MX*1000];

int kdp(int i, int ss, int sf)
{
    if (i == 0 || ss < 0 || sf < 0) return 0;
    int &ret = dp[i][ss][sf];
    if (ret) return ret;
    ret = max(kdp(i-1, ss, sf), kdp(i-1, ss+s[i], sf+f[i])+s[i]+f[i]);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d%d", &s[i], &f[i]);


    for (int i=1; i<=
    printf("%d\n", kdp(N, );

	return 0;
}

