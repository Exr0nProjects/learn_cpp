// 9 July 2020

#include <cstdio>
#include <cstring>

const int MX = 100111;
int N, P, nxt[MX];
char str[MX], pat[MX];

void set_nxt()
{
    memset(nxt, 0, sizeof nxt);
    for (int i=1; i<P; ++i)
    {
        //printf("i %d p %d\n", i, P);
        int j = i;
        do {
            j = nxt[j];
            printf("i %d j %d\n", i, j);
            if (pat[j+1] == pat[i])
            {
                nxt[i+1] = j+1;
                break;
            }
        } while (j > 0);
    }
}

int main()
{
    scanf("%s", pat);
    P = strlen(pat);
    set_nxt();
    for (int i=0; i<P; ++i) printf("%3d", nxt[i]); printf("\n");
}

