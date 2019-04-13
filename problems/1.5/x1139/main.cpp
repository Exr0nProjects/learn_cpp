/*
 * Problem #1139
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char stack;
  cin >> stack;

  int idx = (int) alphabet.find(stack);

  for (int i=0; i<=idx; ++i)
  {
    for (int j=0; j<idx-i; ++j) cout << " ";
    for (int j=0; j<i; ++j) cout << alphabet[j];
    for (int j=i; j>=0; --j) cout << alphabet[j];
    if (i != idx) cout << "\n";
  }

  return 0;
}
