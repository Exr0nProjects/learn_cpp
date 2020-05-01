/*
TASK: 5_poj1014
LANG: C++14
*/

/*
 * Problem 5_poj1014 (contests/dated/2020_04_29/5_poj1014)
 * Create time: Thu 30 Apr 2020 @ 17:32 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
using namespace std;
const int MX = 6;
int counts[MX];

int main()
{
	int kase=0;
	while (true)
	{
		int tot=0;
		for (int i=0; i<MX; ++i)
		{
			scanf("%d", &counts[i]);
			tot += counts[i];
		}
		if (!tot) break;
		int a=0, b=0;
		for (int i=MX-1; i>=0; --i)
			for (int j=0; j<counts[i]; ++j)
				if (a < b)
					a += (i+1);
				else
					b += (i+1);
		//printf("%d vs %d\n", a, b);
		printf("Collection #%d:\nCan%s be divided.\n\n", ++kase, a == b ? "" : "'t");
	}


    return 0;
}
