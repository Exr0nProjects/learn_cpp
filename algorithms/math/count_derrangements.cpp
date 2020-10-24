#include <cstdio>

#define ll long long

const int MX = 1e6+10;

ll ans[MX];
ll num(ll n)
{
    ans[2] = 1;
    for (int i=3; i<=n; ++i)
        // say we want to assign P1 to a chair.
        // because P1 sits in a chair Ck, then the person in Ck must sit somewhere
        // the person Pk who was in Ck either sits in C1 or doesn't:
        // if Pk sits in C1, then both P1 and Pk are occupied and both C1 and Ck are as well.
        //  so this case is equivilant to f(n-2).
        // else, Pk doesn't sit in C1. Then, Pk sits somewhere and C1 needs a person,
        //  but Pk can't sit in C1. this is the same as combining Pk/Ck and P1/C1, so
        //  it's the same as the case for f(n-1)
        // so our recursive formula is f(n) = (n-1)*(f(n-1)+f(n-2))
        ans[i] = (i-1)*(ans[i-1]+ans[i-2]);
    return ans[n];
}

int main()
{
    int n; scanf("%d", &n);
    printf("%d\n", num(n));
}

