/*
 * Problem #7087
 * tree conversion
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double

using namespace std;

string reduce (string left, string center)
{
 //   cout << "  d: " << left << "  " << center << endl;
    if (left.length() <= 1 || center.length() <= 1) return left;
    
    int cidx = center.find(left[0]);
    return reduce(left.substr(1, cidx), center.substr(0, cidx)) + reduce(left.substr(cidx+1), center.substr(cidx+1)) + left[0];
}

int main ()
{
    int legit = 1000000000;
  while (--legit)
  {
      string l, c;
      cin >> l >> c;
      cout << reduce(l, c) << endl;
  }

  return 0;
}
