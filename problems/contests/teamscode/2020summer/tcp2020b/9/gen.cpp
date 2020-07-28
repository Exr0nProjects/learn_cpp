#include <ctime>
#include <cstdio>
#include <cstdlib>

int main()
{
    srand(time(0));
    for (int i=0; i<8; ++i) printf("%c", rand()%10 +'0'); printf("\n");
    for (int i=0; i<8; ++i) printf("%c", rand()%10 +'0'); printf("\n");
}

