/*
 * Problem #3561
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int find (int amnt)
{
  int * in_arr;
  in_arr = new int[amnt];
  for (int i=0; i<amnt; ++i) cin >> in_arr[i];

  int find;
  cin >> find;

  for (int i=0; i<amnt; ++i)
  {
    if (in_arr[i] == find)
    {
      cout << i;
      return 0;
    }
  }
  cout << "No";
  return 1;
}

int main ()
{
  int num;
  while (cin >> num)
  {
    find(num);
    cout << endl;
  }

  return 0;
}
