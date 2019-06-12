/*
 * 11 June 2019
 * insertion sort
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int size, temp, pt;
  cin >> size;
  int array [1010];
  for (int i=0; i<size; ++i) cin >> array[i];

  for (int i=1; i<size; ++i)
  {
    pt = i;
    temp = array[i];
    while (temp < array[pt-1])
    {
      array[pt] = array[pt-1];
      array[pt-1] = temp;
      --pt;
      if (pt == 0) break;
    }
  }

  for (int i=0; i<size; ++i) cout << array[i] << " ";

  return 0;
}
