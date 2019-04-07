/*
 * Problem #3557
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int a, b, c;
  while (cin >> a >> b >> c)
  {
    if (!a) break;
    cout << a + b + c << "\n\n";
  }

  return 0;
}
