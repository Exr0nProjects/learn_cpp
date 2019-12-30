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
bool target[MAXSZ][MAXSZ];
bool grids[MAXSZ][MAXSZ][MAXSZ];

bool getAt(const bool arr[MAXSZ][MAXSZ], cn y, cn x)
{
  return y >= 0 && y < N && x >= 0 && x < N && arr[y][x];
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
      target[i][j] = (c == '#');
    }
    
  }
  
  // for each piece
  for (int k=0; k<K; ++k)
  {
    // input it
    for (int i=0; i<N; ++i)
    {
      scanf("\n");
      for (int j=0; j<N; ++j)
      {
        char c;
        scanf("%c", &c); //FIX: this was scanf("%d", ...) which ofc returned nothing
        grids[k][i][j] = (c =='#');
      }
    }
  }
  
  // each pair of pieces (K*K)
  for (int i=0; i<K; ++i) for (int j=i+1; j<K; ++j)
      // all shifts of first piece (K*N)
      for (int isi=-N+1; isi<N; ++isi) for (int isj=-N+1; isj<N; ++isj)
        // all shifts of the second piece (N*N)
        for (int jsi=-N+1; jsi<N; ++jsi) for (int jsj=-N+1; jsj<N; ++jsj)
        {
          bool legit = true;
          // check if this shifted pair works
          for (int y=0; y<N; ++y) for (int x=0; x<N; ++x)
          {
            bool ati = getAt(grids[i], y, x);
            bool atj = getAt(grids[j], y, x);
            
            if (ati && atj) legit = false; // if the two pieces overlap
            if (target[y][x] != (ati || atj)) legit = false; // if it doesn't match the target
          }
          if (legit)
          {
            printf("%d %d\n", i+1, j+1);
            return 0;
          }
        }
  
  return 0;
}
