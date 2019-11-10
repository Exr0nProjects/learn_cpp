/*
ID: spoytie2
TASK: combo
LANG: C++14                 
*/

/*
 * Problem combo (usaco/training/combo)
 * Created Sun 10 Nov 2019 @ 10:18 (PST)
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
// auto fin = fopen("combo.in", "r");
// auto fout = fopen("combo.out", "w+");

const int MAXSZ = 1; // todo
int n, a, b;
set<int> legit;

void generate(cn n) // generate all combos that are close to n
{
  int mod[] = {200, 100, -100, -200, 20, 10, -10, -20, 2, 1, -1, -2, 0};
  for (int i : mod)
  {
    legit.insert((n+mod)%n);
  }
}

int main ()
{
  scanf("%d", &n);
  int t;
  for (int i=0; i<3; ++i) {scanf("%d", &t); a *= 10; a += t; }
  for (int i=0; i<3; ++i) {scanf("%d", &t); b *= 10; b += t; }
  printf("%d: %d %d\n\n", n, a, b);

  generate(a); // add all near to a
  generate(b); // add all near to b

  printf("%d", legit.size());

  return 0;
}
