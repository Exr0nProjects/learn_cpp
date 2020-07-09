// 8 July 2020

#include <iostream>

const int MX = 100111;
const int MXP = 1000;
char str[MX], pat[MXP]; // match string, pattern
int N, P, nxt[MXP];     // size of str and pat

void set_nxt()
{
    for (int cur=1, pre=0; cur<P; ++cur)
    {
        printf("cur %d pre %d ==? %d\n", cur, pre, pat[cur] == pat[pre]);
        if (pat[cur] == pat[pre])
            nxt[cur] = ++pre;   // FIX: ++pre not pre++ because we want to jump to the one after the match
        else
            pre = 0;
    }
}

int main()
{
    scanf("%s", pat);
    P = strlen(pat);
    set_nxt();
    for (int i=0; i<P; ++i)
        printf("%d ", nxt[i]);
    printf("\n");
}

