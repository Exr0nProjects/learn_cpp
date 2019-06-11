/*
 * Problem #1359
 * radx conversion
 * issue: input could be in different radix than expected, how to deal? todo
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const char letters [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int getNum (string s, int r)
{
  long fin = 0;
  for (int i=0; i<s.size(); ++i)
  {
    char c = s[s.size()-i-1]; // start from the back of the full string

    //cout << "  " << c << ": " << (int) c << endl;

    if (64 < c && c < 71) fin += (c - 55) * (long) pow(r, i); // [A:F]
    else if (47 < c && c < 58) fin += (c - 48) * (long) pow(r, i); // [0:9]

    else return -1; // something went wrong
  }
  return fin;
}

string getChr (long n, int r)
{
  string fin;
  do
  {
    fin.insert(0, 1, letters[n%(long)r]);
    n /= (long) r;
    //cout << "  " << fin << ", " << n << endl;
  }
  while (n > 0);
  return fin;
}

int main ()
{
  int a, b;
  string n;
  cin >> a >> n >> b;
  //cout << n << ": " << n.size() << endl ;

  long dec = getNum(n, a);
  //cout << dec << endl;
  string fin = getChr(dec, b);
  cout << fin;

  return 0;
}
