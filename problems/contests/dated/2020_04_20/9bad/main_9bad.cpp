/*
TASK: 9bad
LANG: C++14
*/

/*
 * Problem 9bad (contests/dated/2020_04_20/9bad)
 * Create time: Mon 20 Apr 2020 @ 11:23 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
	int t;
	scanf("%d", &t);
	for (int j=0; j<t; ++j) scanf("%*d");
	printf("%d\n", t);
    }

    return 0;
}
