/*
 * Problem #3562
 * delete number from array
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int coutPop (int * array, int size, int find)
{
  int * end_array = new int [size];
  bool contains = false;

  for (int i=0; i<size; ++i)
  {
    if (array[i] != find || contains)
    {
      cout << array[i];
      if (i != size - 1) cout << " ";
    }
    else
    {
      contains = true;
    }
  }

  cout << endl;

  return 0;
}

int main ()
{
  int size, find;
  cin >> size;

  int * arr = new int[size];
  for (int i=0; i<size; ++i) cin >> arr[i];

  cin >> find;

  coutPop(arr, size, find);

  return 0;
}
