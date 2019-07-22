/*
 * VJudge 313134 B
 * circle surrounding thing
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

int main ()
{
  double csize, ncirc;
  scanf("%lf %lf", &ncirc, &csize);

  cout.precision(7);
  cout.setf( ios::fixed, ios::floatfield );

  double ret =(csize/(   ( 1/  sin(PI/ncirc) ) -1)   );

  cout << ret;

  return 0;
}


/*
 1 6

 */
