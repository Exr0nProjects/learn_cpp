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
int failptr[MX*ML];	// failpointee of i
int failwords[MX*ML];	// number of words in fail pointer chain
bool isword[MX*ML];
string prefix[MX*ML];	// technically not needed
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
    isword[cur] = 1;	// FIX: use isword to reset failword count each time, don't just add
}

bool query(const string &w)
{
    int cur=0;
    for (char c : w)
	if (!trie[cur][c-CV])
	    return false;
	else
	    cur = trie[cur][c-CV];
    return isword[cur];
}

void constructFailPointers(int cur=0)
{
    memset(failptr, 0, sizeof failptr);
    queue<int> bfs;
    bfs.push(0);
    while (!bfs.empty())
    {
	int cur = bfs.front(); bfs.pop();
	failwords[cur] = isword[cur] + failwords[failptr[cur]]; // precompute # words in failptr chain

	for (int c=0; c<MA; ++c) if (trie[cur][c])
	{
	    bfs.push(trie[cur][c]);
	    if (!cur) continue; // FIX: don't construct failpointers for first letters
	    // find failpointer root to construct failpointer

	    // traverse fail pointer chain until letter matches
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
    if (!failPointersConstructed)
	constructFailPointers();

    int cur=0, ret=0;
    for (int idx=0; idx<k.length(); ++idx)
    {
	while (cur && !trie[cur][k[idx]-CV])	// while at wrong location
	    cur = failptr[cur];			// 	follow fail pointer
	cur = trie[cur][k[idx]-CV];	// go to a node representing the this letter (or root)

	ret += failwords[cur];
    }
    return ret;
}

void printMatches(const string &k)
{
    if (!failPointersConstructed)
	constructFailPointers();

    int cur=0;
    for (int idx=0; idx<k.length(); ++idx)
    {
	while (cur && !trie[cur][k[idx]-CV])
	    cur = failptr[cur];
	cur = trie[cur][k[idx]-CV];
	for (int fail=cur; fail; fail=failptr[fail])
	    if (isword[fail])
		printf("%d %s\n", idx-prefix[fail].length()+1, prefix[fail].c_str());
    }
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
	    case 'p':
		printMatches(s);
		break;
	    case 'd':
		dump();
		break;
	    default:
		printf("i: insert, q: query, c: count matches, p: print matches, d: dump\n");
	}
    }
}

