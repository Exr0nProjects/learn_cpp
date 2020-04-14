// (hopefully clean) big array trie, 13 Apr 2020
const int MA = 30;	// # of letters in the alphabet
const char CV = 'a'; 	// conversion character

#include <queue>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 10000; 	// # of words
const int ML = 100; 	// # of letters per word

int trie[MX*ML][MA];	// heap mem simulation, trie[0] is the root and sentry
int parent[MX*ML];	// parent[i] = parent of trie node i
int weight[MX*ML]; 	// weight[i] = weight of trie node i
char value[MX*ML]; 	// value [i] = the character that trie node i is
bool isend[MX*ML];	// is_end[i] = whether trie[i] is the end of a word
priority_queue<int, deque<int>, greater<int> > alloc;	// indicies to alloc new trie nodes at

void resetTrie()
{
    // TODO: lazy reset? (only reset len, make sure to check against len when traversing, and clear memory when creating a new node)
    memset(trie, 0, sizeof trie);
    memset(isend, 0, sizeof isend);
    alloc = {};
    alloc.push(1);
}

void insertWord(const string& s)
{
    int cur = 0;			// start at the root
    for (char c : s)			// for every character in the word
    {
	if (!trie[cur][c-CV])		// if this prefix doesn't exist yet
	{
	    int pos = alloc.top();	// get next alloc pos
	    alloc.pop();		// mark that alloc pos as used
	    if (alloc.empty())		// if that was the last saved one
		alloc.push(pos + 1);	// 	push the next one up (no gaps)
	    // update internal state
	    trie[cur][c-CV] = pos;	// make the new trie node at pos
	    parent[pos] = cur;		// link new node to this one as its parent
	    value[pos] = c;		// tell the node (and everyone else) what value it has
	    ++weight[cur];		// mark parent of new node as having an additional child
	}
	cur = trie[cur][c-CV];		// go to the new prefix containing the new char
    }
    isend[cur] = 1;			// mark this prefix as the end of a word
}

bool queryWord(const string& s)
{
    int cur = 0;		// start at the root
    for (char c : s)		// for every character in the word
    {
	if (!trie[cur][c-CV])	// if this prefix doesn't exist yet
	    return false;	//	rest of word won't exist, return false
	cur = trie[cur][c-CV];	// go there
    }
    return isend[cur];		// check whether the query is a word or just a prefix
}

void eraseWord(const string& s)
{
    int cur = 0;		// start at the root (again)
    for (char c : s)		// these are very similar aren't they
    {
	if (!trie[cur][c-CV])	// if word isn't in trie
	    return;
	cur = trie[cur][c-CV];	// go to that node
    }
    isend[cur] = 0;		// remove the word

    // clean up
    while (cur && !weight[cur])	// while at a deprecated leaf node that isn't the root
    {
	int del = cur;			// remember where we were
	alloc.push(del);		// mark node for reallocation
	cur = parent[cur];		// move up the tree

	trie[cur][value[del]-CV] = 0;	// remove downwards link (the important one)
	parent[del] = 0;		// remove upwards link
	value[del] = 0;			// clear value
	--weight[cur];			// unweight the parent of deleted
    }
}

void dump(int cur=0, int lay=0, int c='_')
{
    for (int l=0; l<lay; ++l)
	printf("|   ");
    printf("+ %c %d %c\n", c, weight[cur], isend[cur] ? 'E' : ' ');

    for (int i=0; i<MA; ++i)
	if (trie[cur][i])
	    dump(trie[cur][i], lay+1, i+CV);
}


int main()
{
    resetTrie();
    printf("`i <word>` to insert, `q <word>` to query, `e <word>` to erase\n");
    while (true)
    {
	char c;
	string s;
	cin >> c;
	if (c == 'd')
	{
	    dump();
	    continue;
	}
	cin >> s;
	if (c == 'i')
	    insertWord(s);
	else if (c == 'q')
	    printf("%s\n", queryWord(s) ? "YES" : "NO");
	else if (c == 'e')
	    eraseWord(s);
    }
}

