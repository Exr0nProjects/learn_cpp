// jan 2015 bronze whatbase, brute force O(n^2) 1/11

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
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
 auto fin = fopen("whatbase.in", "r");
 auto fout = fopen("whatbase.out", "w+");

const int MAXSZ = 15010; // todo
int n;

LL conv(char n[], cn l, cn b)
{
  if (l == 1) return n[0];
  return b*conv(n, l-1, b) + n[l-1];
}

map<int, string> tabulate;
string solve(char a[], char b[])
{
  int hash = a[0]*pow(10, 5) + a[1]*pow(10, 4); + a[2]*1000 + b[0]*100 + b[1]*10 + b[2];
  if (tabulate.find(ans) != tabulate.end()) return *ans;

  string ret;
  for (int i=10; i<MAXSZ; ++i)
  {
    if (s.length()) break;
    for (int j=10; j<MAXSZ; ++j)
    {
   //d*/   printf("%7lld->%10lld, %7lld->%10lld\n", i, conv(a, 3, i), j, conv(b, 3, j));
      if (conv(a, 3, i) == conv(b, 3, j))
      {
        ret = to_string(i) + " " + to_string(j);
        break;
      }
    }
  }
  tabulate[hash] = ret;
  return ret;
}

int main ()
{
//  int nuu[] = {4, 1, 9};
//  printf("%d", conv(nuu, 3, 47));
//  return 0;
  
  fscanf(fin, "%d", &n);
  for (int i=0; i<n; ++i)
  {
    char a[5], b[5];
    fscanf(fin, "%s%s", a, b);
    for (int j=0; j<3; ++j)
    {
      a[j] -= '0';
      b[j] -= '0';
    }
    //d*/ for (int i=0; i<5; ++i) printf("%3d", a[i]); printf("\n"); for (int i=0; i<5; ++i) printf("%3d", b[i]); printf("\n");
    fprintf(fout, "%s\n", solve(a, b).c_str());
  }

  return 0;
}

/*
5
419 792
419 792
419 792
419 792
419 792
 */
