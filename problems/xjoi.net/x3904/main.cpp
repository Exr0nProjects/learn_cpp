/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 3904 (xjoi.net/3904)
 * Created Sun 01 Sep 2019 @ 15:56 (PDT)
 * Accepted Sun 01 Sep 2019 @ 16:02 (PDT)
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

int main()
{
  int ba, bb, bc, ca, cb, cc;
  scanf("%d%d%d\n%d%d%d", &ba, &bb, &bc, &ca, &cb, &cc);

  int ret = ca - ba;
  if ((cb * 100 + cc) < (bb * 100 + bc))
    --ret;
  printf("%d", max(ret, -1));
  return 0;
}
