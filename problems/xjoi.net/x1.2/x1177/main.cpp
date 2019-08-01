/*
 * Problem #1177
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  long n, m, a, dn, dm;
  cin >> n;
  cin >> m;
  cin >> a;

  dn = n/a;
  dm = m/a;

  if (n%a) dn += 1; // if its not a perfect fit, add an extra tile on one end
  if (m%a) dm += 1;

  cout << dn * dm;

  return 0;
}
