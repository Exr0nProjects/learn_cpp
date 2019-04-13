/*
 * Problem #3565
 * count numbers
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int place (int * count_arr; int * index_arr; int amnt; int num)
{
  for (int i=0; i<amnt; ++i)
  {
    if (index_arr[i] == num)
    {
      ++ count_arr[i];
      return 0;
    }
    else if (index_arr[i] == -1) // reached the end
    {
      index_arr[i] = num;
      count_arr[i] = 1;
      return 0;
    }
  }
  return 1; // something went wrong
}

int main ()
{
  int amnt, temp;
  cin >> num;

  int * count_arr = new int [amnt] {}; // up to 20 different numbers
  int * index_arr = new int [amnt] {-1}; // same as above

  for (int i=0; i<num; ++i)
  {
    cin >> temp;
    place(count_arr, index_arr, amnt, temp);
  }

  int max=0, num=0;
  for (int i=0; i<amnt; ++i)
  {
    if (count_arr[i] > max)
    {
      max = count_arr[i];
      num = index_arr[i];
    }
  }

  cout << num;

  return 0;
}
