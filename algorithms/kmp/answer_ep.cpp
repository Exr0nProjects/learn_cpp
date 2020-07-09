#include <cstdio>
#include <cstring>

const int MX = 100111;
char c[MX];
int nxt[MX];
void kmp(int len) {
    nxt[0] = -1;
    for (int i = 1; i < len; ++i) {
        for (nxt[i] = nxt[i - 1]; ~nxt[i] && c[nxt[i] + 1] != c[i];
                nxt[i] = nxt[nxt[i]])
            ;
        if (c[nxt[i] + 1] == c[i])
            ++nxt[i];
    }
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        memset(c, 0, sizeof c);
        memset(nxt, 0, sizeof nxt);
        scanf("%s", c);
        int len = strlen(c);
        kmp(len);
        for (int i=0; i<len; ++i) printf("%3d", nxt[i]); printf("\n");
    }
}
