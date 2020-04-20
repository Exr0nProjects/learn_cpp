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

const int MX = 10111;
int N, K;
dl ropes[MX];

bool check(dl len)
{
    int n=0;
    for (int i=0; i<N; ++i)
	n += ropes[i] / len;
    return n >= K;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; ++i)
	scanf("%lf", &ropes[i]);

    dl l=0, r=1<<30;
    for (int i=0; i<40; ++i)
    {
	dl m = (l+r)/2;
	if (check(m)) l = m;
	else r = m;
    }
    printf("%.2lf\n", l);

    return 0;
}
