/*
ID: spoytie2
TASK: XXXX
LANG: C++14
*/

/*
 * Problem 3657 (xjoi.net/3657)
 * Created Sun 27 Oct 2019 @ 13:11 (PDT)
 * Accepted Sun 27 Oct 2019 @ 13:19 (PDT)
 * number triangle
 */

#include <iostream>

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 110; // todo
int n;
int grid[MAXSZ][MAXSZ];

void printgrid()
{
  return;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      printf("%3d", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      scanf("%d", &grid[i][j]);
    }
  }

  printgrid();

  for (int i = 1; i < n; ++i)
  {
    grid[i][0] += grid[i - 1][0];
  }

  printgrid();

  // dp
  for (int i = 1; i < n; ++i)
  {
    for (int j = 1; j <= i; ++j)
    {
      grid[i][j] += max(grid[i - 1][j], grid[i - 1][j - 1]);
    }
  }

  printgrid();

  int ret = grid[n - 1][0];
  for (int i = 1; i < n; ++i)
  {
    ret = max(ret, grid[n - 1][i]);
  }

  printf("%d", ret);

  return 0;
}
