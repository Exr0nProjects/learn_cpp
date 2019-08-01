#include <iostream>


using namespace std;

int main() {
  int w, h, d;
  cin >> w;
  cin >> h;
  cin >> d;

  int s = 2*(w*h + h*d + w*d);
  int v = w*h*d;

  cout << s << endl << v;

  return 0;
}
