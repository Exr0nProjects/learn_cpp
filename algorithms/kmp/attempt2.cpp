// 9 July 2020

#include <cstdio>
#include <cstring>

const int MX = 1000111;
int N, P, nxt[MX];
char str[MX], pat[MX];

void set_nxt()
{
    //memset(nxt, -1, sizeof pat);
    nxt[0] = -1; // setry
    for (int i=1; i<P; ++i)
    {
        //printf("i = %d, nxt[i-1] = %d\n", i, nxt[i-1]);
        int j = nxt[i-1];
        while (~j && pat[j+1] != pat[i])
            j = nxt[j];
        nxt[i] = j+1;
        //do {
        //    j = nxt[j];
        //    //printf("j = %d\n", j);
        //    if (pat[j+1] == pat[i])
        //    {
        //        nxt[i] = j+1;
        //        break;
        //    }
        //} while (j >= 0);
    }
}

//int count()
//{
//    int tot=0, j=0;
//    //for (int i=0; i<N; ++i, ++j)
//    for (int i=0; i<N; ++i)
//    {
//        //printf("str[%d] %c; pat[%d] %c\n", i, str[i], j, pat[j]);
//        //if (str[i] != pat[j]) printf("should fail:\n");
//        int f=j-1;
//        for (; str[i]!=pat[f+1] && ~f; f=nxt[f])
//        {
//            //printf("faild i %-2d j %-2d f %-2d\n", i, j, f);
//            //printf(" x");
//        }
//        j = f+1;
//        //if (str[i] != pat[j])
//        //{
//        //    printf(" x");
//        //    j = nxt[j-1], --i;
//        //}
//        if (j+1 == P && str[i] == pat[j])
//        {
//            //printf(" !");
//            ++tot, j=nxt[j];
//        }
//        //printf("\n");
//        j += str[i] == pat[j];
//    }
//    return tot;
//}

int count()
{
    int tot=0, j=0;
    for (int i=0; i<N; ++i)
    {
        //if (str[i] != pat[j])
        //{
        //    int f = j-1;
        //    while (str[i] != pat[f+1] && ~f)
        //        j = nxt[j];
        //}
        while (str[i] != pat[j+1] && ~j)
            j = nxt[j];
        ++j;
        if (j+1 == P)
            ++tot, j=nxt[j];
    }
    return tot;
}


int main()
{
    //int cs; scanf("%d", &cs);
    //while (cs--)
    //{
        //scanf("%s", pat+1);
        //P = strlen(pat+1)+1;
        //set_nxt();
        //for (int i=1; i<P; ++i) printf("%3d", nxt[i]); printf("\n");
    //}

    int cs; scanf("%d", &cs);
    while (cs--)
    {
        scanf("%s%s", pat+1, str+1);
        P = strlen(pat+1)+1;
        N = strlen(str+1)+1;
        set_nxt();
        //for (int i=0; i<P; ++i) printf("%3d", nxt[i]); printf("\n");
        printf("%d\n", count());
    }
}

