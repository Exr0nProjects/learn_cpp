// test next/prev construction

#include <exception>
#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main()
{
	while (true)
	{
		char c = '\n'; while (c < 'a' || c > 'z') scanf("%c", &c);
		int d; scanf("%d", &d);
		if (c == 'i')
		{
			s.insert(d);
		}
		if (c == 'r')
		{
			s.erase(d);
		}
		if (c == 'q')
		{
			printf("%d\n", s.find(d) != s.end());
		}
		if (c == 'n')
		{
			auto it = s.find(d);
			if (it != s.end() && next(it) != s.end())
				printf("%d\n", *next(it));
			else
				printf("0\n");
		}
		if (c == 'p')
		{
			auto it = s.find(d);
			if (it != s.end() && it != s.begin())
				printf("%d\n", *prev(it));
			else
				printf("0\n");
		}
	}
}

