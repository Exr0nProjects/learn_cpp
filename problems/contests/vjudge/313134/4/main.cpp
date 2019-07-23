/*
 * VJudge 313134 D
 * Convert to DAG
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

const int MAXSZ = 100010;

int adjacent[MAXSZ][MAXSZ] = { };

int main ()
{
  int nnode, nedge;
  scanf("%d %d", nnode, nedge);
  for (int i=0; i<nedge; ++i)
  {
    int b, e, c;
    scanf("%d %d %d", b, e, c);
    adjacent[b][e] = c;
  }
  

  return 0;
}
