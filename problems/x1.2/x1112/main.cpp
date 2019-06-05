/*
 * Problem #1112
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  long a, b;
  cin >> a;
  cin >> b;

  if (a > b) cout << a << endl << b;
  else cout << b << endl << a;

  return 0;
}
