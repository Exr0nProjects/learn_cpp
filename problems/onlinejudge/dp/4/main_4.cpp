/*
ID: spoytie2
TASK: 4
LANG: C++14
*/

/*
 * Problem 4 (onlinejudge/dp/4)
 * Created Fri 03 Jan 2020 @ 11:30 (PST)
 * Accepted [!meta:end!]
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=847&page=show_problem&problem=378
 * 437 - The Tower of Babylon
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
FILE *fin = fopen("4.in", "r");
FILE *_ = stderr;

const int MAXSZ = 40; // todo
int N=1, kase;

struct Block
{
  int a, b, c;
} blocks[MAXSZ];

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("4.out", "w+"); }

  for (kase=1; N>0; ++kase)
  {
    scanf("%d", &N);
    for (int n=0; n<N; ++n)
    {
      scanf("%d%d%d", &blocks[n].a, &blocks[n].b, &blocks[n].c);
    }
  }

  return 0;
}
