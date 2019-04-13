/*
 * Problem #1175
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int weight;
  cin >> weight;

  if (!(weight%2) && weight > 2) cout << "YES, you can divide the watermelon into two even parts.";
  else cout << "NO, you can't divide the watermelon into two even parts.";


  return 0;
}
