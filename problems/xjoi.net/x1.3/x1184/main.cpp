/*
 * Problem #1184
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int a, b, temp;
  cin >> a;
  cin >> b;

  while (b != 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }

  cout << a;

  return 0;
}
