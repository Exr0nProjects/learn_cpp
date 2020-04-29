/*
TASK: uva10226
LANG: C++14
*/

/*
 * Problem uva10226 (contests/dated/2020_04_27/uva10226)
 * Create time: Wed 29 Apr 2020 @ 10:59 (PDT)
 * Accept time: Wed 29 Apr 2020 @ 13:43 (PDT)
 *
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, int> cnt;
int tot = 0, kase;

int main()
{
	string line;
	scanf("%d\n\n", &kase);
	while (kase)
	{
		getline(cin, line);
		if (line.length())
		{
			++cnt[line];
			++tot;
		}
		else
		{
			for (auto p : cnt)
				printf("%s %.4lf\n", p.first.c_str(), (double)p.second*100/tot);
			if (kase > 1) printf("\n");
			cnt.clear();
			tot=0;
			--kase;
		}
	}

    return 0;
}
