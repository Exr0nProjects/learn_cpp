// AC Automaton attempt 1, 15 April 2020

#include <iostream>
#include <cstring>
#include <string>
#include <queue>

const int MX = 10111;
const int ML = 100;
const int MA = 30;
const char CV = 'a';

using namespace std;

int trie[MX*ML][MA];
int parent[MX*ML];
int failptr[MX*ML];
int failwords[MX*ML];
bool isword[MX*ML];
string prefix[MX*ML];
int alloc=1;
bool failPointersConstructed = false;

void add(const string &w)
{
    failPointersConstructed = false;
    int cur = 0, depth=0;
    for (char c : w)
    {
	++depth;
	if (!trie[cur][c-CV])
	{
	    trie[cur][c-CV] = alloc;
	    parent[alloc] = cur;
	    prefix[alloc] = w.substr(0, depth);
	    ++alloc;
	}
	cur = trie[cur][c-CV];
    }
    isword[cur] = 1;
}

bool query(const string &w)
{
    int cur=0;
    for (char c : w)
	if (!trie[cur][c-CV])
	    return false;
    return isword[cur];
}

void constructFailPointers(int cur=0)
{
    memset(failptr, 0, sizeof failptr);
    queue<int> bfs;
    for (int c=0; c<MA; ++c) if (trie[0][c]) bfs.push(trie[0][c]);
    while (!bfs.empty())
    {
	int cur = bfs.front(); bfs.pop();
	failwords[cur] = isword[cur] + failwords[failptr[cur]];

	for (int c=0; c<MA; ++c) if (trie[cur][c])
	{
	    bfs.push(trie[cur][c]);
	    // find failpointer root to construct failpointer
	    int failcur = failptr[cur];
	    while (!trie[failcur][c] && failcur)
		failcur = failptr[failcur];
	    failptr[trie[cur][c]] = trie[failcur][c];
	}
    }
    failPointersConstructed = true;
}

int countMatches(const string &k)
{
    printf("count matches %s\n", k.c_str());
    if (!failPointersConstructed)
	constructFailPointers();

    int cur=0, ret=0;
    for (int idx=0; idx<k.length(); ++idx)
    {
	printf("letter %d: %c\n", idx, k[idx]);
	while (cur && !trie[cur][k[idx]-CV])	// while at wrong location
	{
	    printf("    %x -> %x\n", cur, failptr[cur]);
	    cur = failptr[cur];			// 	follow fail pointer
	}
	printf("    => %x ---> t: %d (l %c)\n", cur, trie[cur][k[idx]-CV], k[idx]);
	cur = trie[cur][k[idx]-CV];	// go to a node representing the this letter (or root)

	printf("at %s (%x)\n", prefix[cur].c_str(), cur);
	ret += failwords[cur];
    }
    return ret;
}

void dump(int cur=0, int lay=0)
{
    if (!lay)
	for (int i=0; i<alloc; ++i)
	{
	    printf("%3x %s:", i, prefix[i].c_str());
	    for (int c=0; c<MA; ++c) if (trie[i][c])
		printf("%2c", c+CV);
	    printf("\n");
	}

    for (int i=0; i<lay; ++i) printf("|    ");
    printf("+ (%d %x->%x) %s\n", failwords[cur], cur, failptr[cur], prefix[cur].c_str());

    for (int c=0; c<MA; ++c)
    {
	if (trie[cur][c])
	    dump(trie[cur][c], lay+1);
    }
}
int main()
{
    while (true)
    {
	char c;
	string s;
	cin >> c >> s;
	
	switch (c)
	{
	    case 'i':
		add(s);
		break;
	    case 'q':
		printf("%s\n", query(s) ? "YES" : "NO");
		break;
	    case 'c':
		printf("%d\n", countMatches(s));
		break;
	    case 'd':
		dump();
		break;
	    default:
		printf("i: insert, q: query, c: count, d: dump\n");
	}
    }
}

