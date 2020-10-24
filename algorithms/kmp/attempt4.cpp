#include <cstdio>
#include <cstring>

const int MX = 1e6+10;
const int MXS = 1e6+10;

char pat[MX], str[MXS];
int N, P, pi[MX];

void kpi()
{
    pi[0] = -1;
    for (int i=1; i<P; ++i)
    {
        for (pi[i] = pi[i-1]; ~pi[i] && pat[pi[i]+1] != pat[i]; pi[i] = pi[pi[i]]);
        if (pat[pi[i]+1] == pat[i]) ++pi[i];
    }
}

int main()
{
    scanf("%s%s", str, pat);
    N = strlen(str);
    P = strlen(pat);
    kpi();
    int p=-1;
    for (int i=0; i<N; ++i)
    {
        for (; ~p && pat[p+1] != str[i]; p = pi[p]);
        if (pat[p+1] == str[i]) ++p;
        else p=0;
        if (p + 1 == P) { printf("%d\n", i-P+2); return 0; }
    }
}

