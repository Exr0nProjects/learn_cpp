// 22 July 2020
#include <ctime>
#include <cstdio>
#include <cstdlib>

const int MXT = 10;
const int MXN = 10000;

int main()
{
    srand(time(0));
    for (int t=0; t<MXT; ++t)
    {
        if (t) printf("0\n");
        //int N = rand()%MXN+1;
        int N = MXN;
        printf("%d\n", N);
        for (int i=2; i<=N; ++i)
            printf("%d %d\n", rand()%(i-1)+1, i);
    }
    printf("-1\n");
}

