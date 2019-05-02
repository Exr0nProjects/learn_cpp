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
  while (getline(cin, line))
  {
    for (int i=0; i<3; ++i)
    {
      cout << line << endl;
      getline(cin, line);
    }
  }

  return 0;
}
