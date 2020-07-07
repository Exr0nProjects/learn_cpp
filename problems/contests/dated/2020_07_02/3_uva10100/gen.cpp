#include <iostream>

const int words = 40;
char a[20];

char* generate(char buf[])
{
    buf[0] = rand()%26 + 'a';
    buf[1] = rand()%26 + 'a';
    buf[2] = 0;
    return buf;
}

int main()
{
    for (int i=0; i<1000; ++i)
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

