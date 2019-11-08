/*
ID: spoytie2
TASK: 3276
LANG: C++14                 
*/

/*
 * Problem 3276 (xjoi.net/3276)
 * Created Fri 08 Nov 2019 @ 08:12 (PST)
 * Accepted Fri 08 Nov 2019 @ 08:19 (PST)
 * increasing subseq
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
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("3276.in", "r");
// auto fout = fopen("3276.out", "w+");

const int MAXSZ = 1010;
int arr[MAXSZ];
int dps[MAXSZ];
int n;

int main ()
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    scanf("%d", &arr[i]);
  }

  dps[0] = 1;
  int ret = 1;
  for (int i=1; i<n; ++i)
  {
    for (int j=0; j<i; ++j)
    {
      if (arr[j] < arr[i] && dps[j] > dps[i])
      {
        dps[i] = dps[j];
      }
    }
    ++ dps[i];
    ret = max(ret, dps[i]);
  }

  printf("%d", ret);

  return 0;
}
