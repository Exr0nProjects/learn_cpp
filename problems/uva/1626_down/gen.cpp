#include <ctime>
#include <cstdio>
#include <cstdlib>
const int MXT = 40;
const int MXN = 100;
const char chars[] = "()[]";

int main()
{
    srand(time(0));
    int T = rand()%MXT+1;
    printf("%d\n", T);
    for (int i=0; i<T; ++i)
    {
        printf("\n");
        int N = rand()%MXN+1;
        for (int i=0; i<N; ++i) printf("%c", chars[rand()%4]);
        printf("\n");
    }
}
