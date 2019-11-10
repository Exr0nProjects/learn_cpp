/*
ID: spoytie2
TASK: crypt1
LANG: C++14                 
*/

/*
 * Problem crypt1 (usaco/training/crypt1)
 * Created Sun 10 Nov 2019 @ 08:58 (PST)
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
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
auto fin = fopen("crypt1.in", "r");
auto fout = fopen("crypt1.out", "w+");

const int MAXSZ = 1; // todo
int n;

inline bool legit(cn a, cn p, const set<int> &n)
{
  p = pow(10, p);
  if (a/p || !a*10/p) return false; // check length of num
  for (int c = p%10; p; p/=10) // check each digit
  {
    if (n.find(c) == n.end()) return false;
  }
  return true;
}

inline bool check(cn a, cn b, const set<int> &n)
{
  return (
        legit(a, 3, n) // input long
    &&  legit(b, 2, n) // input short
    &&  legit(a*(b%10), 3, n) // partial product 1
    &&  legit(a*(b/10), 3, n) // partial product 2
    &&  legit(a*b, 4, n) // final product
    );
}

int main ()
{
  set<int> s;
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    int a;
    scanf("%d", &a);
    s.insert(a);
  }

  while (true)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("final: %d\n\n", check(a, b, s));
  }

  return 0;
}
