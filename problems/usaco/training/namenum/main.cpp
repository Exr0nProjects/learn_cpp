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
  TrieNode *c[MAXSZ] = {}; // each capital letter
  TrieNode() { v = NULL; }
  TrieNode(const char _v) { v = _v; }
} root;

void printTrie(TrieNode *c = &root, cn l = 0)
{
  for (int i = 0; i < l; ++i)
    printf("| ");
  printf("%c", c->v);
  for (int i = 0; i < MAXSZ; ++i)
  {
    if (c->c[i])
      printTrie(c->c[i], l + 1);
  }
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
  
  char c;
  TrieNode *p = &root;
  for (fscanf(dict, "%c", &c); c; fscanf(dict, "%c", &c))
  {
    fprintf(fout, "%c", c); if (debugcount > 10) { return 0; } else { ++debugcount; }
    if (c == '\n')
    {
      fprintf(fout, "newline reached!");
      p->leaf = true;
      p = &root;
      continue;
      return 0;
    }
    if (!p->c[c - 'A'])
    {
      fprintf(fout, "new name char! %c\n", c);
      p->c[c - 'A'] = new TrieNode(c);
    }
    p = p->c[c - 'A'];
  }

  return 0;

  printTrie();
  
  return 0;

  dfs(t);

  return 0;
}
