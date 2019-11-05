/*
ID: spoytie2
TASK: barn1
LANG: C++14                 
*/

/*
 * Problem barn1 (usaco/training/barn1)
 * Created Tue 05 Nov 2019 @ 07:54 (PST)
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
auto fin = fopen("barn1.in", "r");
auto fout = fopen("barn1.out", "w+");

const int MAXSZ = 210; // todo
int m, s, c;

int stalls[MAXSZ];
bool covered[MAXSZ];

int main ()
{
  fscanf(fin, "%d%d%d", &m, &s, &c);
  for (int i=1; i<=c; ++i)
  {
    int a;
    fscanf(fin, "%d", &a);
    stalls[a] = -1;
  }
  for (int i=1; i<=s; ++i)
  {
    ++stalls[i];
  }

  auto cmp = [](cn l, cn r) { return stalls[l] > stalls[r]; };
  priority_queue<int, deque<int>, function<bool(int, int)> > pq(cmp);

  int ccount = 0;
  for (int i=1; i<=c; ++i) // cover all w/ a board and preprocess empties
  {
    if (stalls[i] == 0)
    {
      ++ccount;
      covered[i] = true;
      if (i != 1) pq.push(i-1);
    }
    else
    {
      stalls[i] = stalls[i-1] + 1;
    }
    
    if (ccount && ccount < c) covered[i] = true;
  }

  // todo: select next largest gap from pq and uncover it
  

  return 0;
}
