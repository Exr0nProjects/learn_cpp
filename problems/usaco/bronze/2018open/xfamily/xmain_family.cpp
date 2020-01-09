/*
ID: spoytie2
TASK: family
LANG: C++14
*/

/*
 * Problem family (usaco/bronze/2018open/family)
 * Created Tue 31 Dec 2019 @ 15:37 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("family.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N;
//vector<string> a;
//vector<string> b;

unordered_map<string, string> parent;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("family.out", "w+"); }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  string _a, _b;
  cin >> _a >> _b;
//  a.push_back(_a);
//  b.push_back(_b);
  for (int i=0; i<N; ++i)
  {
    string f, s;
    cin >> f >> s;
    parent[s] = f;
//    if (s == a[a.size()-1]) a.push_back(f);
//    if (s == b[b.size()-1]) b.push_back(f);
  }
  
//  fprintf(_, "\na:\n"); for (ca s : a) fprintf(_, "%s\n", s.c_str());
  
  //fprintf(_, "b:\n"); for (ca s : b) fprintf(_, "%s\n", s.c_str());

/// old code from bad vector version
//  for (int i=0; i<a.size(); ++i)
//  {
//    for (int j=0; j<b.size(); ++j)
//    {
//      fprintf(_, "%s == %s\n", a[i].c_str(), b[j].c_str());
//      if (a[i] == b[j]) // common anscestor found!
//      {
//        dist_a = i;
//        dist_b = j;
//        break;
//      }
//    }
//    if (dist_a>0 || dist_b>0) break; // should never be one but not the other, but just in case
//  }
  int dist_a=-1, dist_b=-1;
  bool flag=true;
  for (string a=_a; flag; a=parent[a])
  {
    ++dist_a;
    dist_b = -1; // FIX: forgot to reset for each iter of loop
    for (string b=_b; true; b=parent[b])
    {
      ++dist_b;
      fprintf(_, "at step [%d %d] %s==%s\n", dist_a, dist_b, a.c_str(), b.c_str());
      if (a == b)
      {
        fprintf(_, "YEP!\n");
        flag=false;
        break;
      }
      if (!parent.count(b)) break; // end of chain
    }
    if (!parent.count(a)) break; // end of chain
  }
  fprintf(_, "dist_a = %d, dist_b = %d\n", dist_a, dist_b);
  if (flag) // FIX: flag is negative so no need to negate it again in if statement
  {
    printf("NOT RELATED\n");
    return 0;
  }
  if (dist_a == 1 && dist_b == 1) // siblings should not be self
  {
    printf("SIBLINGS\n");
    return 0;
  }
  if (dist_a > 1 && dist_b > 1)
  {
    printf("COUSINS\n");
    return 0;
  }

  if (dist_a > dist_b)
  {
    // swap
    swap(_a, _b);
    swap(dist_a, dist_b);
  }
  printf("%s is the ", _a.c_str());
  for (int i=2; i<dist_b; ++i) printf("great-");
  if (dist_a == 0)
  {
    // direct descendant
    if (dist_b >= 2) printf("grand-");
    printf("mother of %s\n", _b.c_str());
    return 0;
  }
  else if (dist_a == 1)
  {
    // aunt
//    if (dist_b >= 2) printf("great-");
    printf("aunt of %s\n", _b.c_str());
    return 0;
  }

  return 0;
}

/*
1 AA BB
AA BB
=> AA is mother of BB

2 AA BB
AA mother
mother BB
=> AA is grand-mother of BB

0 AA BB
=> NOT RELATED

3 AA BB
ans BB
ans CC
CC AA
=> BB is the aunt of AA

2 AA BB
m AA
m BB
=> SIBLINGS
 */
