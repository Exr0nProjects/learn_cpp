/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 8102 (xjoi.net/8102)
 * Created Tue 10 Sep 2019 @ 19:37 (PDT)
 * Accepted Wed 11 Sep 2019 @ 06:29 (PDT)
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

const int MAXSZ = 1010; // todo
int board[MAXSZ][MAXSZ];
LL horizontal[MAXSZ];
LL vertical[MAXSZ];

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    horizontal[i] = 0;
    for (int j = 0; j < num; ++j)
    {
      scanf("%d", &board[i][j]);
      horizontal[i] += board[i][j];
      vertical[j] += board[i][j];
    }
  }

  //printf("\n\n"); for (int i=0; i<num; ++i) printf("%3d", horizontal[i]); printf("\n"); for (int i=0; i<num; ++i) printf("%3d", vertical[i]); printf("\n");

  LL big = 0;
  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num; ++j)
    {
      if (board[i][j] == 0) big = max(big, horizontal[i]+vertical[j]);
    }
  }

  if (big == 0)
    printf("Bad Game!");
  else
    printf("%lld", big);

  return 0;
}

/*
4
1 1 1 0
1 1 1 1
1 1 1 1
0 1 1 1
*/
