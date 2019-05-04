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

/*
#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  string line, line1, line2;
  bool gone = false;
  while (getline(cin, line))
  {
    getline(cin, line1);
    getline(cin, line2);

    if (gone) cout << endl;
    else gone = true;

    cout << line << endl << line1 << endl << line2;
    getline(cin, line); // remove trailing newline in input
  }
  //cout << line;

  return 0;
}
*/
