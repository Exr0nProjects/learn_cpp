/*
 * Problem #3550
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int start, count=0;
  cin >> start;

  while (start != 1)
  {
    ++ count;
    if (start%2) start = 3*start+1;
    else start /= 2;
  }

  cout << count;

  return 0;
}
