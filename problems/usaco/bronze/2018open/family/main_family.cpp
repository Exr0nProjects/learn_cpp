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
  cin >> _a >> _b;
  a.push_back(_a);
  b.push_back(_b);
  for (int i=0; i<N: ++i)
  {
    string f, s;
    cin >> f >> s;
    if (s == a[a.size()-1]) a.push_back(f);
    if (s == b[b.size()-1]) b.push_back(f);
  }

  for (int i=0; i<a.size(); ++i)
  {
    for (int j=0; j<b.size(); ++j)
    {
      if (a[i] == b[j])
      {
        if (i > 1 && j > 1)
        {
          printf("COUSINS");
          return 0;
        }

        else if (i == 0)
        {
          if (j == 1) printf("%s is mother of %s")
        }
        else if (i == 1)
        {

          if (j == 2) printf("%s is aunt of %s", a[i], b[j]);
          if (j == 1) printf("SIBLINGS", a[i], b[j]);
          if (j == 0) printf("%s is the mother of %s", b[j], a[i]);
        }
        
      }
    }
  }

  return 0;
}
