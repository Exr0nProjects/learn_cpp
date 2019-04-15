/*
 * Problem #1211
 * minesweeper
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int countAround (int ** field, int height, int width)
{
  // TODO!
}

int main ()
{
  int width, height;
  cin >> height, width;

  int **field = new int * [height];
  for (int i=0; i<height; ++i) field[height] = new int[width];

  string temp;
  for (int i=0; i<height; ++i)
  {
    getline(cin, temp);
    for (int j=0; j<width; ++j)
    {
      switch (temp[j])
      {
        case '?':
          field[i][j] = 0;
          break;
        case '*':
          field[i][j] = 1;
          break;
        default: return 1; // something went wrong
      }
    }
  }

  char **end = new char * [height];
  for (int i=0; i<height; ++i) end[i] = new char [width];

  for (int i=1; i<height; ++i)
  {
    for (int j=1; j<height; ++j)
    {
      if (field[i][j] == 1) cout << '*';
      else end[i][j] = '0' + countAround(field, i, j);
    }
  }

  return 0;
}
