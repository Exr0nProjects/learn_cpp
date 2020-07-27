#include <cstdio>
#include <cstring>

const int MX = 100111;
int N, M, occ[MX], arr[MX], bit[MX];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
        occ[arr[i]] = i;
    }
    for (int i=0; i<M; ++i)
    {
        int rem;
        scanf("%d", &rem);
        occ[rem] = 0;
        memset(bit, 0, sizeof bit);
        int invs=0;
        for (int j=N-1; ~j; --j)
        {
            for (int x=j; x; x-=x&-x)
                invs += bit[x];
            for (int x=j; x<=N; x+=x&-x)
                ++bit[x];
        }
        printf("%d\n", invs);
    }
}

