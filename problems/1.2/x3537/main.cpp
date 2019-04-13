/*
 * Problem #3537
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int year;
  cin >> year;

  if (!(year%4)) {
    if (!(year%100) && year%400) cout << "no";
    else cout << "yes";
  } else cout << "no";

  return 0;
}
