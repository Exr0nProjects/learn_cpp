#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

int main()
{
    srand(time(0));
    int T = 1000;
    printf("%d\n", T);
    while (T--)
    {
        printf("%d %d %d %d\n", rand(1, 100), rand(1, 100), rand(1, 100), rand(1, 100));
    }

    return 0;
}

