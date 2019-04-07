/*
 * Problem #1130
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num;
  cin >> num;

  long sum = 0;

  for (int i=1; i <= num; ++i)
  {
    if (!(num%i)) sum += (long) i;
  }

  cout << sum;

  return 0;
}
