/*
ID: spoytie2
TASK: shuffle
LANG: C++14
*/

/*
 * Problem shuffle (usaco/bronze/2017dec/shuffle)
 * Created Sun 29 Dec 2019 @ 15:18 (PST)
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
FILE *fin = fopen("shuffle.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N;
vector<int> path;

vector<int> shuffle(const vector<int> &src)
{
  vector<int> ret;
  for (ca i : path)
  {
    ret.push_back(src[i-1]); // FIX: shuffle input is one indexed
  }
  return ret;
}


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("shuffle.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    int d;
    scanf("%d", &d);
    path.push_back(d);
  }
  vector<int> cows;
  for (int i=0; i<N; ++i)
  {
    int d;
    scanf("%d", &d);
    cows.push_back(d);
  }
  
  for (int i=0; i<3; ++i)
  {
    for (int c : cows)
      fprintf(_, "%d ", c);
    fprintf(_, "\n");
    cows = shuffle(cows);
  }

  for (int c : cows)
    printf("%d\n", c);

  return 0;
}

