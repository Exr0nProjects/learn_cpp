/*
 * Problem #1186
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int temp;
  for (int i=0; i<5; ++i)
  {
    for (int j=0; j<5; ++j)
    {
      cin >> temp;
      if (temp == 1)
      {
        cout << abs(i-2) + abs(j-2);
        return 0;
      }
    }
  }

  return 0;
}
