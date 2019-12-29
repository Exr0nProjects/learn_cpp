/*
ID: spoytie2
TASK: hps
LANG: C++14
*/

/*
 * Problem hps (usaco/bronze/2017jan/hps)
 * Created Sun 29 Dec 2019 @ 11:16 (PST)
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
FILE *fin = fopen("hps.in", "r");
FILE *_ = stderr;

const int MAXSZ = 5; // todo
int matches[MAXSZ][MAXSZ];
int n;

int main ()
{
  if (fin) { stdin = fin, stdout = fopen("hps.out", "w+"); }
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    ++matches[a][b];
  }
  
  printf("%d\n", max( matches[1][2] + matches[2][3] + matches[3][1],
                      matches[2][1] + matches[3][2] + matches[1][3]));

  return 0;
}

/*
5
1 2
1 2
1 2
1 2
2 1
 => 4
 
3
 1 2
 2 3
 3 1
 */
