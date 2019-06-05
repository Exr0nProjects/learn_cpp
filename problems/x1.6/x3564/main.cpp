/*
 * Problem #3564
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int print_below_avg (int num)
{
  int * in_arr;
  in_arr = new int[num];
  int temp, in_sum = 0;

  for (int i=0; i<num; ++i)
  {
    cin >> temp;
    in_sum += temp;
    in_arr[i] = temp;
  }

  double mean = (double) in_sum / (double) num;

  for (int i=0; i<num; ++i)
  {
    if ((float) in_arr[i] < mean) cout << in_arr[i] << " ";
  }
  cout << endl;

  return 0;
}

int main ()
{
  int amnt;
  while (cin >> amnt)
  {
    print_below_avg(amnt);
  }

  return 0;
}
