/*
 * VJudge 313134 C
 * suicidal king
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1010;
const int ROOKS = 666;
const int TURNS = 2000;

struct Rook
{
  int posx, posy;
};

Rook rooks[ROOKS];
int boardh[MAXSZ] = { };
int boardv[MAXSZ] = { };
int kingx, kingy;

int main ()
{
  scanf("%d %d", &kingx, &kingy);
  for (int i=0; i<ROOKS; ++i)
  {
    scanf("%d %d", &rooks[i].posx, &rooks[i].posy);
    ++ boardh[rooks[i].posx];
    ++ boardv[rooks[i].posy];
  }

  for (int i=0; i<TURNS; ++i)
  {
    if (boardh[kingx] || boardv[kingy]) return 0; // got checked

    if (boardh[kingx-1]) printf("%d %d\n", kingx-1, kingy);
    else if (boardh[kingx+1]) printf("%d %d\n", kingx+1, kingy);
    else if (boardh[kingy-1]) printf("%d %d\n", kingx, kingy-1);
    else if (boardh[kingy+1]) printf("%d %d\n", kingx, kingy+1);
    else
    {
      if (kingx > 0) printf("%d %d\n", kingx-1, kingy);
      else printf("%d %d\n", kingx+1, kingy);
    }
    fflush(stdout);

    int temp;
    scanf("%d", &temp);
    if (temp == -1) return 0;
    -- boardh[rooks[temp].posx];
    -- boardv[rooks[temp].posy];
    scanf("%d %d", &rooks[temp].posx, &rooks[temp].posy);
    ++ boardh[rooks[temp].posx];
    ++ boardh[rooks[temp].posy];
  }

  return 0;
}


/*
 1 6

 */
