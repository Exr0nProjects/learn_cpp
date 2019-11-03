/*
ID: spoytie2
TASK: palsquare
LANG: C++14                 
*/

/*
 * Problem palsquare (usaco/training/palsquare)
 * Created Sun 03 Nov 2019 @ 14:12 (PST)
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
auto fin = fopen("palsquare.in", "r");
auto fout = fopen("palsquare.out", "w+");

const int MAXSZ = 1; // todo
int gbase;

char table[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

string conv(int num, cn base) {
  string ret = "";
  while (num)
  {
    ret = ret + table[num%base];
    num %= base;
  }
  return ret;
}

bool check(string s)
{
  for (int i=0; i<s.length(); ++i)
  {
    if (s[i] != s[s.length()-i]) return false;
  }
  return true;
}

int main()
{
  fscanf(fin, "%d", gbase);
  printf("why segfault\n");
  return 0;

  for (int i=1; i<=300; ++i)
  {
    string t = conv(i*i, gbase);
    if (check(t))
    {
      fprintf(fout, "%s %s\n", conv(i, gbase).c_str(), t.c_str());
    }
  }

  return 0;
}
