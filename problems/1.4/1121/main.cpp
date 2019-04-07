/*
 * Problem #1121
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int total, pos=0, neg=0, zero=0, temp;
  cin >> total;

  for (int i=0; i<total; ++i)
  {
    cin >> temp;
    if (temp == 0) ++ zero;
    else if (temp > 0) ++ pos;
    else ++ neg;
  }

  cout << pos << "\n" << zero << "\n" << neg;

  return 0;
}
