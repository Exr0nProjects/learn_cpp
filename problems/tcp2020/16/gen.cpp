#include <cstdlib>
#include <cstdio>
#include <ctime>

int main()
{
    srand(time(0));
    //int N = rand() % 15000 +1;
    int N = rand() % 5 +1;
    printf("%d\n", N);
    for (int i=0; i<N; ++i)
        printf("%d %d\n", rand()%10 + 1, rand()%10 + 1);
}
