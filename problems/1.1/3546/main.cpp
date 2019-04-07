#include <iostream>


using namespace std;

int main() {
  int h1, m1, h2, m2;

  cin >> h1;
  cin >> m1;
  cin >> h2;
  cin >> m2;

  cout << (h2-h1)*60 + m2-m1;

  return 0;
}
