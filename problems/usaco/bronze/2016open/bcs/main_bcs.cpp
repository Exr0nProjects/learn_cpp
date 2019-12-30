/*
ID: spoytie2
TASK: bcs
LANG: C++14
*/

/*
 * Problem bcs (usaco/bronze/2016open/bcs)
 * Created Mon 30 Dec 2019 @ 12:07 (PST)
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
FILE *fin = fopen("bcs.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10; // todo
int N, K;
struct China
{
  int idx;
  vector<vector<bool> > g; // approx 2 long longs
  China () {
    for (int i=0; i<MAXSZ; ++i)
    {
      g.push_back(vector<bool>{});
      for (int j=0; j<MAXSZ; ++j)
        g[i].push_back(0);
    }
  };
} target;
vector<China> possible;

void print(const China &p)
{
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<N; ++j)
    {
      fprintf(_, "%c", (bool) p.g[i][j] ? '#' : '.');
    }
    fprintf(_, "\n");
  }
  fprintf(_, "\n");
}

bool fits(const China &a, const China &whole)
{
  // true if it fits as a picee of the whole
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<N; ++j)
    {
      if (a.g[i][j] && !whole.g[i][j]) return false; // if `a` has extra bits
    }
  }
  return true;
}

bool overlap(const China &a, const China &b)
{
  // true if two chinas overlap
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<N; ++j)
    {
      if (a.g[i][j] && b.g[i][j]) return true;
    }
  }
  return false;
}

bool finalCmp(const China &a, const China &b, const China &whole)
{
  // true if it fits as a picee of the whole
  fprintf(_, "Final compare between %d and %d: \n", a.idx, b.idx); print(a); print(b);
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<N; ++j)
    {
      fprintf(_, "Checking cell (%d, %d)\n", i, j);
      if (whole.g[i][j] && (a.g[i][j] == b.g[i][j])) return false; // if should be true and not (only one is true)
      if (!whole.g[i][j] && (a.g[i][j] || b.g[i][j])) return false; // if should be false and any is true
    }
  }
  return true;
}

bool shift(const China &src, China &dst, cn si, cn sj)
{
  // vertical shift validity check
  if (si < 0)
  {
    for (int i=0; i<-si; ++i)
      for (int j=0; j<N; ++j) // sweep the entire row
        if (src.g[i][j]) return false; // would drop data
  }
  if (si > 0)
  {
    for (int i=N-1; i>=N-si; --i)
      for (int j=0; j<N; ++j) // sweep entire row again
        if (src.g[i][j]) return false;
  }
  
  // horizontal shift validity check
  if (sj < 0)
  {
    for (int i=0; i<N; ++i)
      for (int j=0; j<-sj; ++j)
        if (src.g[i][j]) return false;
  }
  if (sj > 0)
  {
    for (int i=0; i<N; ++i)
      for (int j=N-1; j>=N-sj; --j)
        if (src.g[i][j]) return false;
  }
  
  //d*/fprintf(_, "before shift: \n"); print(src); fprintf(_, "\n");
  
  // complete the shift
  dst.idx = src.idx;
  for (int i=0; i<N; ++i)
    for (int j=0; j<N; ++j)
    {
      if (i-si >= 0 && i-si < N && j-sj >= 0 && j-sj < N)
        dst.g[i][j] = src.g[i-si][j-sj];
      else
        dst.g[i][j] = 0;
    }
  
  //d*/fprintf(_, "shifted:\n"); print(src);
  
  return true;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("bcs.out", "w+"); }

//  N = 2;
//  China a; a.g = {{1, 1}, {1, 1}, {1, 0}};
//  China b; b.g = {{1, 1}, {1, 0}, {1, 0}};
//  printf("%d\n", overlap(a, b)); // 1
//  return 0;
  
  
//  N = 4;
//  China c; c.g = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
//  China d;
//  shift(c, d, -1, -1);
//  print(d);
//  return 0;
  
  
  scanf("%d%d", &N, &K);
  for (int i=0; i<N; ++i)
  {
    scanf("\n");
    for (int j=0; j<N; ++j)
    {
      char c;
      scanf("%c", &c);
      target.g[i][j] = (c == '#');
    }
    
  }
  
  China in, temp;
  // for each piece
  for (int k=0; k<K; ++k)
  {
    in.idx = k;
    // input it
    for (int i=0; i<N; ++i)
    {
      scanf("\n");
      for (int j=0; j<N; ++j)
      {
        char c;
        scanf("%c", &c); //FIX: this was scanf("%d", ...) which ofc returned nothing
        in.g[i][j] = (c =='#');
      }
    }
    
    //d*/fprintf(_, "Input:\n"); print(in);
    
    // shift to all locations
    for (int i=-N; i<=N; ++i)
    {
      for (int j=-N; j<=N; ++j)
      {
        if (shift(in, temp, i, j))
        {
          if (fits(temp, target)) // overlap func is actually bad, cuz i need it to allow one to not fully cover the other but not the other way around
            possible.push_back(temp);
        }
      }
    }
  }
  
  for (int i=0; i<possible.size(); ++i)
  {
    for (int j=i+1; j<possible.size(); ++j)
    {
      fprintf(_, "%d, %d\n", i, j);
      print(possible[i]); print(possible[j]);
      if (finalCmp(possible[i], possible[j], target))
      {
        // WORKED!
        printf("%d\n%d\n", possible[i].idx+1, possible[j].idx+1);
        return 0;
      }
    }
  }
  
  return 0;
}
