// (hopefully clean) big array trie, 13 Apr 2020
const int MA = 30;  // # of letters in the alphabet
const char CV = 'a';   // conversion character

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 10000;   // # of words
const int ML = 100;   // # of letters per word

int trie[MX*ML][MA];  // trie[0] is the root and sentry
bool isend[MX*ML];  // is_end[i] = whether trie[i] is the end of a word
int tlen = 1;    // next idx to add to trie at

void resetTrie()
{
    // TODO: lazy reset? (only reset len, make sure to check against len when traversing, and clear memory when creating a new node)
    memset(trie, 0, sizeof trie);
    memset(isend, 0, sizeof isend);
    tlen = 1;
}

void insertWord(const string& s)
{
    int cur = 0;      // start at the root
    for (char c : s)      // for every character in the word
    {
  if (!trie[cur][c-CV])    // if this prefix doesn't exist yet
      trie[cur][c-CV] = tlen++;  //   make it
  cur = trie[cur][c-CV];    // go to the new prefix containing the new char
    }
    isend[cur] = 1;      // mark this prefix as the end of a word
}

bool queryWord(const string& s)
{
    int cur = 0;    // start at the root
    for (char c : s)    // for every character in the word
    {
  if (!trie[cur][c-CV])  // if this prefix doesn't exist yet
      return false;  //  rest of word won't exist, return false
  cur = trie[cur][c-CV];  // go there
    }
    return isend[cur];    // check whether the query is a word or just a prefix
}

int main()
{
    printf("`i <word>` to insert, `q <word>` to query\n");
    while (true)
    {
  char c;
  string s;
  cin >> c >> s;
  if (c == 'i')
      insertWord(s);
  else if (c == 'q')
      printf("%s\n", queryWord(s) ? "YES" : "NO");
    }
}


