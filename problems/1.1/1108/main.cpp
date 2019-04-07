#include <iostream>
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


template <class T, class N>
int coutDigits_ (T num, N p)
{ // require <math.h>, round_
  long long mult = (long double) num * pow(10, p+1);

  mult = (long long) round_(mult)/10;

  cout << mult / (long long) pow(10, p) << ".";

  for (int i=p; i>0; --i) {
    cout << abs(mult) % (long long) pow(10, i) / (long long) pow(10, i-1); // this could be more efficient
  }
  return 0;
}


int main() {
  long a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;

  long double avg = (a+b+c)/3;

  coutDigits_(avg, 6);

  return 0;
}
