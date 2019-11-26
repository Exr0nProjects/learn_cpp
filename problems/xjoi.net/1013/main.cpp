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

void mydfs(const int i, const int j, const int layer=0)
{
  //d*/ for (int i=0; i<layer; ++i) printf("  "); printf("dfs: %d %d\n", i, j);
  if (i == j && j == n-1)
  {
    if (best == -1 || dist[i][j] == best)
    {
      best = dist[i][j];
      ++mcount;
    }
    else if (dist[i][j] < best)
    {
      mcount = 1;
      best = dist[i][j];
    }
    return;
  }
  pair<int, int> pos[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  for (pair<int, int> p : pos)
  {
    if (i + p.first < 0 || i + p.first >= n // x out of range
     || j + p.second < 0 || j + p.second >= n // y out of range
     || cells[i + p.first][j + p.second] >= 1 // not a valid spot
     || dist[i + p.first][j + p.second] > 0) // already visited
      continue;
    dist[i+p.first][j+p.second] = dist[i][j] + 1;
    mydfs(i+p.first, j+p.second, layer+1);
    dist[i+p.first][j+p.second] = 0;
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

/** test data
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
