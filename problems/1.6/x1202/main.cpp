/*
 * Problem #1202
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int * one_day (int * plants)
{
  int start, stop, inc;
  cin >> start >> stop >> inc;

  for (int i=start-1; i<stop; ++i)
  {
    plants[i] += inc;
  }
  return plants;
}

int main ()
{
  int num_plants, num_days;
  cin >> num_plants;
  int * plants;
  plants = new int[num_plants];
  for (int i=0; i<num_plants; ++i) cin >> plants[i];
  cin >> num_days;

  for (int i=0; i<num_days; ++i)
  {
    plants = one_day(plants);
  }

  for (int i=0; i<num_plants; ++i) cout << plants[i] << " ";

  return 0;
}
