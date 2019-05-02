/*
 * Problem #3289
 * face recognition
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool checkPos (char ** matrix, int y, int x)
{
  int legit = 0;
  for (int i=-1; i<1; ++i) for (int j=-1; j<1; ++j) switch (matrix[y+i][x+j])
  {
    case ('f'):
      legit += 8; break;
    case ('a'):
      legit += 4; break;
    case ('c'):
      legit += 2; break;
    case ('e'):
      legit += 1; break;
  }
  if (legit == 15) return true;
  else return false;
}

int main ()
{
  int w, h;
  cin >> h >> w;

  char ** matrix = new char * [h];

  string temp;
  getline(cin, temp);
  for (int i=0; i<h; ++i)
  {
    char * tempa = new char [w];
    cout << "on row " << i << endl;

    getline(cin, temp);
    cout << "got line: " << temp << endl;
    for (int j=0; i<w; ++j) tempa[j] = temp[j];

    matrix[i] = tempa;
    cout << "finished inserting" << endl;
  }
  cout << "input complete" << endl;

  int valid_places = 0;
  for (int i=1; i<h; ++i) for (int j=1; j<w; ++j) if ( checkPos(matrix, i, j) ) ++ valid_places;

  cout << valid_places;

  return 0;
}
