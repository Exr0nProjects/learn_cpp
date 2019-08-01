#include <iostream>


using namespace std;

int main() {

  int t, b, h;
  cin >> t;
  cin >> b;
  cin >> h;

  float o = ((float) t + (float) b)/2.0*(float) h;
  int i = (int) (o*1000);

  cout << i/1000 << "." << i%1000/100 << i%100/10 << i%10;

  return 0;
}
