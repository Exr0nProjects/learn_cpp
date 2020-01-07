/*
ID: spoytie2
TASK: family
LANG: C++14
*/

/*
 * Problem family (usaco/bronze/2018open/family)
 * Created Mon 06 Dec 2019 @ 18:32 (PST)
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
FILE *fin = fopen("family.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N, m, k, next_free=1;
bool used_cow[MAXSZ];
bool used_pos[MAXSZ];

int pos_fixed[MAXSZ]; // pos_fixed[i] = the position of cow i if it is fixed
int hierarchy[MAXSZ];

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("family.out", "w+");
  }

  scanf("%d%d%d", &N, &m, &k);
  for (int i=1; i<=m; ++i)
  {
    scanf("%d", &hierarchy[i]);
  }
  for (int i=1; i<k; ++i)
  {
    int c, p;
    scanf("%d%d", &c, &p);
    used_cow[c] = used_pos[p] = true;
    pos_fixed[c] = p;
  }

  return 0;
}
