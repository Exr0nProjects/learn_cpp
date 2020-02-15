/*
ID: spoytie2
TASK: countcross
LANG: C++14
*/

/*
 * Problem countcross (usaco/silver/2017feb/countcross)
 * Create time: Sat 18 Jan 2020 @ 10:55 (PST)
 * Accept time: Sat 18 Jan 2020 @ 11:35 (PST)
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
#define FOR(i, e) FOR_(i, 1, (e) + 1)
#define FORR_(i, b, e) for (int i = (e); i >= (b); --i)
#define FORR(i, e) FORR_(i, 1, e)
#define SORT(a, n) std::sort((a) + 1, (a) + (n) + 1)
#define TRAV(a, x) for (auto &a : x)
#define SORTV(v) std::sort((v).begin() + 1, (v).end())

void setIO(const std::string &name = "countcross");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 110;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, K, R;
int group[MX][MX];
int cy[MX], cx[MX];
set<pair<pii, pii>> cannot;

void disjointDFS(cn i, cn j, cn g)
{
  //  printf("%d %d -> %d\n", i, j, group[i][j]);
  if (group[i][j] != 0)
    return;
  group[i][j] = g;
  int dy[] = {0, -1, 1, 0, 0};
  int dx[] = {0, 0, 0, -1, 1};
  FOR(k, 4) // FIX: name colision, i was an argument and also the loop int
  {
    int y = dy[k];
    int x = dx[k];
    //    if (i+y > 3 || j+x > 3) printf("%d %d + %d %d -> %d %d\n", i, j, y, x, i+y, j+x);
    //    printf("    %2d,%2d %c%2d,%2d\n", i, j, (cannot.count(MP(MP(i, j), MP(i+y, j+x))) == 0) ? '=' : '!', i+y, j+x);
    if (cannot.count(MP(MP(i, j), MP(i + y, j + x))) == 0)
    {
      disjointDFS(i + y, j + x, g);
    }
  }
}

int main()
{
  setIO();
  scanf("%d%d%d", &N, &K, &R);

  FOR_(i, 0, N + 3)
  {
    group[i][0] = group[0][i] = group[N + 1][i] = group[i][N + 1] = -1; // set boundaries
  }

  FOR(i, R)
  {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    cannot.insert(MP(MP(a, b), MP(c, d)));
    cannot.insert(MP(MP(c, d), MP(a, b)));
  }

  //  printf("\ncannot:\n");
  //  TRAV(p, cannot)
  //  {
  //    printf("%2d, %2d ! %2d, %2d\n", p.F.F, p.F.S, p.S.F, p.S.S);
  //  }

  //  printf("\nafter borders drawn\n");
  //  FOR_(i, 0, N+5)
  //  {
  //    FOR_(j, 0, N+5)
  //    {
  //      printf("%3d", group[i][j]);
  //    }
  //    printf("\n");
  //  }

  int g = 1;
  FOR(i, N)
  FOR(j, N)
  {
    disjointDFS(i, j, g);
    ++g;
  }

  //  printf("\nafter groups drawn\n");
  //  FOR_(i, 0, N + 2)
  //  {
  //    FOR_(j, 0, N + 2)
  //    {
  //      printf("%3d", group[i][j]);
  //    }
  //    printf("\n");
  //  }

  FOR(i, K)
  {
    scanf("%d%d", &cy[i], &cx[i]);
  }

  int ret = 0;
  FOR(i, K)
  FOR(j, K)
  {
    if (group[cy[i]][cx[i]] != group[cy[j]][cx[j]])
      ++ret;
  }

  printf("%d\n", ret / 2);

  return 0;
}

/*
 3 3 3
 2 2 2 3
 3 3 3 2
 3 3 2 3
 3 3
 2 2
 2 3
 => 2
 
 2 2 2
 1 1 1 2
 2 1 2 2
 1 1
 2 2
 => 1
 */

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

#ifdef __USING_EDGELIST
void addEdge(cn a, cn b, cn w)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].w = w;
  edges[ect].n = head[a];
  head[a] = ect++;
}
#endif

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
