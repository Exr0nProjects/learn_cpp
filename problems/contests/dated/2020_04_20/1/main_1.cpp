/*
TASK: 1
LANG: C++14
*/

/*
 * Problem 1 (contests/dated/2020_04_20/1)
 * Create time: Mon 20 Apr 2020 @ 10:50 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cmath>
#define ll long long

ll N, ret=0;
void dfs(int rem, int lay=0)
{
    if (lay == 4)
    {
	if (rem == 0) ++ret;
	return;
    }
    for (ll i=0; i<=(ll)sqrt(rem); ++i)
    {
	dfs(rem-i*i, lay+1);
    }
}

int main()
{
    scanf("%lld", &N);
    dfs(N);
    printf("%lld\n", ret);

    return 0;
}
