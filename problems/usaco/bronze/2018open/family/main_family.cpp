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
vector<string> a;
vector<string> b;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("family.out", "w+"); }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  string _a, _b;
  cin >> _a >> _b;
  a.push_back(_a);
  b.push_back(_b);
  for (int i=0; i<N; ++i)
  {
    string f, s;
    cin >> f >> s;
    if (s == a[a.size()-1]) a.push_back(f);
    if (s == b[b.size()-1]) b.push_back(f);
  }
  
  fprintf(_, "\na:\n");
  for (ca s : a) fprintf(_, "%s\n", s.c_str());
  
  fprintf(_, "b:\n");
  for (ca s : b) fprintf(_, "%s\n", s.c_str());

  int dist_a=-1, dist_b=-1;
  for (int i=0; i<a.size(); ++i)
  {
    for (int j=0; j<b.size(); ++j)
    {
      fprintf(_, "%s == %s\n", a[i].c_str(), b[j].c_str());
      if (a[i] == b[j]) // common anscestor found!
      {
        dist_a = i;
        dist_b = j;
        break;
      }
    }
    if (dist_a>0 || dist_b>0) break; // should never be one but not the other, but just in case
  }
  fprintf(_, "dist_a = %d, dist_b = %d\n", dist_a, dist_b);
  if (dist_a+dist_b < 0)
  {
    printf("NOT RELATED\n");
    return 0;
  }
  if (dist_a == 0 && dist_b == 0)
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
    swap(a[0], b[0]);
    swap(dist_a, dist_b);
  }
  printf("%s is the ", a[0].c_str());
  for (int i=2; i<dist_b; ++i) printf("great-");
  if (dist_a == 0)
  {
    // direct descendant
    if (dist_b >= 2) printf("grand-");
    printf("mother of %s\n", b[0].c_str());
    return 0;
  }
  else if (dist_a == 1)
  {
    // aunt
//    if (dist_b >= 2) printf("great-");
    printf("aunt of %s\n", b[0].c_str());
    return 0;
  }

  return 0;
}
