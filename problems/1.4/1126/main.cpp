/*
 * Problem #1126
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int max;
  cin >> max;

  for (int i=23; i <= max; i += 105)
  {
    cout << i << endl;
  }

  return 0;
}
