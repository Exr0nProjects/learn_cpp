/*
 * Problem #1013
 * labrynth
 */

#include <bits/stdc++.h>
#define cn const int;

using namespace std;
const int MAXSZ = 20;
int n, best = -1, mcount = 0;
int cells[MAXSZ][MAXSZ];
int dist[MAXSZ][MAXSZ];

void noop(){}

void mydfs(const int i, const int j, const int layer=1)
{
  //d*/ for (int i=0; i<layer; ++i) printf("  "); printf("dfs: %d %d\n", i, j);
  if (i == j && j == n-1)
  {
    //d*/ printf("\ndist: %d\n", layer); for (int i=0; i<n; ++i) { for (int k=0; k<layer; ++k) printf("  "); for (int j=0; j<n; ++j) printf("%3d", dist[i][j]); printf("\n"); }
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
    if (ii < 0 || ii >= n // x out of range
     || jj < 0 || jj >= n // y out of range
     || cells[ii][jj] >= 1 // not a valid spot
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
  for (int i=0; i<n; ++i)
  {
    for (int j=0; j<n; ++j)
    {
      scanf("%d", &cells[i][j]);
    }
  }
  
  if (n == 1 && cells[0][0] == 1) {printf("0\n0"); return 0;} // edge case circumvention
  
  dist[0][0] = 1;
  mydfs(0, 0);

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
