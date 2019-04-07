/*
 * Problem #3539
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num;
  cin >> num;

  if (num > 50 && !(num % 2)) cout << "yes";
  else cout << "no";

  return 0;
}
