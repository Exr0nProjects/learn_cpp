/*
ID: spoytie2
TASK: hps
LANG: C++14
*/

/*
 * Problem hps (usaco/bronze/2017jan/hps)
 * Created Sun 29 Dec 2019 @ 11:16 (PST)
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
FILE *fin = fopen("hps.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int pa[MAXSZ], pb[MAXSZ];
int n;

int test(int mp[])
{
  int ret = 0;
  for (int i=0; i<n; ++i)
  {
    fprintf(_, "%d, %d\n", (mp[pa[i]-1] + 1) % 3, mp[pb[i]-1]);
    if ((mp[pa[i]-1] + 1) % 3 == (mp[pb[i]-1])%3) ++ret; // FIX: used to be `mp[pa[i]-1] + (1%3)`
  }
  fprintf(_, "total: %d\n", ret);
  return ret;
}

int main ()
{
  if (fin) { stdin = fin, stdout = fopen("hps.out", "w+"); }
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    scanf("%d%d", &pa[i], &pb[i]);
  }
  
  int ret=0;
  
  int opts[] = {0, 1, 2};
  for (int i : opts)
    for (int j : opts)
    {
      if (j == i) continue;
      for (int k : opts)
      {
        if (k == j || k == i) continue;
        int mp[3] = {i, j, k};
        ret = max(ret, test(mp));
      }
    }
  
  printf("%d\n", ret);

  return 0;
}

/*
5
1 2
1 2
1 2
1 2
2 1
 => 4
 
3
 1 2
 2 3
 3 1
 */
