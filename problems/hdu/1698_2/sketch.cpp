#include <iostream>

int main()
{
    int n[20] = {};
    int a = 0;
    n[a++] = a++;
    printf("0 %d 1 %d\n", n[0], n[1]);
}

