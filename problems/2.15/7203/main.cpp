/*
 * Problem #7203
 * struct 2.1
 */
#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

struct arrset
{
    int num;
    int a[MAXSZ];
    int b[MAXSZ];
};

int main ()
{
    int num;
    scanf("%d", &num);
    for (int fli=0; fli<num; ++fli)
    {
        arrset temp;
        scanf("%d", &temp.num);
        
        for (int i=0; i<temp.num; ++i)
        {
            scanf("%d %d\n", &temp.a[i], &temp.b[i]);
            if (i&1)
                printf("%d\n", min(temp.a[i], temp.b[i]));
            else
                printf("%d\n", max(temp.a[i], temp.b[i]));
        }
        
    }
    
    return 0;
}
