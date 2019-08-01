#include <iostream>

using namespace std;

int main () {
  float n;
  cin >> n;

  int i = (int) (n*10000);

  if (i%10 >= 5) {
    i += 10 - (i%10);
  }
  i /= 10;
  cout << i/1000 << "." << i%1000/100 << i%100/10 << i%10;
}
 // bit of a bodge job...
