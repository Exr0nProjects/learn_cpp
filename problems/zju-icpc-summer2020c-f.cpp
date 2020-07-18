#include <cstdio>
#include <algorithm>
using namespace std;
const int MX = 50111;
int N, seq[MX<<1];

int main()
{
    scanf("%d", &N);
    int mn = MX, mx=MX;
    for (int i=0; i<N; ++i)
    {
        if (__builtin_popcount(i)) seq[--mn] = i+1;
        else seq[++mx] = i+1;
    }
    if (seq[mx] == N) swap(seq[MX], seq[mx]);
    else swap(seq[MX], seq[mn]);
    for (int i=0; i<N; ++i)
        printf("%d ", seq[i+mn+1]);
    printf("\n");
}


