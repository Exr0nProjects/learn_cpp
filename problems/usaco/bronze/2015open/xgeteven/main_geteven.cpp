/*
ID: spoytie2
TASK: geteven
LANG: C++14
*/

/*
 * Problem geteven (usaco/bronze/2015open/geteven)
 * Created Fri 13 Dec 2019 @ 19:32 (PST)
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
#define ca const auto &
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("geteven.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 30; // todo
int n;
vector<int> maps[MAXSZ];
int evens[MAXSZ];

int findEvens(vector<char> st, cn c=0, cn s=0)
{
  //d*/printf("called with size %d\n", st.size());
  if (s == st.size())
  {
    printf("reached end, c=%d\n", c);
    return (c+1) % 2;
  }
  int ret = 0;
  //d*/printf(to_string(maps[st[s]-'A'][0]).c_str());
  for (int i:maps[st[s]-'A'])
  {
    printf("setting %c to %d\n", s, i);
    ret += findEvens(st, c+i, s+1);
  }
  return ret;
}

int findLen(vector<char> st)
{
  int ret=0;
  for (char c : st)
  {
    ret += maps[c].size();
  }
  return ret;
}

int main ()
{
  if (fin) { fout = fopen("geteven.out", "w+"); } else { fin = stdin; fout = stdout; }
  
  fscanf(fin, "%d", &n);

  int A=0, B=0, C=0;
  int nA=0, nB=0, nC=0;

  for (int i=0; i<n; ++i)
  {
    char c; int t;
    fscanf(fin, "\n%c%d", &c, &t);
    maps[c-'A'].push_back(t);
  }

  A = findEvens(vector<char>{'B', 'I'});
  B = findEvens(vector<char>{'G', 'O', 'E', 'S'});
  C = findEvens(vector<char>{'M'});
  printf("evens: A=%d, B=%d, C=%d\n", A, B, C);

  nA = findLen({'B', 'I'}) - A;
  nB = findLen({'G', 'O', 'E', 'S'}) - B;
  nC = findLen({'M'}) - C;
  printf("nons: A=%d, B=%d, C=%d\n", nA+A, nB+B, nC+C);

  fprintf(fout, "%d\n", nA*nB + nB*nC + nC*nA + nA + nB + nC + A*B*C); // first three: only one part is even, second three: two parts are even, last: all are even

  return 0;
}
