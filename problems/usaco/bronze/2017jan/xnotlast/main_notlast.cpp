/*
ID: spoytie2
TASK: notlast
LANG: C++14
*/

/*
 * Problem notlast (usaco/bronze/2017jan/notlast)
 * Created Sun 29 Dec 2019 @ 11:37 (PST)
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
FILE *fin = fopen("notlast.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
vector<pair<int, string> > store;
const string names[] = { "Annabelle", "Bessie", "Daisy", "Elsie", "Gertie", "Henrietta", "Maggie"};

int find(string n)
{
  for (int i=0; i<7; ++i)
  {
    if (names[i] == n) return i;
  }
  return -1;
}

int main ()
{
  if (fin) { stdin = fin, stdout = fopen("notlast.out", "w+"); }
  for (ca n : names) store.push_back(make_pair(0, n));
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    char c[20];
    int d;
    scanf("%s%d", c, &d);
    store[find(c)].first += d;
  }
  sort(store.begin(), store.end());

  for (int i=1; i<7; ++i)
  {
    if (store[i].first != store[i-1].first)
    {
      if (i < 6 && store[i].first == store[i+1].first) // FIX: forgot to put this version of the tie condition in.
        printf("Tie\n");
      else
        printf("%s\n", store[i].second.c_str());
      return 0;
    }
  }

  printf("Tie\n");

  return 0;
}
