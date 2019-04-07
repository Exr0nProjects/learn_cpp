/*
 * Problem #1114
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num_n, min, max;
  cin >> num_n;

  cin >> min; // init these values to something in the dataset
  max = min;

  for (int i=1; i<num_n; ++i)
  {
    int n;
    cin >> n;
    if (n > max) max = n;
    else if (n < min) min = n;
  }

  cout << max << "\n" << min;

  return 0;
}
