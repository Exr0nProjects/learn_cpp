/*
 * Problem #1
 * biggest and smallest
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num, min=-2147483647, max=2147483647, temp;
  cin >> num;

  for (int i=0; i<num; ++i)
  {
    cin >> temp;
    if (temp > max) max = temp;
    if (temp < min) min = temp;
  }
  cout << max << endl << min << endl;

  return 0;
}
