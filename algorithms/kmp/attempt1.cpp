// 8 July 2020

#include <iostream>

const int MX = 100111;
const int MXP = 1000;
char str[MX], pat[MXP]; // match string, pattern
int N, P, nxt[MXP];     // size of str and pat

//void set_nxt()
//{   // WRONG WRONG WRONG, should be like failpointers
//    for (int cur=1, pre=0; cur<P; ++cur)
//    {
//        printf("cur %d pre %d ==? %d\n", cur, pre, pat[cur] == pat[pre]);
//        if (pat[cur] == pat[pre])
//            nxt[cur] = ++pre;   // FIX: ++pre not pre++ because we want to jump to the one after the match
//        else
//            pre = pat[cur] == pat[0];   // FIX: set to 1 if its equal to the beginning
//    }
//}

void set_nxt()
{
    memset(nxt, -1, sizeof nxt);
    for (int i=1; i<P; ++i)
    {
        printf("i = %d\n", i);
        int j=nxt[i-1];
        for (; ; j=nxt[j])
        {
            printf("    j = %d\n", j);
            if (pat[j+1] == pat[i])
            {
                nxt[i] = j+1;
                break;
            }
        }
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

