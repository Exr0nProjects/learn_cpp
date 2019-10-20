/*
clumsy dancers
after-contest solution

if a, c are male and b, d are female, and a>c && b>d, then ac, bd is better than ad, bc
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 1010;
int male[MAXSZ];
int female[MAXSZ];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int c;
        scanf("%d", &c);
        female[i] = c;
    }
    for (int i = 0; i < n; ++i)
    {
        int c;
        scanf("%d", &c);
        male[i] = c;
    }
    sort(male, male + n);
    sort(female, female + n);

    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += (int)abs(female[i] - male[i]);
    }

    printf("%d", ret);
}
