/*
 * Problem #3549
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int seq;
  cin >> seq;

  if (seq%2) cout << seq/2+1;
  else cout << "-" << seq/2;

  return 0;
}
