/*
TASK: 6_uva1394
LANG: C++14
*/

/*
 * Problem 6_uva1394 (contests/dated/2020_05_04/6_uva1394)
 * Create time: Sat 16 May 2020 @ 12:49 (PDT)
 * Accept time: Sat 16 May 2020 @ 13:20 (PDT)
 *
 */

#include <iostream>

using namespace std;
const int MX = 10111;
int pred[MX], succ[MX];

void remove(int i)
{
	pred[succ[i]] = pred[i];
	succ[pred[i]] = succ[i];
}

int main()
{
	int N, K, M;
	while (scanf("%d%d%d", &N, &K, &M) == 3)
	{
		if (!N && !K && !M) break;
		for (int i=0; i<N; ++i)
		{
			pred[i] = (i+N-1) %N;
			succ[i] = (i+N+1) %N;
		}

		int deathbed = M-1;
		for (int rem=N-1; rem>0; --rem)
		{
			remove(deathbed);
			const int stp = K%rem;
			if (stp == 0) deathbed = pred[deathbed];
			for (int i=0; i<stp; ++i)
				deathbed = succ[deathbed];
		}
		printf("%d\n", succ[deathbed]+1);
	}

    return 0;
}

