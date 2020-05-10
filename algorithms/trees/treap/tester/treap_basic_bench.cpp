#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	while (true)
	{
		char t=' ';
		while (t < 'a' || t > 'z') scanf("%c", &t);

		if (t == 'x') break;

		int d;
		scanf("%d", &d);
		if (t == 'i')
			s.insert(d);
		else if (t == 'r')
			s.erase(d);
		else if (t == 'q')
			printf("%d\n", s.find(d) != s.end());
	}
}

