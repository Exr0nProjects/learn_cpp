/*
 * VJudge 313134 A
 * problem contests
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

int probcount[MAXSZ] = {};
int reqcontst[MAXSZ] = {};

int main ()
{
  int count=1;

  int t, n;
  scanf("%d %d", &t, &n);
  for (int i=0; i<n; ++i)
  {
    int _t;
    scanf("%d", &_t);
    ++ probcount[_t];
    ++ reqcontst[probcount[_t]];

    if (reqcontst[count] == t)
    {
      printf("1");
      ++count;
    }
    else
      printf("0");
  }


  return 0;
}


/*
3 11
2 3 1 2 2 2 3 2 2 3 1

00100000001
00100000001


 4 8
 4 1 3 3 2 3 3 3

 00001000

 */
