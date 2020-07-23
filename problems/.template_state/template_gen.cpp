#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

int main()
{
    srand(time(0));

    return 0;
}

