/*
ID: spoytie2
TASK: 4
LANG: C++14
*/

/*
 * Problem 4 (contests/dev.xjoi/dev.xjoi-1351/4)
 * Created Sat 28 Dec 2019 @ 18:15 (PST)
 * Accepted [!meta:end!]
 * sorting structs, should be easy with std::pair
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
FILE *fin = fopen("4.in", "r");
FILE *fout = nullptr;

const int MAXSZ = -1; // todo



int main ()
{
  if (fin) { fout = fopen("4.out", "w+"); } else { fin = stdin; fout = stdout; }
  int n;
  scanf("%d", &n);

  vector<pair<int, int> > soln;
  for (int i=0; i<n; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    soln.push_back(make_pair(a, b));
  }

  sort(soln.begin(), soln.end());

  for (const auto &p : soln)
  {
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}
