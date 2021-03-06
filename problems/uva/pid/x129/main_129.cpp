/*
ID: spoytie2
TASK: 129
LANG: C++14
*/

/*
 * Problem 129 (onlinejudge/pid/129)
 * Create time: Sun 26 Jan 2020 @ 16:32 (PST)
 * Accept time: [!meta:end!]
 * I hae no clue how to check for prefixes
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

void setIO(const std::string &name = "129");

typedef struct
{
  int f, t, w, n;
} Edge;
#define TRAVE(s, e) for (int e = head[s]; e; e = edges[e].n)

const int MX = 100;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
int N, L, cnt = 0, pos = 0;
char S[MX] = {};
queue<string> seq;

bool construct()
{
  //  printf("\n%d construct\n", pos);
  //  FOR(i, pos) printf("%c", S[i]); printf("\n");
  if (cnt++ == N)
  {
    // TODO
    return 1;
  }
  FOR(l, L)
  {
    //    printf("trying %c\n", 'A'+l);
    S[pos] = 'A' + l;
    bool works = true;
    //    printf("  checking ln = 0 - %d\n", (pos)/2+1);
    FOR_(ln, 1, (pos + 1) / 2 + 1)
    {
      //      printf("    ln = %d\n", ln);
      bool this_sequence_works = false;
      FOR(j, ln)
      {
        //        printf("    %d vs %d\n", pos-j, pos-ln-j);
        if (S[pos - j] != S[pos - ln - j])
        {
          this_sequence_works = true;
        }
      }
      works &= this_sequence_works;
    }
    if (works)
    {
      //      printf("  seems legit!\n");
      ++pos;
      if (construct())
      {
        return 1; // sucess
      }
      --pos;
    }
  }
  S[pos] = 0;
  //  printf("pos %d: didn't work :(\n", pos);
  return 0;
}

int main()
{
  scanf("%d%d", &N, &L);
  while (N || L)
  {
    pos = cnt = 0;
    construct();
    int chr = 0, group = 0;
    FOR(i, pos)
    {
      if (chr == 4)
      {
        if (group == 15)
        {
          printf("\n");
          group = 0;
        }
        else
        {
          printf(" ");
          ++group;
        }
        chr = 0;
      }
      printf("%c", S[i]);
      ++chr;
    }
    printf("\n%d\n", pos);

    scanf("%d%d", &N, &L);
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
