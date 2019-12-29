/*
ID: spoytie2
TASK: blocks
LANG: C++14
*/

/*
 * Problem blocks (usaco/bronze/2016dec/blocks)
 * Created Sun 29 Dec 2019 @ 10:17 (PST)
 * Accepted Sun 29 Dec 2019 @ 10:34 (PST)
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
FILE *fin = fopen("blocks.in", "r");
FILE *_ = stderr;

const int MAXSZ = 26; // todo
int count1[MAXSZ+4];
int count2[MAXSZ+4];
int ret[MAXSZ+4];
int n;


int main ()
{
  if (fin != NULL) { stdin = fin, stdout = fopen("blocks.out", "w+"); }
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    // get sides
    char s1[MAXSZ], s2[MAXSZ];
    scanf("%s%s", s1, s2);
    // count them
    for (int i=0; s1[i] != '\0'; ++i) // FIX: Had to change from strlen because strlen was not defined on usaco servers
      ++count1[s1[i]-'a'];
    for (int i=0; s2[i] != '\0'; ++i)
      ++count2[s2[i]-'a'];
    for (int i=0; i<MAXSZ; ++i)
    {
      ret[i] += max(count1[i], count2[i]);
      count1[i] = count2[i] = 0; // FIX: need to reset counters 
    }
  }

  for (int i=0; i<MAXSZ; ++i)
    printf("%d\n", ret[i]);

  return 0;
}

/*
 3
 fox box
 dog cat
 car bus
 
 */
