/*
 * Problem #1185
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  long idx, last=0, curr=1;
  cin >> idx;

  for (int i=1; i < idx; ++i)
  {
    long temp = curr;
    curr += last;
    last = temp;
  }

  cout << last;

  return 0;
}
