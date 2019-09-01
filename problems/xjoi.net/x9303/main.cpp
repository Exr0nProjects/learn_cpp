/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 9303 (xjoi.net/9303)
 * Created Sun 01 Sep 2019 @ 15:46 (PDT)
 * Accepted Sun 01 Sep 2019 @ 15:54 (PDT)
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
  int num;
  scanf("%d", &num);

  int d = -num;
  for (int i = num % 10; num != 0; num /= 10, i = num % 10)
  {
    d += (int)pow(i, 3);
  }

  if (d == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
