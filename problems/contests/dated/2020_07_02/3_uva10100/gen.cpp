#include <iostream>

const int words = 200;
char a[20];

char* generate(char buf[])
{
    for (int i=0; i<3; ++i)
        buf[i] = rand()%26 + 'a';
    buf[3] = 0;
    return buf;
}

int main()
{
    srand(time(NULL));
    for (int i=0; i<50; ++i)
    {
        for (int w=0; w<words; ++w)
        {
            printf("%s ", generate(a));
        } printf("\n");

        for (int w=0; w<words; ++w)
        {
            printf("%s ", generate(a));
        } printf("\n");
    }
}

