/*
 * c1206-2
 * horse race selection
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string>
#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 2019;

int dp[MAXSZ][MAXSZ] = { };
int speeda[MAXSZ] = { };
int speedb[MAXSZ] = { };

int main ()
{
  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i) scanf("%d", &speeda[i]);
  for (int i=0; i<num; ++i) scanf("%d", &speedb[i]);

  for (int i=0; i<num; ++i) printf("%d ", speeda[i]); printf("\n");
  for (int i=0; i<num; ++i) printf("%d ", speedb[i]);

  sort (speeda, speeda + num);
  sort (speedb, speedb + num);

  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num; ++j)
    {
      if (i == 0)
      {
        dp[i][j] = (int) (speeda[i] > speedb[j]);
      }
    }
  }

  return 0;
}

/*


3 4
....
*..X
X.X.
2
EAST
NORTH


 */
