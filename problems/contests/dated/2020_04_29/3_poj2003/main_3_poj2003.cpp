/*
TASK: 3_poj2003
LANG: C++14
*/

/*
 * Problem 3_poj2003 (contests/dated/2020_04_29/3_poj2003)
 * Create time: Thu 30 Apr 2020 @ 16:28 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
const int MX = 1111;
map<string, int> nameid;
vector<string> idname;
int id(string &name)
{
	if (!nameid.count(name))
	{
		nameid[name] = idname.size();
		idname.push_back(name);
	}
	return nameid[name];
}

struct Node
{
	int parent;
	vector<int> children;
} tree[MX];

void insert(int parent, int name)
{
	tree[parent].children.push_back(name);
	tree[name].parent = parent;
}

void erase(int cur)
{
	if (cur == 1) return;

	while (tree[cur].children.size())
	{
		const vector<int> &t = tree[tree[cur].parent].children;
		vector<int>::iterator it;
		it = t.find(cur);
		printf("replacing %d with %d\n", *it, tree[cur].children[0]);
		*it = cur = tree[cur].children[0];
	}
}

void print(int cur=1, int lay=0)
{
	for (int i=0; i<lay; ++i) printf("+");
	printf("%s\n", idname[cur].c_str());
	for (vector<int>::iterator it=tree[cur].children.begin();
			it != tree[cur].children.end(); ++it)
		print(*it, lay+1);
}

int main()
{
	string tmp;
	cin >> tmp;
	id(tmp);
	while (getline(cin, tmp))
	{
		string a, b, c;
		stringstream(tmp) >> a >> b >> c;
		printf("%s %s %s\n", a.c_str(), b.c_str(), c.c_str());
		if (a == "fire")
			erase(id(b));
		else if (a == "print")
			print();
		else if (b == "hires")
			insert(id(a), id(c));
		else
			return 150;
	}

    return 0;
}
