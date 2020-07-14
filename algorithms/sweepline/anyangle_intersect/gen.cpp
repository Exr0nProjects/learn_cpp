#include <ctime>
#include <cstdio>
#include <cstdlib>

const int MXN = 6;
const int MXM = 10;

int main()
{
    srand(time(NULL));
    int N = rand()%MXN+1;
    printf("%d\n", N);
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<4; ++j)
        {
            if (j) printf(" ");
            printf("%d", rand()%MXM+1);
        }
        printf("\n");
    }
}

