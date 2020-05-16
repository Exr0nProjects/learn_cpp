/*
TASK: 2_poj2013
LANG: C++14
*/

/*
 * Problem 2_poj2013 (contests/dated/2020_05_04/2_poj2013)
 * Create time: Sat 16 May 2020 @ 12:01 (PDT)
 * Accept time: Sat 16 May 2020 @ 12:27 (PDT)
 *
 */

#include <iostream>

using namespace std;
const int MX = 31;
char names[MX][MX];

int main()
{
	int N, kase=0;
	while (scanf("%d", &N) == 1)
	{
		if (!N) break;
		memset(names, 0, sizeof names);
		for (int i=0; i<N; ++i)
		{
			const int pos = i%2 ? N-(i+1)/2 : i/2;
			scanf("%s", names[pos]);
		}
		printf("SET %d\n", ++kase);
		for (int i=0; i<N; ++i)
		{
			printf("%s\n", names[i]);
		}
	}
    return 0;
}

