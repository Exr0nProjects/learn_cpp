/*
ID: spoytie2
TASK: 1
LANG: C++14
*/

/*
 * Problem 1 (contests/dev.xjoi/dev.xjoi-1351/1)
 * Created Sat 28 Dec 2019 @ 17:51 (PST)
 * Accepted [!meta:end!]
 * prime number sieve
 */

#include <bits/stdc++.h>

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
FILE *fin = fopen("1.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 100010; // todo
bool nums[MAXSZ];


int main ()
{
  if (fin) { fout = fopen("1.out", "w+"); } else { fin = stdin; fout = stdout; }

  int n;
  scanf("%d", &n);
  for (int i=2; i<n; ++i)
  {
    if (! nums[i])
    {
      printf("%d ", i);
      for (int j=2*i; j<n; j += i)
      {
        nums[j] = true;
      }
    }
  }

  return 0;
}
