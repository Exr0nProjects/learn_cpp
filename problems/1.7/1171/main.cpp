/*
 * Problem #1171
 * serpentine matrix
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
  int size, tempstore;
  cin >> size;

  int ** matrix = new int * [size];
  for (int i=0; i<size; ++i) matrix[i] = new int [size];

  int posx=0, posy=0;
  bool diagup = false;
  for (int i=1; i<=size*size; ++i)
  {
    matrix[posy][posx] = i;
    tempstore = diagup;
    cout << posx << " " << posy << " and diagup: " << diagup << endl;
    if ( posx == 0 || posy == 0 || posx == size-1 || posy == size-1 )
    {
      cout << "on edge\n";
      if (posy == size-1 && posx == 0 && size%2 == 0) // corner
      {
        ++ posx;
        diagup = !diagup;
      }
      else if (size%2 == 1 && posx == size-1 && posy == 0) // corner
      {
        ++ posy;
        diagup = !diagup;
      }
      else if ((posx + posy) % 2 == 0) // top right edges
      {
        if (posy == 0) ++ posx;
        if (posx == size-1) ++ posy;
        diagup = !diagup;
      }
      else if ((posx + posy) % 2 == 1) // bottom left edges
      {
        if (posx == 0) ++ posy;
        if (posy == size-1) ++ posx;
        diagup = !diagup;
      }
    }
    if ( (diagup != tempstore) )
    {
      cout << "no edges\n";
      if (diagup)
      {
        cout << "traveling diagup\n";
        ++ posx;
        -- posy;
      }
      else
      {
        cout << "traveling diagdown\n";
        -- posx;
        ++ posy;
      }
    }
    cout << posx << " " << posy << "\n\n";
  }

  cout << "coolio\n";

  for (int i=0; i<size; ++i)
  {
    for (int j=0; j<size; ++j)
    {
      cout << matrix[i][j];
      if (!(j == size-1)) cout << " ";
    }
    if (!(i == size-1)) cout << endl;
  }

  return 0;
}
