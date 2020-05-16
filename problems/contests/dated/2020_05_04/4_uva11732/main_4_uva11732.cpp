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
#include <cstring>

using namespace std;
const int MX = 4111*1000;
char buf[1010];
int trie[MX][60], size[MX], alloc=1;
int N, ret;

inline int id(char c)
{
	if (c >= 'a' && c <= 'z') return c-'a';
	if (c >= 'A' && c <= 'Z') return c-'A' + 26;
	if (c >= '0' && c <= '9') return c-'0' + 52;
}

void insert(int idx, int cur)
{
	ret += size[cur]++;
	int &stp = trie[cur][buf[idx]];
	if (!stp)
		stp = alloc++;
	else
		ret += size[cur]-1;
	if (buf[idx]) insert(idx+1, stp);
}

int main()
{
	while (scanf("%d", &N) == 1)
	{
		if (!N) break;
		std::memset(trie, 0, min(sizeof(int)*alloc*60, sizeof trie));
		std::memset(size, 0, min(sizeof(int)*alloc, sizeof size));
		ret = 0;
		alloc = 1;

		for (int i=0; i<N; ++i)
		{
			scanf("%s", buf);
			insert(0, 0);
			printf("    %d\n", ret);
		}
		printf("%d\n", ret);
	}

    return 0;
}

