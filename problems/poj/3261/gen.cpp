#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

//const int MXN = 20000;
//const int MXV = 1e6;

const int MXN = 20000;
const int MXV = 1e6;

int main()
{
    srand(time(0));
    printf("%d %d\n", MXN, rand(1, 3));
    for (int i=0; i<MXN; ++i)
        printf("%d\n", rand(1, MXV));

    return 0;
}

