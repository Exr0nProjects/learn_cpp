/*
ID: spoytie2
TASK: div7
LANG: C++14
*/

/*
 * Problem div7 (usaco/silver/2016jan/div7)
 * Create time: Sun 12 Jan 2020 @ 16:57 (PST)
 * Accept time: Sun 12 Jan 2020 @ 17:29 (PST)
 *
 * Note: this algorithm is actually O(n) because its complexity is the sum of all numbers from 1 to n
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
FILE *fin = fopen("div7.in", "r");
//FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
int low[7];
int high[7]; // high[i] is the highest index in the input where the prefix sum is i (mod 7)

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("div7.out", "w+");
  }
  scanf("%d", &N);
  int pfs = 0; // prefix sum
  for (int i = 1; i <= N; ++i)
  {
    int d;
    scanf("%d", &d);
    pfs = (pfs + d) % 7;
    if (!low[pfs])
      low[pfs] = i; // no need to min because i only gets bigger, so only save the first one
    high[pfs] = i;  // no need to max because i only gets bigger
  }

  //  for (int i=0; i<=N; ++i)
  //    fprintf(_, "%3lld", sum[i]);
  //  fprintf(_, "\n");

  int ret = 0;
  for (int i = 0; i < 7; ++i)
  {
    if (high[i] > 0)                    // upper exists
      ret = max(ret, high[i] - low[i]); // if two prefix sums are the same mod seven, the segment between them must be a multiple of seven.
  }

  printf("%d\n", ret);
  return 0;
}

/*
 1
 7
 => 1
 
 2
 3 4
 => 2
 
 4
 1 3 4 5
 => 2
 */
