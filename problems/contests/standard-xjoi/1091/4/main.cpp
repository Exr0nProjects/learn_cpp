/*
 * Problem #4
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int tot, f, b;
  cin >> tot >> f >> b;

  if (tot - b - 1 > f) cout << b + 1;
  else cout << tot - f;

  return 0;
}
