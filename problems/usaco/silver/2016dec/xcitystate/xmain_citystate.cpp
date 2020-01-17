/*
ID: spoytie2
TASK: citystate
LANG: C++14
*/

/*
 * Problem citystate (usaco/silver/2016dec/citystate)
 * Create time: Wed 15 Jan 2020 @ 20:57 (PST)
 * Accept time: Thu 16 Jan 2020 @ 19:53 (PST)
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
FILE *fin = fopen("citystate.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
map<pair<pair<char, char>, pair<char, char> >, int> locs;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("citystate.out", "w+"); }
  // stdout = fopen("citystate.out", "w+");
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    char buf[16], c1, c2, s1, s2;
    scanf("\n%s %c%c", buf, &s1, &s2);
    c1 = buf[0];
    c2 = buf[1];
//    printf("%c%c : %c%c\n", c1, c2, s1, s2);
    ++locs[make_pair(make_pair(c1, c2), make_pair(s1, s2))];
  }

  ll ret = 0;
  for (ca p : locs)
  {
//    printf("checking %c%c:%c%c -> %d\n", p.first.first.first, p.first.first.second, p.first.second.first, p.first.second.second, p.second);
    if (locs.count(make_pair(p.first.second, p.first.first)))
    {
      if (p.first.first == p.first.second) continue; // FIX: don't even count anything if two cities are from the same state.
                                                      // the only way a city could match another from the same state is if the first two letters of the city is the same as the state.
      ret += p.second * locs.at(make_pair(p.first.second, p.first.first)); // FIX: originally forgot to multiply by p.second
      if (p.first.first == p.first.second) // if the reverse would match itself
      {
        ret -= p.second; // don't overcount, FIX: subtract p.second instead of just 1
      }
    }
  }

  printf("%lld\n", ret/2);

  return 0;
}

/*
 3
 AA BB
 BBA AA
 BBB AA
 => 2
 
 4
 AA BB
 AA BB
 BB AA
 BB AA
 => 4
 
 2
 ABCDEFGHIJ AA
 EPIKKK AA
 => 0
 
 5
 AA AA
 AA AA
 AA AA
 AA AA
 AA AA
 => 10
 */
