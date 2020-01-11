/*
ID: spoytie2
TASK: div7
LANG: C++14
*/

/*
 * Problem div7 (usaco/silver/2016jan/div7)
 * Create time: Sat 11 Jan 2020 @ 08:55 (PST)
 * Accept time: [!meta:end!]
 *
 * Note: this algorithm is actually O(n) because its complexity is the sum of all numbers from 1 to n
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *fin = fopen("div7.in", "r");
//FILE *_ = stderr;

const int MAXSZ = 50010; // todo
int N;
ll sum[MAXSZ]; // FIX: change to long long

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("div7.out", "w+");
  }
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
  {
    int d;
    scanf("%d", &d);
    if (i > 0)
      sum[i] = sum[i - 1];
    sum[i] += d;
  }

  //  for (int i=0; i<=N; ++i)
  //    fprintf(_, "%3lld", sum[i]);
  //  fprintf(_, "\n");

  for (int span = N; span > 0; --span)
  {
    for (int start = 0; start + span <= N; ++start)
    {
      //      fprintf(_, "%d..%d: %d\n", start, start+span, sum[start+span]-sum[start]);
      if ((sum[start + span] - sum[start]) % 7 == 0)
      {
        printf("%d\n", span);
        return 0;
      }
    }
  }

  printf("0\n");
  return 0;
}
