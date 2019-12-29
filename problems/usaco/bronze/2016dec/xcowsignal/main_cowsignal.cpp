/*
ID: spoytie2
TASK: cowsignal
LANG: C++14
*/

/*
 * Problem cowsignal (usaco/bronze/2016dec/cowsignal)
 * Created Sun 29 Dec 2019 @ 10:34 (PST)
 * Accepted [!meta:end!]
 *
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
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
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
FILE *fin = fopen("cowsignal.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10; // todo
int M, N, K;

void amplify(char buf[])
{
  for (int i=0; i<K; ++i)
  {
    for (int c=0; c<N; ++c)
      for (int j=0; j<K; ++j)
      {
        printf("%c", buf[c]);
      }
    printf("\n");
  }
}

int main ()
{
  if (fin) { stdin = fin, stdout = fopen("cowsignal.out", "w+"); }
  scanf("%d%d%d", &M, &N, &K);
  for (int i=0; i<M; ++i)
  {
    char buf[MAXSZ+10];
    scanf("%s", buf);
    amplify(buf);
  }

  return 0;
}
