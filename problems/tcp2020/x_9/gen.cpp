#include <cstdlib>
#include <cstdio>
#include <ctime>

int main()
{
    srand(time(NULL));
    printf("%lld\n%lld\n", rand(), rand());
}

