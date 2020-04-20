/*
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (contests/dated/2020_04_20/2)
 * Create time: Mon 20 Apr 2020 @ 09:05 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#define ll long long

using namespace std;
const int MX = -1;
ll ret=0;
void dfs(int num, int pre, int k)
{
    if (k == 0 && num == 0) ++ret;
    if (k <= 0 || num <= 0) return;
    for (int i=pre; i<=num; ++i)
	dfs(num-i, i, k-1);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    dfs(n, 1, k);
    printf("%lld\n", ret);

    return 0;
}
