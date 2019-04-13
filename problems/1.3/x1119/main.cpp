/*
 * Problem #1119
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int idx, last2=0, last=1, curr=1, temp;
  cin >> idx;

  for (int i=1; i<idx; i++)
  {
    temp = curr;
    curr += last2 + 2*last;
    last2 = last;
    last = temp;
  }

  cout << last2;

  return 0;
}
