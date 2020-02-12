/*
ID: spoytie2
TASK: skidesign
LANG: C++14
*/

/*
 * Problem skidesign ([!meta:srcpath!])
 * Create time: Tue 11 Feb 2020 @ 19:18 (PST)
 * Accept time: [!meta:end!]
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

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i,b,e) for (int i=(b); i<(e); ++i)
#define FOR(i,e) FOR_(i,0,(e))
#define FORR_(i,b,e) for (int i=(e)-1; i>=(b); --i)
#define FORR(i,e) FORR_(i,0,e)
#define SORT(a,n) std::sort((a), (a)+(n))
#define TRAV(a,x) for (auto& a: x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name="skidesign");

using namespace std;
const int MX=1010;
int N, hills[MX];


int main()
{
  setIO();
  scanf("%d", &N);
  FOR(i, N) scanf("%d", &hills[i]);
  
  int ret = 1<<30;
  FOR(low, 83)
  {
    int high = low + 17;
    int cost = 0;
    FOR(i, N)
    {
      if (hills[i] < low) cost += pow(low - hills[i], 2);
      if (high < hills[i]) cost += pow(hills[i]-high, 2);
    }
    ret = min(ret, cost);
  }

  printf("%d\n", ret);

  return 0;
}



void setIO(const string &name)
{
  ios_base::sync_with_stdio(0); cin.tie(0); // fast cin/cout
  if (fopen((name+".in").c_str(), "r") != nullptr)
  {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w+", stdout);
  }
}
