/*
 * Problem #1113
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int sumto;
  cin >> sumto;

  long ans = (long) ( (sumto+1) * (sumto/2) );
  if (sumto % 2) ans += (long) (sumto/2 + 1);

  cout << ans;

  return 0;
}
