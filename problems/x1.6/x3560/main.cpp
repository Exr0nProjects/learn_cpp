/*
 * Problem #3560
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int num_inps;
  cin >> num_inps;

  for (int inps_main=0; inps_main<num_inps; ++inps_main)
  {
    int inps;
    cin >> inps;
    int * in_arr;
    in_arr = new int [inps];
    for (int inps_sub=0; inps_sub<inps; ++inps_sub)
    {
      cin >> in_arr[inps_sub];
    }
    for (int inps_sub_print=inps-1; inps_sub_print>0; --inps_sub_print)
    {
      cout << in_arr[inps_sub_print] << " ";
    }
    cout << in_arr[0] << endl;
  }

  return 0;
}
