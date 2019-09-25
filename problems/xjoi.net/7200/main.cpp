/*
 * Problem #7200
 * struct intro
 */
#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

struct nyan
{
    int a, b;
    char cow;
}

int main ()
{
    int num;
    scanf("%d", &num);
    for (int i=0; i<num; ++i)
    {
        nyan cat;
        scanf("%d %d %c", &cat.a, &cat.b, &cat.cow);
        printf("%d %d %c\n", cat.a, cat.b, cat.cow);
    }
    
    return 0;
}
