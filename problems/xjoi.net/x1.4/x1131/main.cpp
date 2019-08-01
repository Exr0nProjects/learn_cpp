/*
 * Problem #1131
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int money, pers=0;
  cin >> money;

  for (int i=0; i<=money/5; ++i) // from zero 5yuan to all 5yuan
  {
    pers += (money - 5*i) / 2 + 1; // zero 2yuan to all 2yuan
  }

  cout << pers;

  return 0;
}
