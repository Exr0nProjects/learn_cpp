/*
 * Problem #1147
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num, sum=0;
  cin >> num;

  for (int i=0; num != 0; ++i)
  {
    sum += num % 10;
    num /= 10;
  }

  cout << sum;

  return 0;
}
