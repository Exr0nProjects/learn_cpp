/*
 * Problem #1013
 * labrynth
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int n; // positive int n < 15
  cin >> n;
  bool ** lab = new bool * [n];
  for (int i=0; i<n; ++i)
  {
    lab[n] = new bool [n];
    string line;
    getline(cin, line);
    for (int j=0; j<2*n; j += 2)
    {
      lab[i][j] = (bool) ( (int) line[j] -48 );
      cout << lab[i][j];
    }
    cout << endl;
  }



  return 0;
}

/** test data
5
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

*/
