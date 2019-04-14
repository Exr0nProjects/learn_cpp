/*
 * Problem #1170
 * spiral matrix
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int size;
  cin >> size;

  int **matrix =  new int * [size];
  for (int i=0; i<size; ++i) matrix[i] = new int [size]

  int pointx=0, pointy=0, dir=1; // dir: 0: up 1:right 2:bot 3:left
  for (int count=0; count<size*size; ++count)
  {
    matrix[pointy][pointx] = count;

    // change direction
    if (pointy+pointx+1 == size
    || (y==x   && x>=size/2)
    || (y==x+1 && x< size/2) ) ++ dir;

    // move direction
    switch (dir)
    {
      case 0:
        -- pointy;
        break;
      case 2:
        ++ pointy;
        break;
      case 1:
        ++ pointx;
        break;
      case 3:
        -- pointx;
        break;
    }
  }

  for (int i=0; i<size; ++i)
  {
    for (int j=0; j<size; ++j)
    {
      cout << matrix[i][j];
      if (!(j==size-1)) cout << " ";
    }
    if (!(i==size-1)) cout << endl;
  }

  return 0;
}
