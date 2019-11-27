/*
 * Problem #1013
 * labrynth
 */

#include <bits/stdc++.h>
#define cn const int;

using namespace std;
const int MAXSZ = 60; // final: the limits were to small (used to be 20) rEEEEEEEE
int n, best = -1, mcount = 0;
int cells[MAXSZ][MAXSZ];
int dist[MAXSZ][MAXSZ];

void noop(){}

void mydfs(const int i, const int j, const int layer=1)
{
  //d*/ for (int i=0; i<layer; ++i) printf("  "); printf("dfs: %d %d\n", i, j);
  if (i == j && j == n)
  {
    //d*/ printf("\ndist: %d\n", layer); for (int i=0; i<=n+1; ++i) { for (int k=0; k<layer; ++k) printf("  "); for (int j=0; j<=n+1; ++j) printf("%3d", dist[i][j]); printf("\n"); }
    if (best == -1 || layer == best)
    {
      best = layer;
      ++mcount;
    }
    else if (layer < best)
    {
      mcount = 1;
      best = layer;
    }
    return;
  }
  pair<int, int> pos[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  for (pair<int, int> p : pos)
  {
    int ii = i+p.first;
    int jj = j+p.second;
    //if (ii < 0 || ii >= n // x out of range
    // || jj < 0 || jj >= n // y out of range
    if (cells[ii][jj] >= 1 // not a valid spot
     || dist[ii][jj] > 0) // already visited
      continue;
    dist[ii][jj] = 1;
    mydfs(ii, jj, layer+1);
    dist[ii][jj] = 0;
  }
}

int main()
{
  scanf("%d", &n);
  if (n < 0) return 0;
  for (int i=0; i<=n+1; ++i)
  {
    for (int j=0; j<=n+2; ++j)
    {
      cells[i][j] = 1;
      dist[i][j] = 0;
    }
  }
  for (int i=1; i<=n; ++i)
  {
    for (int j=1; j<=n; ++j)
    {
      scanf("%d", &cells[i][j]);
    }
  }
  
  if (n == 1 && cells[1][1] == 1) {printf("0\n0"); return 0;} // edge case circumvention
  
  dist[1][1] = 1;
  mydfs(1, 1);

  cout << mcount << endl << max(best, 0); // max used to circumvent edgecases
  
  return 0;
}

/* test data
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
 
3
0 0 0
0 0 0
0 0 0

*/
