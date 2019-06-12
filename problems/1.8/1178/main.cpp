/*
 * Problem #1178
 * empty rooms
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int tot, ocu, max;
  cin >> tot >> ocu;

  if (ocu == 0 || ocu == tot) cout << "0 0";
  else
  {
    if (ocu <= tot/3) max = 2*ocu;
    else max = tot-ocu;
    cout << "1 " << max;
  }
  return 0;
}
