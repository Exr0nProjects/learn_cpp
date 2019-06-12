/*
 * Problem #1127
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int max;
  cin >> max;

  for (int i=2020; i <= max; ++i)
  {
    if ( (i/100 + i%100) * (i/100 + i%100) == i) cout << i << endl;
  }

  return 0;
}
