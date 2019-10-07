/*
 8  queens
 6 oct  2019
 */

#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 12;
int vertical[MAXSZ];
int horizontal[MAXSZ];
int diagonal1[MAXSZ * 3];
int diagonal2[MAXSZ * 3];
int n;

int place(cn rem, cn s = 0)
{
    static int count = 0;
    if (rem == 1)
    {
        ++count;
        return count; // todo remove
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (vertical[i] && horizontal[j])
                {
                    printf("X");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = s; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (vertical[i] || horizontal[j] || diagonal1[i + j] || diagonal2[i - j + MAXSZ])
            {
                continue;
            }
            printf("%d: %d, %d\n", rem, i, j);
            vertical[i] = horizontal[j] = diagonal1[i + j] = diagonal2[i - j + MAXSZ] = rem;
            place(rem - 1, i);
            vertical[i] = horizontal[j] = diagonal1[i + j] = diagonal2[i - j + MAXSZ] = 0;
        }
    }
    return count;
}

int main()
{
    scanf("%d", &n);
    place(n);
}
