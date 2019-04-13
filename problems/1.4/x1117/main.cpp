/*
 * Problem #1117
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  double year;
  cin >> year;

  cout.precision(2);
  cout << fixed;
  cout << 100 * pow(1.08, year);

  return 0;
}
