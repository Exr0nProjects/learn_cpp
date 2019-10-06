/*
what the teacher said
6 oct 2019
f4(n) = min[f4(k)*2+f3(n-k) for k in [0:n]]
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;

int three(cn n)
{
    return 1<<n -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", three(n));
}