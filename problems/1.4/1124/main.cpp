/*
 * Problem #1124
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template <class T>
T round_ (T n)
{ // require math.h
  long long num = (long long) n;

  int num_modded = abs(num%10);

  num -= num%10;
  if (num_modded > 4)
  {
    if (num > 0) num += 10;
    else num -= 10;
  }

  return (T)num;
}

bool contains_five (int num)
{
  int digits = (int) log10(num) + 1;
  for (int i=0; i < digits; ++i)
  {
    if (num % 10 == 5) return true;
    num /= 10;
  }
  return false;
}

int main ()
{
  double m;
  cin >> m;

  int max = (int) round_(m*10)/10;

  for (int i=0; i<=max; i += 3)
  {
    if (contains_five(i)) cout << i << "\n";
  }

  return 0;
}
