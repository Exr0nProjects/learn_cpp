/*
ID: spoytie2
TASK: helpcross
LANG: C++14
*/

/*
 * Problem helpcross (usaco/silver/2017feb/helpcross)
 * Create time: Sat 08 Feb 2020 @ 09:29 (PST)
 * Accept time: Sat 08 Feb 2020 @ 09:55 (PST)
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>

void setIO(const std::string &name = "helpcross");

const int MX = 20010;

using namespace std;
int C, N;
multiset<int> chicken;
vector<pair<int, int>> cow;

int main()
{
  setIO();
  scanf("%d%d", &C, &N);
  for (int i = 0; i < C; ++i)
  {
    int t;
    scanf("%d", &t);
    chicken.insert(t);
  }
  for (int i = 0; i < N; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    cow.emplace_back(b, a);
  }
  sort(cow.begin(), cow.end());

  int ret = 0;
  for (int i = 0; i < N; ++i)
  {
    // auto first = lower_bound(chicken.begin(), chicken.end(), cow[i].second); // NTFS: using this one makes it TLE
    auto first = chicken.lower_bound(cow[i].second); // first chicken that starts after this cow is avaliable
    if (first != chicken.end() && *first <= cow[i].first)                    // there is such chicken and it is avaliable while the cow is avaliable
    {
      ++ret; // pair them
      chicken.erase(first);
    }
  }

  printf("%d\n", ret);

  return 0;
}

// boilerplate functions
void setIO(const string &name)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); // fast cin/cout
  if (fopen((name + ".in").c_str(), "r") != nullptr)
  {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w+", stdout);
  }
}
