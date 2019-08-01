/*
 * Problem #1122
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int factorial (int num)
{
  int ans = 1;
  for (int i=2; i<=num; ++i) ans *= i;

  return ans;
}

int main ()
{
  int n, ans = 0;
  cin >> n;

  for (int i=1; i<=n; ++i)
  {
    ans += factorial(i);
  }

  cout << ans;

  return 0;
}
