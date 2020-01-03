/*
ID: spoytie2
TASK: 1
LANG: C++14
*/

/*
 * Problem 1 (onlinejudge/dp/1)
 * Created Thu 02 Jan 2020 @ 15:44 (PST)
 * Accepted [!meta:end!]
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=944
 * 10003 - Cutting Sticks
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
FILE *fin = fopen("1.in", "r");
FILE *_ = stderr;

const int MAXSZ = 60; // todo
int l, n;
vector<int> cuts;
int tabu[MAXSZ][MAXSZ];

int cutStick(cn l, cn r, cn step = 0)
{
  if (tabu[l][r] >= 0)
    return tabu[l][r];
  // for (int i = 0; i < step; ++i)
  //   cerr << "  ";
  // cerr << "cutStick called on a stick of len " << cuts[r] - cuts[l] << " and " << l << ", " << r << endl;
  if (l >= r - 1)
    return 0;
  int ret = 0x7FFFFFF;
  for (int i = l + 1; i < r; ++i)
  {
    ret = min(ret, cutStick(l, i, step + 1) + cutStick(i, r, step + 1));
  }
  ret += (cuts[r] - cuts[l]);
  tabu[l][r] = ret;
  return ret;
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("1.out", "w+");
  }

  for (; true;)
  {
    scanf("%d", &l);
    if (l == 0)
      break;
    scanf("%d", &n);
    cuts = vector<int>(1, 0);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < MAXSZ; ++j)
      {
        tabu[i][j] = -1;
      }
      int d;
      scanf("%d", &d);
      cuts.push_back(d);
    }
    cuts.push_back(l);
    printf("The minimum cutting is %d.\n", cutStick(0, cuts.size() - 1));
  }

  return 0;
}
