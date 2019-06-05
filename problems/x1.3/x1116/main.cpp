/*
 * Problem #1116
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int iters;
  cin >> iters;

  long double ans = 0;

  for (double i=1; i<=iters; i++)
  {
    ans += 1/i;
  }

  cout.precision(6);
  cout << fixed;

  cout << ans;

  return 0;
}
