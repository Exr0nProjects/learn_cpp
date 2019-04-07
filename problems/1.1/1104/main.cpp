#include <iostream>


using namespace std;

int main() {
  int a, b, al, bl, e, el;
  cin >> a;
  cin >> b;
  e = a + b;

  if (a >= 100) al = 3;
  else if (a >= 10) al = 4;
  else al = 5;

  if (b >= 100) bl = 3;
  else if (b >= 10) bl = 4;
  else bl = 5;

  if (e >= 100) el = 4;
  else if (e >= 10) el = 5;
  else el = 6;

  cout << a << "+" << b << "=" << e << endl;

  cout << " ";
  for (int fli=0; fli<al; fli++) cout << " ";
  cout << a << endl;

  cout << "+";
  for (int fli=0; fli<bl; fli++) cout << " ";
  cout << b << endl;

  for (int fli=0; fli<7; fli++) cout << "-";
  cout << endl;

  for (int fli=0; fli<el; fli++) cout << " ";
  cout << e << endl;

  return 0;
}
