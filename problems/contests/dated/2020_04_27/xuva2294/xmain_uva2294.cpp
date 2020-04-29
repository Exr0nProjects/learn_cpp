/*
TASK: uva2299
LANG: C++14
*/

/*
 * Problem uva2294 (contests/dated/2020_04_27/uva2294)
 * Create time: Wed 29 Apr 2020 @ 11:18 (PDT)
 * Accept time: Wed 29 Apr 2020 @ 13:44 (PDT)
 *
 */

#include <iostream>

using namespace std;
double overhang;

bool check(int cards)
{
	double tot = 0;
	for (int i=0; i<cards; ++i)
		tot += (double)1/(i+2);
	return tot >= overhang;
}

int main()
{
	while (true)
	{
		scanf("%lf", &overhang);
		if (!overhang)
			break;
		int l = 0, r = 400;
		for (int i=0; i<20; ++i)
		{
			int m = (l + r) / 2;
			if (check(m))
				r = m;
			else
				l = m;
		}
		printf("%d card(s)\n", r);
	}

    return 0;
}
