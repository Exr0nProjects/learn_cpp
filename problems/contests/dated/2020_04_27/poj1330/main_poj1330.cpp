/*
TASK: poj1330
LANG: C++14
*/

/*
 * Problem poj1330 (contests/dated/2020_04_27/poj1330)
 * Create time: Wed 29 Apr 2020 @ 11:40 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;
const int MX = 10111;
list<int> head[MX];
char hasParent[MX];
int N, a, b;

int find(int cur)
{
	//printf("cur %d a%d b%d\n", cur, a, b);
	if (cur == a || cur == b)
		return cur;
	vector<int> child;
	for (list<int>::iterator it=head[cur].begin(); it!=head[cur].end(); ++it)
		if (find(*it))
			child.push_back(*it);
	if (child.size() == 0)
		return 0;
	if (child.size() == 1)
		return child[0];
	if (child.size() == 2)
		return cur;
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		memset(hasParent, 0, sizeof hasParent);
		for (int i=0; i<MX; ++i) head[i].clear();
		for (int i=0; i<N-1; ++i)
		{
			int p, c;
			scanf("%d%d", &p, &c);
			head[p].push_back(c);
			hasParent[c] = 1;
		}
		scanf("%d%d", &a, &b);
		for (int i=0; i<N; ++i)
			if (!hasParent[i+1])
			{
				printf("%d\n", find(i+1));
				break;
			}
	}

    return 0;
}
