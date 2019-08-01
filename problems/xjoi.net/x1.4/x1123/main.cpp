/*
 * Problem #1123
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


bool is_palindrome (int num)
{
  int digits = (int) log10(num);
  //cout << "\nchecking if palindrome: " << num << "\nlen: " << digits << endl;
  for (int i=0; i<(digits+1)/2; ++i)
  {
    //cout << (num / (int) pow(10, i) %10) << " " << (num / (int) pow(10, digits-i) %10) << " " << ((num / (int) pow(10, i) %10) != (num / (int) pow(10, digits-i))) << endl;
    if ( (num / (int) pow(10, i) %10) != (num / (int) pow(10, digits-i)) ) return false;
  }
  //cout << "Yay!" << endl;
  return true;
}

int main ()
{
  int max;
  cin >> max;

  for (int i=1; i<=max; ++i)
  {
    if (is_palindrome(i)) cout << i << endl;
  }

  return 0;
}
