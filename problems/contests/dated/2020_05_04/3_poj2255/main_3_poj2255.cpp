/*
TASK: 3_poj2255
LANG: C++14
*/

/*
 * Problem 3_poj2255 (contests/dated/2020_05_04/3_poj2255)
 * Create time: Sat 16 May 2020 @ 13:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>

void setIO(const std::string &name = "3_poj2255");

using namespace std;
const int MX = 30;
char pre[MX], in[MX];

void printpost(int pl, int pr, int il, int ir, int lay=0)
{
	//for (int i=0; i<lay; ++i) printf("|    ");
	//for (int i=pl; i<pr; ++i) printf("%c", pre[i]); printf("  ");
	//for (int i=il; i<ir; ++i) printf("%c", in[i]);	printf("\n");

	if (pl + 1 < pr)
	{
		int off;
		for (off=0; off<ir-il; ++off)
			if (in[il+off] == pre[pl])
				break;
		printpost(pl+1, pl+off+1, il, il+off, lay+1);
		printpost(pl+off+1, pr, il+off+1, ir, lay+1);
	}
	if (pr > pl) printf("%c", pre[pl]);
}

int main()
{
	int N, first=0;
	while (scanf("%s%n%s", pre, &N, in) == 2)
	{
		if (first) N-=first;
		else ++first;

		printpost(0, N, 0, N);
		printf("\n");
	}

    return 0;
}
