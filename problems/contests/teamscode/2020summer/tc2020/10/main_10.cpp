/*
 * Problem 10 (tc2020/10)
 * Create time: Sat 25 Jul 2020 @ 15:45 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

#define ll long long
#define dl double

using namespace std;
const ll MX = -1;

int mxpts(int sh, int wo, int br, int ore, int wh)
{
    wo +=2, br+=2; // extra two roads
    int hardmax = min(min(wh, sh), min(wo/3, br/3));
    wh -= hardmax; // remaining wheat to build cities with
    return hardmax + min(hardmax, min(ore/3, wh/2));
}

int main()
{
    int sh, wo, br, ore, wh;
    scanf("%d%d%d%d%d", &sh, &wo, &br, &ore, &wh);

    printf("%d\n", max(mxpts(sh, wo, br, ore, wh),
            mxpts(sh-3, wo, br, ore-3, wh-3)+2));

	return 0;
}

