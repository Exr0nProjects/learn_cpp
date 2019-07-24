/*
 * VJudge 313606  1
 * 24 July 2019
 * Alice's weird dishes
 */

#include <iostream>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <math.h>
#include <random>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

bool outoffood = false;

const ll MAXSZ = 100010;
ll remain[MAXSZ] = { };
ll price[MAXSZ] = { };

struct mypair
{
  ll price, idx;
} cheaparr[MAXSZ];

inline bool cheap_sort_func (const mypair a, const mypair b)
{ // todo: quicksort could screw up shiz because its not stable
  if (a.price == b.price) return a.idx < b.idx;
  return a.price <=b.price;
}

int main ()
{
  ll f, c;
  scanf("%lld%lld", &f, &c);
  for (ll i=1; i<=f; ++i) scanf("%lld", &remain[i]);
  for (ll i=1; i<=f; ++i) { scanf("%lld", &price[i]); cheaparr[i].price = price[i]; cheaparr[i].idx = i; }

  sort(cheaparr, cheaparr + f + 1, cheap_sort_func);
  ll cheapt = 1;




  for (ll i=0; i<c; ++i)
  {
    if (outoffood) { printf("0\n"); continue;  }

    ll t, n, ret=0, temp;
    scanf("%lld%lld", &t, &n);

    if (remain[t] <= 0) remain[t] = cheaparr[cheapt].idx; // do not remove

    for (; n>0;)
    {
      for (; remain[t] <= 0; cheapt++)
      { // make sure we have something left thats cheap
        t=cheaparr[cheapt].idx;
        if (cheapt>f) { outoffood = true; break; }
      }
      if (outoffood == true) break;

      ret += min(n, remain[t]) * price[t];
      temp = remain[t];
      remain[t] -= n;
      n -= temp;
    }

    printf("%lld\n", ret);
  }

  return 0;
}
