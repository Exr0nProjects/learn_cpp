/*
 * Problem #7987
 * palendromeify
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;


int main ()
{
  string num, ret;
  cin >> num;

  for (int i=num.length()-1; i>=0; --i)
  {
    ret += num[i];
  }

  cout << ret + num; 

  return 0;
}
