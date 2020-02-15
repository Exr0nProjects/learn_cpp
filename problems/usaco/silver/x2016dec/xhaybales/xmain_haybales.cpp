/*
ID: spoytie2
TASK: haybales
LANG: C++14
*/

/*
 * Problem haybales (usaco/silver/2016dec/haybales)
 * Create time: Wed 15 Jan 2020 @ 20:46 (PST)
 * Accept time: Wed 15 Jan 2020 @ 20:57 (PST)
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
FILE *fin = fopen("haybales.in", "r");
FILE *_ = stderr;

const int MAXSZ = 100010; // todo
int N, Q;
int bales[MAXSZ];


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("haybales.out", "w+"); }
  scanf("%d%d", &N, &Q);
  for (int i=0; i<N; ++i)
  {
    scanf("%d", &bales[i]);
  }
  
  stable_sort(bales, bales+N); // ! FIX: forgot to sort at first
  
  for (int i=0; i<Q; ++i)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    int li = lower_bound(bales, bales+N, l)-bales;
    int ri = upper_bound(bales, bales+N, r)-bales;
//    if (bales[ri] == r) ++ri;
    printf("%d\n", ri-li);
  }

  return 0;
}

/*
 5 1
 3 2 7 5 7
 2 5
 => 3
 */
