/*
 * Problem #1138
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int layers, count = 1;
  cin >> layers;

  for (int i=1; i<=layers; ++i)
  {
    for (int j=0; j<i; ++j)
    {
      for (int k=0; k < 3-(int)log10(count); ++k) cout << " ";
      cout << count++;
    }
    if (i != layers) cout << "\n";
  }

  return 0;
}
