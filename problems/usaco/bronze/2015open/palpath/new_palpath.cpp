/*
ID: spoytie2
TASK: palpath
LANG: C++14
*/

/*
 * Problem palpath (usaco/bronze/2015open/palpath)
 * Created Mon 06 Jan 2020 @ 20:13 (PST)
 * Accepted [!meta:end!]
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

const int MAXSZ = 300; // todo
int n;
char farm[MAXSZ][MAXSZ];
unordered_set<string> pals;
unordered_set<string> pals2;

int function_calls = 0; // incremented to 30 for sample test case

void firstWalk(cn  i, cn j, string s)
{
  ++function_calls;
  s = s + string{farm[i][j]}; // add to the tracker
  if (i+j+1 == n) // if on the diagonal
  {
//    fprintf(stderr, " %s", s.c_str());
    pals.insert(s);
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
  if (i+j+1 == n)
  {
    pals2.insert(s);
    return;
  }
  if (i-1>=0)
    secondWalk(i-1, j, s);
  if (j-1>=0)
    secondWalk(i, j-1, s);
}

int compare()
{ // FIX: instead of using unordered_set.erase() in the base case of secondWalk
  ++function_calls;
  int ret=0;
  for (const string &s : pals)
  {
    if (pals2.find(s) != pals2.end())
    {
      ++ret;
    }
  }
  return ret;
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
  //fprintf(stderr, "\n");
  secondWalk(n-1, n-1, "");

  fprintf(fout, "%d\n", compare());

  return 0;
}
