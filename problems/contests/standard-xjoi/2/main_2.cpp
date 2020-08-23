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
int N, s[MX], f[MX], dp=0;

int main()
{
    // TODO: why is the sample test case 8?
    // TODO: so scuffed, can't declare dp as its own int, can't have dp is negative, or long long?
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d%d", &s[i], &f[i]);
    for (int i=1; i<=N; ++i) dp = max(dp, dp+s[i]+f[i]);
    printf("%d\n", dp);

	return 0;
}

