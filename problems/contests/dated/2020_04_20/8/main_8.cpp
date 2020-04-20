/*
TASK: 8
LANG: C++14
*/

/*
 * Problem 8 (contests/dated/2020_04_20/8)
 * Create time: Mon 20 Apr 2020 @ 09:51 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#define dl double
#define ll long long

const int MX = 10111;
ll N, K;
ll ropes[MX];

bool check(ll len)
{
    ll n=0;
    for (int i=0; i<N; ++i)
	n += ropes[i] / len;
    return n >= K;
}

int main()
{
    scanf("%d%d", &N, &K);
    dl len;
    for (int i=0; i<N; ++i)
    {
	scanf("%lf", &len);
	ropes[i] = len*1000;
    }

    ll l=0, r=1<<30;
    for (int i=0; i<80; ++i)
    {
	ll m = (l+r)/2;
	if (check(m)) l = m;
	else r = m;
    }
    printf("%.2lf\n", (dl)l/1000);

    return 0;
}
