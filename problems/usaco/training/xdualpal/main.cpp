/*
ID: spoytie2
TASK: dualpal
LANG: C++14                 
*/

/*
 * Problem dualpal (usaco/training/dualpal)
 * Created Sun 03 Nov 2019 @ 16:36 (PST)
 * Accepted Sun 03 Nov 2019 @ 17:03 (PST)
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
auto fin = fopen("dualpal.in", "r");
auto fout = fopen("dualpal.out", "w+");

const int MAXSZ = 1; // todo
int n, s;

string conv(int num, cn base)
{
  string ret = "";
  for (; num;)
  {
    ret = to_string(num%base) + ret;
    num /= base;
  }
  return ret;
}

bool check(string s)
{
  for (int i=0; i<s.length(); ++i)
  {
    if (s[i] != s[s.length()-i-1]) return false;
  }
  return true;
}

int main ()
{
  fscanf(fin, "%d%d", &n,  &s);
 // printf("%d", check("1221")); return 0;

  for (int c=s+1, i=0; i<n; ++c)
  {
    int legit = 0;
    for (int b=2; b<11; ++b)
    {
      if (check(conv(c, b))) ++legit;
      if (legit == 2) break;
    }
    if (legit >= 2)
    {
      fprintf(fout, "%d\n", c);
      ++ i;
    }
  }

  return 0;
}
