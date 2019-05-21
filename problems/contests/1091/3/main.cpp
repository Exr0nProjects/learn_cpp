/*
 * Problem #3
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool isprime(int num)
{
  if (num == 2) return true;
  if (num < 2 || !(num%2)) return false;
  for (int i=3; i*i <= num; i += 2)
  {
    if (!(num%i)) return false;
  }
  return true;
  /*
  if (!(num%2) || !(num%3) || !(num%5) || !(num%7) || !(num%11)) return false;
  for (int i=13; i * i < num; i += 2310)
  {
    if ()
  }
  */
}

int main ()
{
  long num;

  bool gone;
  while (cin >> num)
  {
    if (sqrt(num) == (double) (int) sqrt(num)) // perfect square
    {
      if ( isprime( (int) sqrt(num) ) )
      {
        if (gone) cout << endl;
        else gone = true;
        cout << "YES";
        continue;
      }
    }
    if (gone) cout << endl;
    else gone = true;
    cout << "NO";
  }

  return 0;
}
