#include <iostream>
#include <math.h>

template <class T>
T round_ (T num)
{ // require math.h
  T num_modded = abs(num%10);

  num -= num%10;
  if (num_modded > 4)
  {
    if (num > 0) num += 10;
    else num -= 10;
  }

  return num;
}

template <class T, class N>
int coutDigits_ (T num, N p)
{ // require <math.h>, round_
  long long mult = (long double) num * pow(10, p+1);

  mult = (long long) round_(mult)/10;

  cout << mult/(long long)pow(10, p) << ".";

  for (int i=p; i>0; --i) {
    cout << abs(mult) % (long long) pow(10, i) / (long long) pow(10, i-1); // this could be more efficient
  }
  return 0;
}


using namespace std;

int main() {
  double r;
  cin >> r;

  double pi = 3.14159; // this is the constant that they use, cannot be any more percise

  long c = (long) (r*2.0*pi*1000000);
  long a = (long) (r*r*pi * 1000000);

  coutDigits_(c, 6);
  cout << endl;
  coutDigits_(a, 6);

  return 0;
}
