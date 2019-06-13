/*
 * Bubble sort
 * 13 June 2019
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main ()
{
  int num, temp;
  int array [1010];
  cin >> num;
  for (int i=0; i<num; ++i) cin >> array[i];

  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num-i-1; ++j)
    {
      if (array[j] > array[j+1])
      {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  for (int i=0; i<num; ++i) cout << array[i] << " ";

  return 0;
}
