/*
 * Problem #1205
 * count around a circle, last one standing
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int p, s, a, death; // people, start, ammount
  cin >> p >> s >> a;

  int * table = new int[p];
  for (int i=0; i<p; ++i) table[i] = i;

  while (p > 1)
  {
    int death = (s+a-1)%p;
    for (int i=death; i<p; ++i) table[i] = table[i+1]; // shift everyone over to replace the out person
    -- p;
    s = death;
  }

  cout << table[0];

  return 0;
}
