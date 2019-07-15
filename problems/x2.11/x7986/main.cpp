/*
 * Problem #7986
 * reverse number
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;

string reverse (string num, string ret)
{
  if (num.length() == ret.length()) return ret;
  return reverse(num, ret + num[num.length() - ret.length() -1]);
}

int main ()
{
  string num, ret;
  cin >> num;

  cout << reverse(num, ret);

  return 0;
}
