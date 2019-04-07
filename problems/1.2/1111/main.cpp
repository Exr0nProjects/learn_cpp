/*
 * Problem #1111
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int nums[3];
  int min=1000000, max=0;
  cin >> nums[0];
  cin >> nums[1];
  cin >> nums[2];

  for (int i=0; i<3; ++i)
  {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }

  cout << "The maximum number is : " << max << endl;
  cout << "The minimum number is : " << min;

  return 0;
}
