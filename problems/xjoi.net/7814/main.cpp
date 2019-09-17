/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 7814 (xjoi.net/7814)
 * Created Sun 15 Sep 2019 @ 13:55 (PDT)
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

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 10; // todo
bool digits[MAXSZ];
int p = 0;

int dfs (const int r=1)
{
  static int count = 0;
  if (r == 3)
  {
    ++count;
    return count;
  }
  for (int i=1; i<9; ++i)
  {
    if (digits[i]) continue;
    digits[i] = true;
    for (int j=1; j<9; ++j)
    {
      if (digits[j]) continue;
      digits[j] = true;
      for (int k=1; k<9; ++k)
      {
        if (digits[k]) continue;
        digits[k] = true;
        if (r == 1 || r*p == 100*i+10*j+k)
        {
          dfs(r+1);
        }
        digits[k] = false;
      }
      digits[j] = false;
    }
    digits[i] = false;
  }
  return count;
}

int main ()
{
  printf("%d", dfs());

  return 0;
}
