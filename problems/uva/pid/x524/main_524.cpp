/*
ID: spoytie2
TASK: 524
LANG: C++14
*/

/*
 * Problem 524 (onlinejudge/pid/524)
 * Create time: Sun 26 Jan 2020 @ 15:21 (PST)
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

// for macro overloading, see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// this set is designed for one indexed collections
#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "524");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 20;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N;
int used[MX];
vi nums;

bool isPrime(cn n)
{
  return (
      n == 2 ||
      n == 3 ||
      n == 5 ||
      n == 7 ||
      n == 11 ||
      n == 13 ||
      n == 17 ||
      n == 19 ||
      n == 23 ||
      n == 29 ||
      n == 31);
}

void test(cn tc, cn dep = 1)
{
  if (dep == tc)
  {
    if (nums.size() > 1 && isPrime(nums[0] + nums[nums.size() - 1]))
    {
      FOR(i, nums.size() - 1)
      printf("%d ", nums[i]);
      printf("%d\n", nums[nums.size() - 1]);
    }
  }
  FOR_(i, 2, tc + 1)
  {
    if (!used[i])
    {
      used[i] = true;
      if (nums.size() == 0 || isPrime(nums[nums.size() - 1] + i))
      {
        nums.push_back(i);
        //        TRAV(i, nums) printf("%3d", i); printf("\n");
        test(tc, dep + 1);
        nums.pop_back();
      }
      used[i] = false;
    }
  }
}

int main()
{
  setIO();

  nums.push_back(1);

  for (int tc = 1; cin >> N; ++tc)
  {
    if (tc > 1)
      printf("\n");
    if (N > 1)
      printf("Case %d:\n", tc);

    test(N);
  }

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

/*
Benjamin Qi
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
*/

/*
thecodingwizard

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
*/
