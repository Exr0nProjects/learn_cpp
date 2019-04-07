/*
 * Problem #1187
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int pixels, sqroot;
  cin >> pixels;
  sqroot = (int) sqrt(pixels);

  for (int i=0; i<sqroot; ++i)
  {
    if (! (pixels % (sqroot-i)))
    {
      cout << (sqroot-i) << " " << pixels / (sqroot-i);
      return 0;
    }
    if (! (pixels % (sqroot+i)))
    {
      cout << (sqroot+i) << " " << pixels / (sqroot+i);
      return 0;
    }
  }

  return 0;
}
