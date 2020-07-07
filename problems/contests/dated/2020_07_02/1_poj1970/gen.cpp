#include <iostream>

const int T = 11;
const int sz = 19;

int main()
{
    srand(time(NULL));
    printf("%d\n", T);
    for (int k=0; k<T; ++k)
    {
        for (int i=0; i<sz; ++i)
        {
            for (int j=0; j<sz; ++j)
                printf("%d ", rand()%3);
            printf("\n");
        }
        printf("\n");
    }
}


