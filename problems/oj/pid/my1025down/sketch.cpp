#include <cstdio>
#include <cstring>

int main()
{
    int num;
    memset(&num, 0x40, sizeof num);
    printf("%d\n", num - (1<<30));
}

