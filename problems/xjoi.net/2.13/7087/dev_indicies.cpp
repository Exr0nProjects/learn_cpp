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

string l, c;

string reduce (int ls, int le, int cs, int ce)
{
    string ret = "";
    if (le-ls <= 1 || ce-cs <= 1) return ret + l[ls];
    
    int cidx = c.find(l[ls], cs);
    return reduce(ls+1, cidx+1, cs, cidx) + reduce(cidx+1, l.length(), cidx+1, c.length()) + l[0];
}

int main ()
{
    int legit = 1000000000;
  while (--legit)
  {
      cin >> l >> c;
      cout << reduce(0, l.length(), 0, c.length()) << endl;
  }

  return 0;
}
