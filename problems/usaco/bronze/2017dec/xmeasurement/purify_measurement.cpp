/*
ID: spoytie2
TASK: measurement
LANG: C++14
*/

/*
 * Problem measurement (usaco/bronze/2017dec/measurement)
 * Created Sun 29 Dec 2019 @ 15:28 (PST)
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
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
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
FILE *fin = fopen("measurement.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N;
vector<pair<int, pair<int, int> > > logs;

int toIdx(char c)
{
  if (c == 'B') return 1;
  if (c == 'E') return 2;
  if (c == 'M') return 3;
  return 0;
}

int getMax(const int arr[], cn size)
{
  int b = arr[0], x=0;
  for (int i=1; i<size; ++i)
  {
    if (arr[i] > b)
    {
      b = arr[i];
      x = i;
    }
  }
  return b;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("measurement.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    int d, c;
    char n[20];
    scanf("%d%s%d", &d, n, &c);
    logs.push_back(make_pair(d, make_pair(toIdx(n[0]), c)));
  }
  sort(logs.begin(), logs.end());
  
  //for (ca i : logs) printf("%d: %3d\n", i.second.first, i.second.second); printf("\n");
  
  int prod[] = {0, 7, 7, 7};
  bool wall[] = {0, 0, 0, 0};
  int ret = 0; // maybe two changes on the same day? add retday variable
  for (int i=0; i<logs.size(); ++i)
  {
    prod[logs[i].second.first] += logs[i].second.second;
    int best = getMax(prod, 4);
    
    for (int j=1; j<4; ++j)
    {
      if (wall[i] != (prod[j]==best)) wall[0] = 1; // change flag
      wall[i] = prod[j]==best;
    }
    
    ret += wall[0];
    wall[0] = 0;
  }
  
  printf("%d\n", ret);

  return 0;
}
