#include <iostream>
#include <math.h>


using namespace std;

template <class T>
T round_ (T num)
{
  // require math.h
  T num_modded = abs(num%10);

  num -= num%10;
  if (num_modded > 4)
  {
    if (num > 0) num += 10;
    else num -= 10;
  }
  return num;
}



int main() {
  long r, ans;
  cin >> r;
  ans = round_<long>(r);
  cout << ans;

  return 0;
}
