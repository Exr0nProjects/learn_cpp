/*
ID: spoytie2
TASK: namenum
LANG: C++14
*/

/*
 * Problem [!meta:pid!] (usaco/training/namenum)
 * Created Sun 27 Oct 2019 @ 17:28 (PDT)
 * Accepted [!meta:end!]
 *
 */

#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 30; // todo
long long n, debugcount = 0;
struct TrieNode
{
  char v;
  bool leaf = false;
  map<char, TrieNode> c; // each capital letter
  TrieNode() { v = NULL; }
  TrieNode(const char _v) { v = _v; }
  bool operator< (const TrieNode &o) const
  { return v < o.v; }
} root;

void printTrie(const TrieNode &c = root, cn l = 1)
{
  for (int i = 0; i < l; ++i)
    printf("| ");
  printf("%c\n", c.v);
  printf("recursing\n");
  for (auto &p : c.c)
  {
    printf("next up: %c\n", p.first);
    printTrie(p.second, l+1);
  }
}

inline pair<char, TrieNode> make (const char &c)
{
  return pair<char, TrieNode>{c, TrieNode{c}};
}

void dfs(string n)
{
}

int main()
{
  auto fin = fopen("namenum.in", "r");
  auto fout = fopen("namenum.out", "w+");

  char t[20];
  fscanf(fin, "%s", t);

  auto dict = fopen("dict.txt", "r"); // todo: space seperated? assuming newline
  
  char c, prevc = '@';
  TrieNode *p = &root;
  for (fscanf(dict, "%c", &c); c; fscanf(dict, "%c", &c))
  {
    if (c == '\n')
    {
      if (prevc == '\n')
      {
        break;
      }
      else
      {
        p->leaf = true;
        continue;
      }
    }
    prevc = c;
    if (p->c.find(c) == p->c.end())
    {
      p->c.insert(make(c));
    }
    p = &(p->c[c]); // move on
  }

  printf("finished input of dict!\n");

  return 0;

  printTrie();

  return 0;

  printTrie();
  
  return 0;

  dfs(t);

  return 0;
}
