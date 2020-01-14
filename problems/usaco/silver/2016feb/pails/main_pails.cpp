/*
ID: spoytie2
TASK: pails
LANG: C++14
*/

/*
 * Problem pails (usaco/silver/2016feb/pails)
 * Create time: Tue 14 Jan 2020 @ 07:11 (PST)
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
FILE *fin = fopen("pails.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int mem[MAXSZ][MAXSZ][MAXSZ];
int a, b, K, M;

int recurse(cn i, cn j, cn k) // i = milk in a, j = milk in b, k = steps remaining + fencepost corrections
{
  if (mem[i][j][k] > 0) return mem[i][j][k];
  
  if (k == 1) return abs(i + j - M);

  int ret = INT32_MAX;
  // do nothing
  ret = min(ret, recurse(i, j, k-1));
  // empty one of the buckets
  ret = min(ret, min(
    recurse(0, j, k-1),
    recurse(i, 0, k-1)
  ));
  // fill one of the buckets
  ret = min(ret, min(
    recurse(a, j, k-1),
    recurse(b, j, k-1)
  ));
  // pour one into the other
  ret = min(ret, min(
    recurse(min(a, i+j), max(j-(a-i), 0), k-1), // b into a
    recurse(max(i-(b-j), 0), min(b, j+i), k-1)
  ));
  
  mem[i][j][k] = ret;
  return ret;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("pails.out", "w+"); }

//  for (;1;) // test pour math
//  {
//    int i, j;
//    scanf("%d%d%d%d", &a, &b, &i, &j);
//    printf("pour b -> a = %d, %d\n", max(i-(b-j), 0), min(b, j+i));
//  }

  scanf("%d%d%d%d", &a, &b, &K, &M);

  printf("%d\n", recurse(0, 0, K));

  return 0;
}


/*
 pouring math test
 1 1 0 0 => 0 0
 1 1 1 1 => 1 1
 14 50 0 50 => 14, 36
 10 10 5 5 => 10 0
 10 10 7 5 => 10 2
 10 10 7 1 => 8 0
 10 10 9 10 => 10 9
 10 10 10 5 => 10 5
 */
