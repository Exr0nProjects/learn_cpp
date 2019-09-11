/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8103 (xjoi.net/8103)
 * Created Wed 11 Sep 2019 @ 08:33 (PDT)
 * Continue Wed 11 Sep 2019 @ 12:04 (PDT)
 * Accepted [!meta:end!]
 * 
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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 5010; // todo
int apples[MAXSZ];

int main ()
{
  int n, s, a, b, ret;
  scanf("%d%d%d%d", &n, &s, &a, &b);
  for (int i=0; i<n; ++i) scanf("%d", &apples[i]);

  for (int cmin=-1; cmin < s; ++cmin)
  {
    int mindx = -1;
    for (int i = 0; i < n; ++i)
    {
      if (mindx == -1 || apples[i] < cmin && apples[i] >= 0)
      {
        cmin = apples[i];
        mindx = i;
      }
    }
    apples[mindx] = -1;
    ++ret;
  }

  return 0;
}
