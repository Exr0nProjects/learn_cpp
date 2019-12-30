/*
ID: spoytie2
TASK: diamond
LANG: C++14
*/

/*
 * Problem diamond (usaco/bronze/2016open/diamond)
 * Created Mon 30 Dec 2019 @ 11:45 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("diamond.in", "r");
FILE *_ = stderr;

const int MAXSZ = 1010; // todo
int sizes[MAXSZ];
int N, K;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("diamond.out", "w+"); }
  scanf("%d%d", &N, &K);
  for (int i=0; i<N; ++i)
  {
    scanf("%d", &sizes[i]);
  }
  
  sort(sizes, sizes+N); // we will treat each diamond as the lower bound

  int ret=0;
  for (int i=0; i<N; ++i)
  {
    int tmp = 1; // for the sizes[i] diamond
    for (int j=i+1; j<N && sizes[i] + K >= sizes[j]; ++j)
    {
      ++tmp;
    }
    ret = max(ret, tmp);
  }

  printf("%d\n", ret);

  return 0;
}
