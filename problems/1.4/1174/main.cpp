/*
 * Problem #1174
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool is_prime (int num)
{
  if (num == 1) return false;
  else if (num == 2) return true;
  else if (!(num%2)) return false;
  else {
    int final = (int) sqrt(num) +1;
    for (int i=3; i <= final; i += 2)
    {
      if (!(num % i)) return false;
    }
    return true;
  }
}

int main ()
{
  int num_n, p;
  cin >> num_n;

  for (int i=0; i < num_n; ++i)
  {
    cin >> p;
    if (is_prime(p)) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
