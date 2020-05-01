/*
TASK: 5_uva3924
LANG: C++14
*/

/*
 * Problem 5_uva3924 (contests/dated/2020_04_29/5_uva3924)
 * Create time: Thu 30 Apr 2020 @ 18:02 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int MX = 400111;
int alloc=1, trie[MX][30];
bool isend[MX];
int tab[MX];

char buf[MX];

void clear()
{
	alloc = 1;
	memset(tab, 0, sizeof tab);
	memset(trie, 0, sizeof trie);
	memset(isend, 0, sizeof isend);
	tab[0] = 1;
}
void insert(string &s)
{
	int cur=0;
	for (int i=s.length()-1; i>=0; --i)
	{
		if (!trie[cur][s[i]-'a'])
			trie[cur][s[i]-'a'] = alloc++;
		cur=trie[cur][s[i]-'a'];
	}
	isend[cur] = 1;
}
int countback(int idx)
{
	int cur=0, tot=0;
	do {
		cur = trie[cur][buf[idx]-'a'];
		//printf("moving to %d (via %c)\n", cur, buf[idx]);
		-- idx;
		if (isend[cur])
		{
			//printf("idx %d works\n", idx);
			if (idx < 0) tot += 1;
			else tot += tab[idx];
		}
		tot %= 20071027;
		if (idx < 0) break;
	} while (cur);
	return tot;
}

int main()
{
	int kase=0;
	while (scanf("%s", buf))
	{
		if (!buf[0]) break;
		clear();
		int S;
		scanf("%d", &S);
		string word;
		for (int i=0; i<S; ++i)
		{
			cin >> word;
			insert(word);
		}

		int i;
		for (i=0; buf[i]; ++i)
		{
			tab[i] = countback(i);
		}
		printf("Case %d: %d\n", ++kase, tab[i-1]);
	}

    return 0;
}
