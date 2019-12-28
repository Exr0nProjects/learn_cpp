/*
ID: spoytie2
TASK: cbarn
LANG: C++14
*/

/*
 * Problem cbarn (usaco/bronze/2016feb/cbarn)
 * Created Sat 28 Dec 2019 @ 13:21 (PST)
 * Accepted [!meta:end!]
 *
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
FILE *fin = fopen("cbarn.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 1100; // todo
ll needed[MAXSZ];
ll n;

ll test(cl start)
{
  ll ans = 0;
  for (int i = 0; i < n; ++i)
  {
    ans += i * needed[(start + i) % n + 1];
    printf("  add: %d, ans: %d\n", (start + i) % n + 1, ans);
  }
  return ans;
}

int main()
{
  if (fin)
  {
    fout = fopen("cbarn.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%lld", &n);
  for (int i = 1; i <= n; ++i)
  {
    fscanf(fin, "%lld", &needed[i]);
  }

  for (int i = 1; i <= n; ++i)
  {
    printf("%3lld", needed[i]);
  }
  printf("\n");

  //printf("%d", test(1)); return 100;

  ll ret = -1;
  for (int i = 0; i < n; ++i)
  {
    if (ret < 0)
      ret = test(i);
    else
      ret = min(ret, test(i));
  }

  fprintf(fout, "%lld\n", ret);

  return 0;
}
