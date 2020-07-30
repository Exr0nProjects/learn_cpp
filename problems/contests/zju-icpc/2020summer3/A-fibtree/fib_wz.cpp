#include <cstdio>

int fib[(int)1e6+100];

int main()
{
    int M; scanf("%d", &M);
    fib[1] = 1;
    fib[0] = 1;
    int i = 2;
    while(true){
        if(fib[i - 1] + fib[i - 2] > M) break;
        fib[i] = fib[i - 1] + fib[i - 2];
        i++;
    }
    for(int j = 0; j<i; j++)
        printf("%d\n", fib[j]);
}

