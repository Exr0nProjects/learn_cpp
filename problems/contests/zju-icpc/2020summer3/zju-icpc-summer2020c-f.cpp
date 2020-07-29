#include <cstdio>
#include <algorithm>
using namespace std;
const int MX = 50111;
int N, seq[MX<<1];

int main()
{
    //for (int cs=1; cs<80; ++cs) {
        //printf("\n");
        scanf("%d", &N);
        //N = cs;
        int mn = MX, mx=MX;
        for (int i=1; i<N; ++i)
        {
            if (__builtin_popcount(i)%2) seq[--mn] = i;
            else seq[++mx] = i;
            //printf("%d .. %d\n", mn-MX, mx-MX);
        }
        seq[MX] = N;
        //for (int i=mn; i<=mx; ++i) printf("%d ", seq[i]); printf("\n");
        //if (seq[mx] == N) swap(seq[MX], seq[mx]);
        //else swap(seq[MX], seq[mn]);
        //for (int i=mn; i<=mx; ++i)
        //    for (int j=1; i-j >= mn && i+j <= mx; ++j)
        //        if (seq[i+j]+seq[i-j] == 2*seq[i])
        //        {
        //            printf("%d +/- %d:  ", seq[i], j);
        for (int i=mn; i<=mx; ++i)
            printf("%d ", seq[i]);
        printf("\n");
                //i = mx+1; break;}
    //}
}


