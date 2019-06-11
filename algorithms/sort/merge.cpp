/*
 * Merge sort
 * 11 June 2019
 *
 */


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int * merge (int * ar1, int sz1, int * ar2, int sz2)
{
  int size = sz1 + sz2;
  int pt1=0, pt2=0;
  int * fin = new int [size];
  for (int i=0; i<size; ++i)
  {
    if      (pt1 == sz1) fin[i] = ar2[pt2++];
    else if (pt2 == sz2) fin[i] = ar1[pt1++];
    else if (ar1[pt1] <= ar2[pt2]) fin[i] = ar1[pt1++];
    else if (ar1[pt1] >= ar2[pt2]) fin[i] = ar2[pt2++];
  }

  return fin;
}

int * sort (int * arr, int size)
{
  if (size == 1) return arr;
  else
  {
    // segment the input
    int sz1 = size/2; int * ar1 = new int [sz1];
    int sz2 = size - size/2; int * ar2 = new int [sz2];
    for (int i=0; i<sz1; ++i)
    {
      ar1[i] = arr[i];
      ar2[i] = arr[i+sz1];
    }
    ar2[sz2 -1] = arr[size-1]; // update last element incase odd size array

    return merge( sort(ar1, sz1), sz1, sort(ar2, sz2), sz2 );
  }
}

int main ()
{
  int size;
  cin >> size;
  int * arr = new int [size];
  for (int i=0; i<size; ++i) cin >> arr[i];

  arr = sort (arr, size);
  for (int i=0; i<size; ++i) cout << arr[i] << " ";

  return 0;
}
