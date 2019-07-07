/*
 * quicksort 5 july 2019
 * based on https://medium.com/karuna-sehgal/a-quick-explanation-of-quick-sort-7d8e2563629b
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void quicksort (vector<int>& arr, int size)
{
  vector<int> left (num); vector<int> right (num);
  int lpoint=0, rpoint=0;

  int pivot = arr[0];

  for (int i=1; i<size; ++i)
  {
    if (arr[i] < pivot) left[lpoint++] = arr[i];
    else right[rpoint++] = arr[i];
  }

  quicksort(left, lpoint);
  quicksort(right, rpoint);

  arr = left;
  arr[lpoint] = pivot;
  for (int i=0; i<rpoint; ++i) arr[i+lpoint+1] = right[i];

  return;
}

int main ()
{
  int num;
  cin >> num;
  vector <int> arr (num);
  for (int i=0; i<num; ++i) cin >> arr[i];

  quicksort(arr, num);

  for (int i=0; i<num; ++i) cout << arr[i] << " ";

  return 0;
}
