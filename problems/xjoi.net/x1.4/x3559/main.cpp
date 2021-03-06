/*
 * Problem #3559
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void print_layer (int number, int total)
{
  for (int j=0; j< total-number; ++j) cout << " ";
  for (int j=0; j< number *2 -1; ++j) cout << "*";
  for (int j=0; j< total-number; ++j) cout << " ";
  cout << "\n";
}

int main ()
{
  int layers;
  while (cin >> layers)
  {
    for (int i=1; i<layers; ++i) print_layer(i, layers);
    for (int i=layers; i>0; --i) print_layer(i, layers);
  }

  return 0;
}
