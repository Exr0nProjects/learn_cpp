/*
 * Problem #1203
 * ceaser shift by 1
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  string message;
  getline(cin, message);

  for (int i=0; i<message.length(); ++i)
  {
    if (message[i] == ' ')
    {
      cout << ' ';
      continue;
    }
    cout << (char) (( (int)message[i]-96 ) %26 + 97);
  }

  return 0;
}
