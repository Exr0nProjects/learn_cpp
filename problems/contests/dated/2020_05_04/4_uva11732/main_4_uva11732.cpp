/*
TASK: 4_uva11732
LANG: C++14
*/

/*
 * Problem 4_uva11732 (contests/dated/2020_05_04/4_uva11732)
 * Create time: Sat 16 May 2020 @ 14:00 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>

using namespace std;
const int MX = 4111*1000;
char buf[1010];
int trie[MX][125], size[MX], alloc=1;
int N, ret;

void insert(int idx, int cur)
{
	if (!buf[idx]) return;
	ret += size[cur]++;
	int &stp = trie[cur][buf[idx]];
	if (!stp)
	{
		stp = alloc++;
	}
	insert(idx+1, stp);
}

int main()
{
	while (scanf("%d", &N) == 1)
	{
		if (!N) break;
		memset(trie, 0, sizeof(int)*alloc*125);
		memset(size, 0, sizeof(int)*alloc);
		ret = 0;
		alloc = 1;

		for (int i=0; i<N; ++i)
		{
			scanf("%s", buf);
			insert(0, 0);
		}
		printf("%d\n", ret);
	}

    return 0;
}

