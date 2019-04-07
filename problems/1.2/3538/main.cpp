/*
 * Problem #3538
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int sides[3];
  int max = 0, leg_sum = 0;

  for (int i=0; i<3; ++i)
  {
    cin >> sides[i]; // get number
    if (sides[i] > max) { // if biggest
      max = sides[i]; // get the max
    }
    leg_sum += sides[i] * sides[i]; // add square
  }

  if (leg_sum == max*max*2) cout << "yes"; // max squared *2 because max*max is already added in the sum
  else cout << "no";

  return 0;
}
