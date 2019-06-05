/*
 * Problem #3556
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main()
{
  int a,b;
  while(cin >> a >> b)
  {
    if(a==0 && b==0) break;
    cout << a + b << endl;
  }
}
