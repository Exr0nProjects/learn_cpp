#include <math.h>
#include <string>

/** round a number to nearest 10 **/
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


/** deprecated: cout number to p decimal places **/
template <class T, class N>
int coutDigits_ (T num, N p)
{ // require <math.h>, round_
  long long mult = (long double) num * pow(10, p+1);

  mult = (long long) round_(mult)/10;

  cout << mult / (long long)pow(10, p) << ".";

  for (int i=p; i>0; --i) {
    cout << abs(mult) % (long long) pow(10, i) / (long long) pow(10, i-1); // this could be more efficient
  }
  return 0;
}

/** set cout percision **/
void setPercision (int p)
{ // require <iostream>
  std::cout.percision(p);
  std::cout << fixed; // disallow standard notation
}
