/*
 * Problem #6
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  long y, k, t, x;
  cin >> y >> k >> t;

  if (k < 1)
  {
    cout << "-1";
    return 0;
  }

  bool gone = false;

  while (x+y <= t)
  {
    if (gone)
    {
      cout << " " << x;
      x += k;
    }
    else
    {
      if ((y+x)%k == 0)
      {
        gone = true;
        cout << x;
        x += k;
      }
      else ++ x;
    }
  }

  if (!gone) cout << "-1";

  cout << flush;

  return 0;
}
