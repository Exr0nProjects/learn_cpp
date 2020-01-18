/*
ID: spoytie2
TASK: cowdance
LANG: C++14
*/

/*
 * Problem cowdance (usaco/silver/2017jan/cowdance)
 * Create time: Fri 17 Jan 2020 @ 16:09 (PST)
 * Accept time: [!meta:end!]
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
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <cstring>
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
FILE *fin = fopen("cowdance.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10010; // todo
int N, T;
int dur[MAXSZ];

int perform(cn k)
{ // klogk + nlogn
  priority_queue<int, deque<int>, greater<int>> pq;
  for (int i=0; i<k; ++i) pq.push(0);
  for (int i=1; i<=N && !pq.empty(); ++i)
  {
//    printf("is pq empty? %d, i=%d\n", pq.empty(), i);
    int n = pq.top() + dur[i];
    pq.pop(); // hecka slow, these lines should be combinable
    pq.push(n);
  }
  
  int ret=0;
  for (; !pq.empty(); pq.pop())
  {
//    printf("%3d", pq.top());
//    printf("\n");
    ret = pq.top();
  }
  fprintf(_, "Stage of size %d -> %d\n", k, ret);
  return ret;
}

int binarySearch(cn l, cn r)
{
  fprintf(_, "binary search %d : %d\n", l, r);
  if (l+1 >= r) return l;
  int m = (l+r)/2;
  int cmp = perform(m);
  if (cmp > T) return binarySearch(m+1, r);
  else return binarySearch(l, m);
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cowdance.out", "w+"); }
  scanf("%d%d", &N, &T);
  for (int i=1; i<=N; ++i)
  {
    scanf("%d", &dur[i]);
  }

  printf("%d\n", binarySearch(1, N));
//  printf("%d\n", perform(1));

  return 0;
}

/*
 6 6
 1 1 1 1 1 1
 => 1
 */
