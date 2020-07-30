#include <iostream>

int main()
{
    int N; scanf("%d", &N);
    int a=0, b=1;
    while (a <= N<<1)
    {
        (a = b) += a;
        std::swap(a, b);
        printf("%d\n", a);
    }
}

