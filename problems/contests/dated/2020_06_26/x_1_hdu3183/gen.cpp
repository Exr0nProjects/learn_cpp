#include <cstdio>
#include <cstdlib>
#include <ctime>
const int cases = 10000;
const int maxlen = 1000;
//const int maxlen = 10;

int main()
{
    srand(time(NULL));
    for (int c=0; c<cases; ++c)
    {
        int len = rand()%maxlen+1;
        printf("%d", rand()%9 + 1);
        for (int i=0; i<len; ++i)
            printf("%d", rand()%10);
        printf(" %d\n", rand()%len+1);
    }
}

