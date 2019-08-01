/*
 * c1206-1
 * city block racing
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

const int MAXSZ = 110;
const int MAXLN = 1010;

char city[MAXSZ][MAXSZ] = { };
char turns[MAXLN] = { };

inline char trevMap (int& py, int& px, const char mod='C')
{
  switch (mod)
  {
    case 'N':
      --py; break;
    case 'S':
      ++py; break;
    case 'E':
      ++px; break;
    case 'W':
      --px; break;
  }

  char ret;
  if (!(py < 0 || px < 0)) ret = city[py][px];
  else return 'C';

  if (!(ret=='X' || ret=='.')) return 'C';
  return ret;
}

inline void dfc (int sy, int sx, char * pt)
{
  if (*pt == 'C') { city[sy][sx] = '*'; return; }
  for (char cur = trevMap(sy, sx, *pt); cur == '.'; cur = trevMap(sy, sx, *pt))
  {
    dfc(sy, sx, pt+1);
  }
}

int main ()
{
  int n, m, sx=0, sy=0;
  scanf("%d%d\n", &n, &m);
  for (int n_=0; n_<n; ++n_)
  {
    string temp;
    getline(cin, temp);
    for (int m_=0; m_<m; ++m_)
    {
      city[n_][m_] = temp[m_];
      if (temp[m_] == '*')
      {
        sy = n_;
        sx = m_;
        city[n_][m_] = '.';
      }
    }
  }

//  for (int i=0; i<n; ++i) { for (int j=0; j<m; ++j) printf("%c", city[i][j]); printf("\n"); } printf("\n\n\n");

  int num;
  scanf("\n%d\n", &num);
  for (int i=0; i<num; ++i)
  {
    string temp;
    getline(cin, temp);
    turns[i] = temp[0];
  }
  turns[num] = 'C'; // exit condition in dfc

//  for  (int i=0; i<=num; ++i) printf("%c ", turns[i]);

  dfc(sy, sx, turns);

  for (int i=0; i<n; ++i)
  {
    for (int j=0; j<m; ++j)
    {
      printf("%c", city[i][j]);
    }
    printf("\n");
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
