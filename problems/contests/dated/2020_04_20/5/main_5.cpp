/*
TASK: 5
LANG: C++14
*/

/*
 * Problem 5 (contests/dated/2020_04_20/5)
 * Create time: Mon 20 Apr 2020 @ 09:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#define ll long long

void recurse(int num)
{
    if (num == 0) return;
    printf("%d", num%10);
    recurse(num/10);	// tail recursion :sunglasses:
}

int main()
{
    int N;
    scanf("%d", &N);
    recurse(N);
    printf("\n");

    return 0;
}
