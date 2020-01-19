/*
ID: spoytie2
TASK: cowdance
LANG: C++14
*/

/*
 * Problem cowdance (usaco/silver/2017jan/cowdance)
 * Create time: Fri 17 Jan 2020 @ 16:09 (PST)
 * Accept time: Fri 17 Jan 2020 @ 18:27 (PST)
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
int dummy[MAXSZ];

ll perform(cn k)
{ // klogk + nlogn
  priority_queue<ll, deque<ll>, greater<ll>> pq;
  for (int i=0; i<k; ++i) pq.push(0);
  for (int i=1; i<=N && !pq.empty(); ++i)
  {
//    printf("is pq empty? %d, i=%d\n", pq.empty(), i);
    ll n = pq.top() + dur[i];
    pq.pop(); // hecka slow, these lines should be combinable
    pq.push(n);
  }
  
  ll ret=0;
  for (; !pq.empty(); pq.pop())
  {
//    printf("%3d", pq.top());
//    printf("\n");
    ret = pq.top();
  }
//  fprintf(_, "Stage of size %d -> %d\n", k, ret);
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

bool cmp(cn i, cn v)
{
  return perform(i) < v;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cowdance.out", "w+"); }
  scanf("%d%d", &N, &T);
  for (int i=1; i<=N; ++i)
  {
    scanf("%d", &dur[i]);
  }

  // These two lines work in place of binary search but result in N^2 log N instead of N log^2 N
  // int ans=1;
  // while (perform(ans) > T) ++ans;

  // int ans = binarySearch(1, N);
  // while (perform(ans-1) <= T) -- ans; // overshot
  // while (perform(ans) > T) ++ ans; // undershot // FIX: Sometimes this was the case, so I had to add this condition to meet the final two test cases.

  iota(dummy, dummy+N, 1);
  int ans = lower_bound(dummy, dummy+N, T, cmp);

  printf("%d\n", min(N, ans));
//  printf("%d\n", perform(1));

  return 0;
}

/*
 6 6
 1 1 1 1 1 1
 => 1
 
 0 10
 => 0
 
 6 1
 1 1 1 1 1 1
 => 6
 */
