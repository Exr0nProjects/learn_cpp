/*
 * Problem #1194
 * triple prime number
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int num;
  while (cin >> num)
  {
    if (num != 1 && (double) (int) sqrt(num) == sqrt(num) && ((int) sqrt(num) %2 == 1 || (int) sqrt(num) == 2))
    {
      int test = 3, comp = 0;
      num = (int) sqrt(num);
      while (test <= (int) sqrt(num))
      {
        if (num % test == 0)
        {
          comp = 1;
          break;
        }
        else
          test += 2;
      }
      if (comp == 0) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
  }

  return 0;
}
