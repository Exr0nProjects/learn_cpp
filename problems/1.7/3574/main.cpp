/*
 * Problem #3574
 * Multiple sets of test data in a two-dimensional character array
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  string line;
  bool gone = false;
  while (getline(cin, line))
  {
    for (int i=0; i<3; ++i)
    {
      if (gone) cout << endl;
      else gone = true;
      cout << line;
      if (!getline(cin, line)) break;
    }
  }
  //cout << line;

  return 0;
}
