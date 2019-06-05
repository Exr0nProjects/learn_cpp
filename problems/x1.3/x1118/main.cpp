/*
 * Problem #1118
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int idx, a=0, b=1, temp;
  cin >> idx;

  cout << "0 ";

  for (int i=1; i<idx; i++)
  {
    temp = b;
    b += a;
    a = temp;
    cout << a << " ";
  }

  return 0;
}
