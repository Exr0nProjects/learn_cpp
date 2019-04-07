/*
 * Problem #3536
 *
 * "even" if integer is even, "odd" if odd
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int check;
  cin >> check;

  if (check%2) cout << "odd";
  else cout << "even";

  return 0;
}
