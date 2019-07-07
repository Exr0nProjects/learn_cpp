/*
 * Problem #7805
 * add fractions of a number
 */

#include <bits/stdc++.h> // includes "everything"

using namespace std;


int main ()
{
  long num, end;
  cin >> num;

  for (int i=1; i<=num; ++i) end += num/i;

  cout << end;

  return 0;
}
