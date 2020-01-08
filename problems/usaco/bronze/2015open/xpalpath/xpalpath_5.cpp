/*
ID: spoytie2
TASK: palpath
LANG: C++14
*/

/*
 * Problem palpath (usaco/bronze/2015open/palpath)
 * Created Mon 06 Jan 2020 @ 21:14 (PST)
 * Accepted Tue 07 Jan 2020 @ 19:44 (PST)
 * This is a copy of palpath_3, with the fatal flaw fixed (where in the second dfs, if a palendrome was not found then it kept going instead of stopping on the diagonal)
 * It fixes the bug where it thinks there are palendromes when the two segments end in different places
 */

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
#include <unordered_set>
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
FILE* fin = fopen("palpath.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 30; // todo
int n, ret=0;
char farm[MAXSZ][MAXSZ];
set<pair<int, string> > pals; // FIX: check ending location of each string, only need one int because the string can only end on a diagonal, where each location on the diagonal is gaurenteed to have distinct x and y values
unordered_set<string> final_sift;

int function_calls = 0; // incremented to 62 for sample case, more than double the new version... why?

void firstWalk(cn  i, cn j, string s)
{
  ++function_calls;
  s = s + string{farm[i][j]};
  if (i+j+1 == n)
  {
    fprintf(stderr, "first: %d %s\n", i, s.c_str());
    pals.insert(make_pair(i, s));
    return;
  }
  if (i+1<n)
    firstWalk(i+1, j, s);
  if (j+1<n)
    firstWalk(i, j+1, s);
}

void secondWalk(cn i, cn j, string s)
{
  ++function_calls;
  s =  s + string{farm[i][j]};
  if (i+j+1 == n) // FIX: this also would've solved the problem, although a little less percisely
  {
    auto search = make_pair(i, s);
    if (pals.find(search) != pals.end())
    {
      pals.erase(search);
      final_sift.insert(s);
      fprintf(stderr, "secnd: %d %s\n", i, s.c_str());
      ++ret;
    }
    return; // FIX: return even when we don't find a palendrome, because otherwise we start going past the diagonal and don't recover until we hit the top corner!
  }
  if (i-1>=0)
    secondWalk(i-1, j, s);
  if (j-1>=0)
    secondWalk(i, j-1, s);
}

int main ()
{
  if (fin) { fout = fopen("palpath.out", "w+"); } else { fin = stdin; fout = stdout; }

  fscanf(fin, "%d", &n);
  for (int i=0; i<n; ++i)
  {
    fscanf(fin, "\n");
    for (int j=0; j<n; ++j)
    {
      fscanf(fin, "%c", &farm[i][j]);
    }
  }
  
  firstWalk(0, 0, "");
  fprintf(stderr, "\n");
  secondWalk(n-1, n-1, "");

  fprintf(fout, "%d\n", final_sift.size());

  return 0;
}

/*
 count distinct palendromes, not paths
 3
 ABC
 DEB
 FBA
 => 2
 
 count connected paths
 4
 AAAA
 BCDE
 FGHI
 AAAA
 => 0
 
 4
 AAAB
 CDEF
 GHIJ
 KAAA
 => 0
 
 dont overcount different unconnected paths
 3
 ABC
 DCB
 EFA
 => 1
 */
