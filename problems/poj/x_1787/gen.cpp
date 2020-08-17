#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

//const int T = 1000;
//const int MXP = 10000;
//const int MXC = 10000;

const int T = 1000;
const int MXP = 10000;
const int MXC = 10000;

int main()
{
    srand(time(0));
    for (int i=0; i<T; ++i)
    {
        printf("%d %d %d %d %d\n",
                rand(1, MXP),
                rand(1, MXC),
                rand(1, MXC),
                rand(1, MXC),
                rand(1, MXC)
              );
    }
    printf("0 0 0 0 0\n");

    return 0;
}

