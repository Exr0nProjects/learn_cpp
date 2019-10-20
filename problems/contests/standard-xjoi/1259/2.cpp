/*
after contest rewrite

dearrangement, use "swap" method
dearrangement of n-1 + dearrargement of n-2
(n-1)*f(n-1)+(n-1)*f(n-2)

pie method
n!-n*(n-1)!+nC2((n-2)!)-nC3((n-3)!) etc
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;
long long sol[30];

int main()
{
    int n;
    scanf("%d", &n);

    sol[1] = 0;
    sol[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        sol[i] = sol[i - 1] * (i - 1) + sol[i - 2] * (i - 1);
    }
    printf("%lld", sol[n]);
    return 0;
}
