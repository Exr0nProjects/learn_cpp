/*
 * Problem #2
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int max, curr=0, sum=0;
  cin >> max;

  while (curr <= max)
  {
    sum += curr;
    curr += 7;
  }

  cout << sum;

  return 0;
}
