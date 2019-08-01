/*
 * Problem #1198
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int max (int amnt)
{
  int temp, max = 0;
  for (int i=0; i<amnt; ++i)
  {
    cin >> temp;
    if (temp > max) max = temp;
  }
  return max;
}

int main ()
{
  int num_a, num_b, max_a, max_b, temp;
  cin >> num_a >> num_b;
  max_a = max(num_a);
  max_b = max(num_b);

  cout << max_a + max_b;

  return 0;
}
