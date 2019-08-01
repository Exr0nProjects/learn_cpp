/*
 * Problem #7981
 * steps needed for hanoi tower
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;


int main ()
{
  int num, steps = 1;
  cin >> num;

  for (int i=1; i<num; ++i) steps = 2*steps + 1;

  cout << steps;

  return 0;
}
