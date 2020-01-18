/*
ID: spoytie2
TASK: [!meta:pid!]
LANG: C++14
*/

/*
 * Problem [!meta:pid!] [!meta:srcpath!]
 * Create time: [!meta:beg!]
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
#define ii pair<int, int>
#define vii vector<ii>

#define MP make_pair
#define PB push_back
#define F first
#define B second
#define INF 0x7FFFFFFF

// for macro overloading, see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// this set is designed for one indexed collections
#define FOR_(i,b,e) for (int i=(b); i<(e); ++i)
#define FOR(i,e) FOR_(i,1,(e)+1)
#define FORR_(i,b,e) for (int i=(e); i>=(b); --i)
#define FORR(i,e) FORR_(i,1,e)
#define SORT(a,n) std::sort((a)+1, (a)+(n)+1)
#define TRAV(a,x) for (auto& a: x)
#define SORTV(v) std::sort((v).begin()+1, (v).end())

void setIO();

typedef struct {
  int f, t, w, n;
} Edge;
#define TRAVE(s,e) for (int e=head[s]; e; e=edges[e].n)

const int MX=100010;
#define __USING_EDGELIST
void addEdge(cn a, cn b, cn w=1);
Edge edges[MX*MX];
int ect=1, head[MX];

using namespace std;
int N, V;

char type[MX];
int group[MX];

void disjointDFS(cn s, cn g)
{
  if (group[s]) return;
  group[s] = g;
  TRAVE(s, e)
  {
    if (type[edges[e].t] == type[s])
    {
      disjointDFS(edges[e].t, g);
    }
  }
}

int main()
{
  setIO();
  scanf("%d%d", &N, &V);
  scanf("%s", type+1);
  FOR(i, N)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    addEdge(a, b);
    addEdge(b, a);
  }
  
  FOR(i, N)
  {
    disjointDFS(i, i);
  }
  
//  for (int i=1; i<=N; ++i) printf("%2d (%c): %3d\n", i, type[i], group[i]);
  
  for (int i=1; i<=V; ++i)
  {
    int a, b;
    char c;
//    scanf("%d%d%c", &a, &b, &c);
    cin >> a >> b >> c;
    printf("%d : %d (%c)\n", a, b, c);
    if (group[a] == group[b]) printf("%d", type[a] == c);
    else printf("1");
  }

  return 0;
}

// boilerplate functions
void setIO()
{
  ios_base::sync_with_stdio(0); cin.tie(0); // fast cin/cout
  if (fopen("[!meta:pid!].in", "r") != nullptr)
  {
    freopen("[!meta:pid!].in", "r", stdin);
    freopen("[!meta:pid!].out", "w", stdout);
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
