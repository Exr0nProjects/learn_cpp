/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8102 (xjoi.net/8102)
 * Created Tue 10 Sep 2019 @ 19:37 (PDT)
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

const int MAXSZ = 1; // todo
int board[MAXSZ][MAXSZ];

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num; ++j)
    {
      scanf("%d", &board[i][j]);
    }
  }

  return 0;
}
