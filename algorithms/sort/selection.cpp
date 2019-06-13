/*
 * Selection sort
 * 13 June 2019
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int num, min, mindx, sub;
  int array [1010];
  cin >> num;
  for (int i=0; i<num; ++i) cin >> array[i];

  for (int i=0; i<num; ++i)
  {
    min = 1000000010; // 10^9 + 10
    sub = i;
    for (; sub<num; ++sub) if ( array[sub] < min )
    {
      min = array[sub];
      mindx = sub;
    }

    if (min < array[i])
    {
      array[mindx] = array[i];
      array[i] = min;
    }
    cout << array[i] << " ";
  }

  return 0;
}
