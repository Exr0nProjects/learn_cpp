/*
 * Problem #1013
 * labrynth
 */

#include <bits/stdc++.h>
#define cn const int;

using namespace std;
const int MAXSZ = 20;
int n;
int cells[MAXSZ][MAXSZ];
int dist[MAXSZ][MAXSZ];

queue<pair<int, int> > q;

int main ()
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    for (int j=0; j<n; ++j)
    {
      scanf("%d", cells[i][j]);
    }
  }

  dist[0][0] = 1;
  for (q.push(pair<int, int>{0, 0}); !q.empty(); q.pop())
  {
    pair<int, int> pos[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (pair<int,int> p : pos)
    {
      if (q.top().first + p.first < 0 || q.top().first + p.first >= n
       || q.top().second + p.secoond < 0 || q.top().second + p.second >= n
       || cells[q.top().first+p.first][q.top().second+p.second] >= 1)
        continue;
      dist[q.top().first+p.first][q.top().second+p.second] = dist[q.top().first][q.top().second] + 1;
      q.push(pair<int, int>{q.top().first + p.first, q.top().second + p.second});
    }
  }

  printf("%d", cells[n-1][n-1]);

  return 0;
}

/** test data
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

*/
