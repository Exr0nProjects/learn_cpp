/*
 * Problem #1120
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int sum_digits (int num)
{
  int sum = 0;
  for (int i=0; i<7; ++i) {
    sum += num / (int) pow(10, i) % 10; // this could be more efficient
  }
  return sum;
}

int main ()
{
  int a, b, count=0;
  cin >> a >> b;

  if (b > 11111) b = 11112; // anything bigger will have a sum more than five so we don't have to check them

  for (int i=a; i<b; ++i)
  {
    if (sum_digits(i) % 5) continue;
    ++ count;
  }

  cout << count;

  return 0;
}
