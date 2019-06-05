/*
 * Problem #1182
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int max, arrsqrt;
  cin >> max;

  arrsqrt = (int) sqrt(max) +1;
  int * arr;
  arr = new int [max+1]; // this could probably be half as big seeing as we are hard coding 2 anyways

  if (max > 1) cout << "2";

  // is there a way to init the array so we dont have to do this
  for (int i=3; i < max; i += 2) arr[i] = 1;

  for (int i=3; i < arrsqrt; i += 2)
  {
    if (arr[i] == 1)
    {
      cout << i << " ";
      int j = 2*i;
      while (j <= max)
      {
        arr[j] = 0; // its composite
        j += i; // could be int j=3*i and j += 2*i cuz we are avoiding evens that way but eh
      }
    }
  }

  return 0;
}
