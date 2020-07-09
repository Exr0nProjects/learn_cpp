#include <ctime>
#include <cstdio>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    printf("100000\n");
    for (int c=0; c<100000; ++c)
    {
        for (int i=0; i<100; ++i)
            printf("%c", rand()%26 + 'a');
        printf("\n");
    }
}

