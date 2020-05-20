#include <iostream>
#include <iterator>
#include <set>

std::multiset<int> multi;

int main()
{
	while (true)
	{
		char c = '\n'; while (c < 'a' || c > 'z') scanf("%c", &c);
		if (c == 'x') break;
		int d; scanf("%d", &d);
		if (c == 'i') multi.insert(d);
		if (c == 'r')
		{
			auto count = multi.count(d);
			multi.erase(d);
			for (int i=1; i<count; ++i)
				multi.insert(d);
		}
		if (c == 'q') printf("%d\n", multi.count(d));
		if (c == 'k')
		{
			if (d > multi.size())
			{
				printf("-1\n");
				continue;
			}
			auto it = std::next(multi.begin(), d-1);
			printf("%d\n", it == multi.end() ? -1 : *it);
		}
	}
}

