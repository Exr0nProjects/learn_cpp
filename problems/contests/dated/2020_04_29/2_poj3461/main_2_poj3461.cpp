/*
TASK: 2_poj3461
LANG: C++14
*/

/*
 * Problem 2_poj3461 (contests/dated/2020_04_29/2_poj3461)
 * Create time: Thu 30 Apr 2020 @ 16:16 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <string>

using namespace std;
string W, T;
int N;

int main()
{
	scanf("%d\n", &N);
	for (int i=0; i<N; ++i)
	{
		getline(cin, W);
		getline(cin, T);
		int idx=-1, cnt=-1;
		do
		{
			//printf("    idx  %d\n", idx);
			++cnt;
			idx = T.find(W, idx+1);
		} while (idx != string::npos);
		printf("%d\n", cnt);
	}

    return 0;
}
