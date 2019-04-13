/*
 * Problem #1199
 * oier oier oier
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool check_line (string line)
{
  cout << "\n\nchecking line: " << line << "; length " << line.length();
  if ((line.length()+1) %5 != 0) return false; // multiple of five, cuz "oier " over and over except there is no last space so add one to compensate

  // now check each letter in turn
  for (int i=0; i<line.length(); i += 4)
  {
    cout << "\nidx: " << i << " char: " << line[i] << " true? " << (line[i] == 'o') << "\n\n\n\n\n";
    if (!(
      line[ i ] == 'o'
    &&line[i+1] == 'i'
    &&line[i+2] == 'e'
    &&line[i+3] == 'r'
    ))
    {
      return false; // something wasnt right
    }
    if (i != line.length() -4 && line[i+4] != ' ') return false;
  }
  return true; // it all checks out!
}

int main ()
{
  int amnt;
  cin >> amnt;

  string temp;
  for (int i=-1; i<amnt; ++i)
  {
    getline(cin, temp);
    if (check_line(temp))
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }

  return 0;
}
