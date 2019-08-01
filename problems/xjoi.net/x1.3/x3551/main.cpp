/*
 * Problem #3551
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int iters;
  cin >> iters;

  long double ans=1;

  for (int i=2; i<iters; i++)
  {
    if (i%2) ans += 1 / (long double) (i/2+1);
    else ans -= 1 / (long double) (i/2+1);
  }

  cout.precision(3);
  cout << fixed;

  cout << ans;

  return 0;
}
