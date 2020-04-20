/*
TASK: 3
LANG: C++14
*/

/*
 * Problem 3 (contests/dated/2020_04_20/3)
 * Create time: Mon 20 Apr 2020 @ 09:12 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <stack>
#include <set>

using namespace std;
multiset<int> warehouse;
stack<multiset<int>::iterator> ops;
int N;

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
	int t;
	scanf("%d", &t);
	switch (t)
	{
	    case 0:
		scanf("%d", &t);
		ops.push(warehouse.insert(t));
		break;
	    case 1:
		if (warehouse.empty()) break;
		warehouse.erase(ops.top());
		ops.pop();
		break;
	    case 2:
		if (warehouse.empty()) printf("0\n");
		else printf("%d\n", *warehouse.rbegin());
		break;
	}
    }

    return 0;
}
