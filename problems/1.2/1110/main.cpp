/*
 * Problem #1110
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int year, month;
  cin >> year;
  cin >> month;

  switch ( month ) {
    case 2:
      if ( ( !(year%4) && year%100 ) || !(year%400)) cout << 29;
      else cout << 28;
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      cout << 31;
      break;
    default:
      cout << 30;
      break;
  }

  return 0;
}
