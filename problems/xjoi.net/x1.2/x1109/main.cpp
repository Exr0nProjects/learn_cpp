/*
 * Problem #1109
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int weight;
  cin >> weight;

  cout.precision(2);
  cout << fixed; // avoid sci notation

  if (weight < 0) cout << "NO"; // negative weight?
  else if (weight <= 30) cout << 0.2 * (double) weight; // standard rate
  else if (weight <= 60) cout << 6 + 0.6 * (double)(weight-30); // oversize rate
  else cout << "NO"; // too much to ship

  return 0;
}
