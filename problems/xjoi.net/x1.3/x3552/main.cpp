/*
 * Problem #3552
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int iters;
  cin >> iters;

  long ans = 0;

  for (int i=1; i<iters; i++)
  {
    ans += i*(iters-i+1);
  }

  cout << ans;

  return 0;
}
