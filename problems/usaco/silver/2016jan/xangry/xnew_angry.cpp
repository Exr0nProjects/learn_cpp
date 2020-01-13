/*
ID: spoytie2
TASK: angry
LANG: C++14
*/

/*
 * Problem angry (usaco/silver/2016jan/angry)
 * Create time: Sun 12 Jan 2020 @ 14:13 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *fin = fopen("angry.in", "r");
FILE *_ = stderr;

const int MAXSZ = 50010; // todo
int N, K;
int pos[MAXSZ];
set<int> exists;

int works(cn r)
{
  //  fprintf(_, "checking if radius %d works...\n", r);
  int leftmost = 0, cows = 0;
  for (; leftmost < N; ++cows)
  {
    //    fprintf(_, "    leftmost cow: %d\n", leftmost);
    if (cows >= K)
      return false;
    int i = 1;
    for (; pos[leftmost + i] <= pos[leftmost] + 2 * r && leftmost + i < N; ++i)
    {
      //      fprintf(_, "        i = %d: pos[leftmost+i]=%d, maxed=%d\n", i, pos[leftmost+i], pos[leftmost]+2*r+1);
    }
    leftmost += i;
  }
  return true;
}

int search(cn low, cn high)
{
  fprintf(_, "search %d..%d, works=%d\n", low, high, works((low + high) / 2));
  if (high <= low)
    return high;

  int mid = (low + high) / 2;
  if (works(mid))
    return search(low, mid);
  else
    return search(mid + 1, high);
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("angry.out", "w+");
  }
  scanf("%d%d", &N, &K);

  int highest = 0;
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &pos[i]);
    highest = max(highest, pos[i]);
  }

  stable_sort(pos, pos + N);

  //  while (1)
  //  {
  //    int d;
  //    cin >> d;
  //    cerr << "works? " << works(d) << endl;
  //  }

  int high = highest / K + 1; // upper bound, covers everything
  int low = 0;

  printf("%d\n", search(low, high));

  return 0;
}

/*
 1 1
 4
 => 0
 
 2 1
 4 5
 => 1
 
 3 2
 5
 4
 8
 => 1
 
 2 1
 1
 4
 => 2
 */
