/*
 * Problem #1115
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int max;
  cin >> max;

  long ans = 0;

  for (int i=0; i<=max; i+=7)
  {
    ans += i;
  }

  cout << ans;

  return 0;
}
