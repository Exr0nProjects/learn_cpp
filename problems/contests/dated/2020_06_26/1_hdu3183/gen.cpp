#include <cstdio>
#include <cstdlib>
const int cases = 100;
const int maxlen = 100;

int main()
{
    for (int c=0; c<cases; ++c)
    {
        int len = rand()%maxlen+1;
        printf("%d", rand()%9 + 1);
        for (int i=0; i<len; ++i)
            printf("%d", rand()%10);
        printf(" %d\n", rand()%len);
    }
}

