/*
 * Problem 12 (tcp2020b/12)
 * Create time: Wed 22 Jul 2020 @ 19:24 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const int MX = 100111;

int N, M, locs[MX];

bool check(int d)
{
    int last=locs[0], togo = M-1;
    for (int i=1; i<N; ++i)
        if (last + d <= locs[i])
            last=locs[i], --togo;
    return togo <= 0;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i) scanf("%d", &locs[i]);
    sort(locs, locs+N);

    int l=0, r=1<<30;
    while (l+1 < r)
    {
        int mid = l + (r-l>>1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", l);

	return 0;
}

