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

const int MAXSZ = 1; // todo
long long n;
struct TrieNode
{
  bool leaf=false;
  TrieNode* c[30] = {}; // each capital letter
} root;

void dfs(string n)
{
  
}

int main ()
{
  auto fin = fopen("namenum.in", "r");
  auto fout = fopen("namenum.out", "w+");

  auto dict = fopen("dict.txt", "r"); // todo: space seperated? assuming newline
  char c;
  TrieNode* p = &root;
  for (fscanf(fin, "%c", &c); c; fscanf(fin, "%c", &c))
  {
    if (c == '\n')
    {
      p->leaf = true;
      p = &root;
      continue;
    }
    if (! p->c[c-'A']) p->c[c-'A'] = new TrieNode();
    p = p->c[c-'A'];
  }

  char t[20];
  fscanf(fin, "%s", t);

  dfs(t);

  return 0;
}
