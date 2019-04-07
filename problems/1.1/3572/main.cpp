// Problem #3572
// Compile: http://www.hzxjhs.com:83/detail/435397

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

int main() {

  // this weirdness because if we just had int a, b: inputting `5.5 2` would screw with everything somehow
  double a, b;
  cin >> a;
  cin >> b;
  cout << fixed;
  a = (int) (round_(a*10) / 10);
  b = (int) (round_(b*10) / 10);

  long double ans = (long double) a / (long double) b;


  cout.precision(3);
  cout << fixed << ans;

  return 0;
}
