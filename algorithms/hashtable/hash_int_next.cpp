/*
24 Sep 2019
this impl is unable to store the value 0
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 107; // should be a prime number + 1
int table[MAXSZ];

int insert(const int k)
{
    int i;
    for (i = k; table[i % MAXSZ]; i = (i + 1) % MAXSZ)
    {
        if (i == (k - 1) % MAXSZ)
            return -1;
    };
    table[i] = k;
    return i;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        if (insert(t) < 0)
        {
            printf("Error! Hash table too small!");
            return 1;
        }
    }

    for (int i = 0; i < MAXSZ; ++i)
    {
        if (table[i])
            printf("%d\n", table[i]);
    }

    return 0;
}
