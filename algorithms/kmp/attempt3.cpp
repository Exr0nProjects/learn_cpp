// 3 oct 2020 23:33

#include <cstdio>
#include <cstring>

const int MX = 10000;
int P, k[MX];
char p[MX];

void kmp()
{
    k[0] = -1;
    for (int i=1; i<P; ++i)
    {
        for (k[i]=k[i-1]; ~k[i] && p[k[i]+1] != p[i];
                k[i] = k[k[i]]);
        if (p[k[i]+1] == p[i]) ++k[i];  // you must have this extra if statement, because loop breaks on -1
    }
}

int main()
{
    scanf("%s", p);
    P = strlen(p);
    kmp();
    for (int i=0; i<P; ++i) printf("%3d", k[i]); printf("\n");
}
