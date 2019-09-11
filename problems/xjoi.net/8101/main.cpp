/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8101 (xjoi.net/8101)
 * Created Tue 10 Sep 2019 @ 18:57 (PDT)
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

const int MAXSZ = 100010; // todo
int boxes[MAXSZ];

int main ()
{
  int num, mmax, ret=0;
  scanf("%d%d", &num, &mmax);
  for (int i=0; i<num; ++i) scanf("%d", &boxes[i]);
  for (int i=0; i<num-1; ++i) boxes[i] += boxes[i+1];
  for (int i=0; i<num-2; ++i)
  {
    if (boxes[i] > mmax)
    {
      ++ret;
      --boxes[i];
    }
  }

  printf("%d", ret);

  return 0;
}
