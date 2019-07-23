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

struct GameEx : std::exception
{
  int type;
};

Rook rooks[ROOKS];
int boardh[MAXSZ] = { };
int boardv[MAXSZ] = { };
bool sboard[MAXSZ][MAXSZ] = { };
int kingx, kingy;

void getMove ()
{
  int temp;
  scanf("%d", &temp);
  if (temp == -1)
  { // got checked
    GameEx exp;
    exp.type = 0; // got checked, and won
    throw exp;
  }
  -- boardh[rooks[temp].posx];
  -- boardv[rooks[temp].posy];
  sboard[rooks[temp].posx][rooks[temp].posy] = false;
  scanf("%d %d", &rooks[temp].posx, &rooks[temp].posy);
  ++ boardh[rooks[temp].posx];
  ++ boardh[rooks[temp].posy];
  sboard[rooks[temp].posx][rooks[temp].posy] = true;
}

inline void putMove (int dx, int dy)
{
  if (boardh[kingx] || boardv[kingy])
  {
    GameEx exp;
    exp.type = 0;
    throw exp;
  }

  if (boardh[kingx+1]) dx =  1;
  if (boardh[kingx-1]) dx = -1;
  if (boardv[kingy+1]) dy =  1;
  if (boardv[kingy-1]) dy = -1;

  printf("%d %d\n", kingx+dx, kingy+dy);
  fflush(stdout);
}

bool goat (const int tax, const int tay)
{
  int mx=0, my=0;
  if (kingx == tax && kingy == tay) return true;

  if (kingx != tax)
  {
    if      (kingx > tax) mx = -1;
    else if (kingx < tax) mx =  1;
  }
  else
  {
    if      (kingy > tay) my = -1;
    else if (kingy < tay) my =  1;
  }

  putMove(mx, my);

  if (kingx == tax && kingy == tay) return true;
  return false;
}

int main ()
{
  scanf("%d %d", &kingx, &kingy);
  for (int i=0; i<ROOKS; ++i) // input
  {
    scanf("%d %d", &rooks[i].posx, &rooks[i].posy);
    ++ boardh[rooks[i].posx];
    ++ boardv[rooks[i].posy];
    sboard[rooks[i].posx][rooks[i].posy] = true;
  }

  // stage 1: move to the center
  for (; !(kingx == kingy && kingy == 500);)
  {
    if (boardh[kingx] || boardv[kingy]) return 0; // got checked

    goat(500, 500); // go at (500, 500);

    try { getMove(); } catch (GameEx e) {
      if (e.type == 0) return 0;
      throw e;
    }
  }

  // stage 2: count
  int quad_count[4] = { };
  for (int i=0; i<ROOKS; ++i)
  {
    int posb = 15; // snowflake representing the quadrants
    /*
           |
      0010 | 0001
     ------+------
      0100 | 1000
           |
     */
    if (rooks[i].posx > 500) posb &= 9;
    if (rooks[i].posx < 500) posb &= 6;
    if (rooks[i].posy > 500) posb &= 12;
    if (rooks[i].posy < 500) posb &= 3;

    ++ quad_count[(int)log2(posb)];
  }

  int targx, targy;

  int mmin=200, midx=4; for (int i=0; i<4; ++i) if (quad_count[i]<mmin) {mmin=quad_count[i]; midx=i;}
  switch (midx)
  {
    case 0:
      targx = 999;
      targy = 0;
      break;
    case 1:
      targx = 0;
      targy = 0;
      break;
    case 2:
      targx = 0;
      targy = 999;
      break;
    default:
      targx = 999;
      targy = 999;
      break;
  }

  // stage 3: move
  for (; !goat(targx, targy);)
  {
    if (boardh[kingx] || boardv[kingy]) return 0; // got checked

    goat(targx, targy);

    try { getMove(); } catch (GameEx e) {
      if (e.type == 0) return 0;
      throw e;
    }
  }

  return 0;
}


/*
 1 6

 */
