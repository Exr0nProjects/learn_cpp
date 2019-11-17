/*
ID: spoytie2
TASK: wormhole
LANG: C++14
*/

/*
 * Problem wormhole (usaco/training/wormhole)
 * Created Sun 17 Nov 2019 @ 13:24 (PST)
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
// auto fin = fopen("wormhole.in", "r");
// auto fout = fopen("wormhole.out", "w+");

const int MAXSZ = 1; // todo
struct Wormhole
{
  int x, y;
  bool operator<(const Wormhole &o) const { return x < o.x; }
  operator string() const { return "Wormhole(" + to_string(x) + ", " + to_string(y) + ")"; }
};
map<int, vector<Wormhole>> mp; // sorted by x position

int n;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    Wormhole w;
    w.x = x;
    w.y = y;
    mp[x].push_back(w);
  }

  for (pair<const int, vector<Wormhole>> &p : mp)
  {
    sort(p.second.begin(), p.second.end());
    //d*/ for (auto a : p.second) cout << (string) a << " "; cout << endl;
  }

  return 0;
}
