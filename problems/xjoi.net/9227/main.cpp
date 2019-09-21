/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 9227 (xjoi.net/9227)
 * Created Sat 21 Sep 2019 @ 12:05 (PDT)
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

const int MAXSZ = 1010; // todo
bool trees[MAXSZ];

int main ()
{
  int l, n;
  scanf("%d%d", &l, &n);

  for (int i=0; i<n; ++i)
  {
    int a, b, c=0;
    scanf("%d%d", &a, &b);
    for (int j=a; j<=b; ++j)
    {
      if (!trees[j]) ++c;
      trees[j] = true;
    }
    printf("%d\n", c);
  }

  return 0;
}
