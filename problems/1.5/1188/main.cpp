/*
 * Problem #1188
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int a, b, health;
  cin >> a >> b >> health;

  for (int i=0; i<=health; i+=a)
  {
    if ((health-i) % b == 0)
    {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

  return 0;
}
