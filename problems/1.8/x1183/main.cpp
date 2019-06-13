/*
 * Problem #1183
 * prime factor
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int primes [500] = {};

int decomp (int num)
{
  //cout << "decomp: " << num << endl;
  if (num == 1) return 1;
  for (int i=2; i<=num; ++i) if (num % i == 0) return i;
  return 1;
}

int main ()
{
  int num, cp, ret=0, last=0, count=-1;
  cin >> num;

  if (num ==1) { cout << "1=1"; return 0; }

  cp = num;
  string fin = to_string(num) + "=";
  while (ret != 1)
  {
    if (ret == last || num*ret == cp) ++ count;
    else
    {
      //cout << "factor over: " << last << endl;
      if (last == 0) last = num*ret;
      fin += to_string(last);
      if (count > 1) fin += "^" + to_string(count);
      fin += "*";

      count = 1;
    }

    last = ret;
    ret = decomp(num);
    num /= ret;
  }
  //cout << num << " " << ret << " " << last << " " << count << ": " << fin << endl;
  fin += to_string(last);
  if (count > 1) fin += "^" + to_string(count);

  cout << fin;

  return 0;
}
