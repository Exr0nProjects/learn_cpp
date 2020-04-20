/*
TASK: 7brute
LANG: C++14
*/

/*
 * Problem 7brute (contests/dated/2020_04_20/7brute)
 * Create time: Mon 20 Apr 2020 @ 11:15 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
const int MX = 500111;
int N, height[MX];
bool tab[MX][MX];

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
	scanf("%d", &height[i]);

    for (int i=0; i<N; ++i) tab[i][i+1] = 1;
    for (int i=0; i<N; ++i)
	for (int j=i+2; j<N; ++j)
	    if (tab[i][j-1] && height[j-1] <= min(height[j], height[i]))
		tab[i][j] = 1;

    ll ret=0;
    for (int i=0; i<N; ++i)
	for (int j=i+1; j<N; ++j)
	    if (tab[i][j])
		++ret;

    printf("%lld\n", ret);

    return 0;
}
