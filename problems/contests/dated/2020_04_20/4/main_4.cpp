/*
TASK: 4
LANG: C++14
*/

/*
 * Problem 4 (contests/dated/2020_04_20/4)
 * Create time: Mon 20 Apr 2020 @ 09:17 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <queue>
#include <set>


using namespace std;
set<int> memory;
queue<set<int>::iterator> cache;
int M, N;

int main()
{
    scanf("%d%d", &M, &N);
    int ret=0;
    for (int i=0; i<N; ++i)
    {
	int w;
	scanf("%d", &w);
	if (!memory.count(w))
	{
	    ++ret;
	    if (memory.size() >= M)
	    {
		memory.erase(cache.front());
		cache.pop();	// FIX: pop the cache
	    }
	    cache.push(memory.insert(w).first);
	}
    }

    printf("%d\n", ret);

    return 0;
}
