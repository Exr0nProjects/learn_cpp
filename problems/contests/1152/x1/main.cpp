/*
 * Post-array test (sub): Problem #1
 * 14 June 2019
 * spiral matrix
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{
  int matrix [20][20];
  bool flop = false;
  int size, slen, py=0, px=-1, dir=1, num=0;
  cin >> size;
  slen = size;

  for (int b=1; b<2*size; ++b)
  {
    //cout << dir << " " << slen << ":" << endl;
    for (int s=0; s<slen; ++s)
    {
      //cout << "  " << dir << " " << py << " " << px << endl;
      switch (dir)
      {
        case 0: -- py;
          break;
        case 1:
          ++ px;
          break;
        case 2:
          ++ py;
          break;
        case 3:
          -- px;
          break;
      }
      matrix[py][px] = ++num;
    }
    dir = (dir + 1) % 4;
    flop = ! flop;
    if (flop) --slen;
  }

  for (int i=0; i<size; ++i)
  {
    for (int j=0; j<size; ++j)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
 1 2 3 4 5
 16 17 18 19 6
 15 24 25 20 7
 14 23 22 21 8
 13 12 11 10 9



 */
