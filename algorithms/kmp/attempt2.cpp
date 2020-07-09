// 9 July 2020

#include <cstdio>
#include <cstring>

const int MX = 100111;
int N, P, nxt[MX];
char str[MX], pat[MX];

void set_nxt()
{
    memset(nxt, -1, sizeof pat);
    for (int i=1; i<P; ++i)
    {
        printf("i = %d, nxt[i-1] = %d\n", i, nxt[i-1]);
        int j = i-1;
        do {
            j = nxt[j];
            printf("j = %d\n", j);
            if (pat[j+1] == pat[i])
            {
                nxt[i] = j+1;
                break;
            }
        } while (j >= 0);
    }
}

int main()
{
    scanf("%s", pat);
    P = strlen(pat);
    set_nxt();
    for (int i=0; i<P; ++i) printf("%3d", nxt[i]); printf("\n");
}

