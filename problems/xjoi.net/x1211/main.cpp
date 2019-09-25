/*
 * Problem #1211
 * minesweeper
 */

#include <iostream>
#include <string>
#include <math.h>


using namespace std;

int countAround (int ** field, int height, int width, int mw, int mh)
{
  int score = 0;
  for (int x=-1; x<=1; ++x)
  {
    for (int y=-1; y<=1; ++y)
    {
      if (height+y < 0 || width+x < 0 || height+y == mh || width+x == mw) continue;
      else if (field[height+y][width+x] == -1) ++ score;
    }
  }
  return score;
}

int main ()
{
  //string tempa; getline(cin, tempa); cout << (tempa[0] == 'a');

  int width, height;
  cin >> height >> width;

  int **field = new int * [height];
  for (int i=0; i<height; ++i) field[i] = new int[width];

  string temp; getline(cin, temp);
  //cout << "inited stuff \n\n";
  for (int i=0; i<height; ++i)
  {
    getline(cin, temp);
    //cout << temp << "\n-";
    for (int j=0; j<width; ++j)
    {
      //cout << j << " " << temp[j];
      switch (temp[j])
      {
        case ('?') :
          //cout << " ?" << endl;
          field[i][j] = 0;
          break;
        case ('*') :
          //cout << " *" << endl;
          field[i][j] = -1;
          break;
        default: return 16; // something went wrong
      }
    }
  }

/*
  char **end = new char * [height];
  for (int i=0; i<height; ++i) end[i] = new char [width];
*/
  for (int i=0; i<height; ++i)
  {
    for (int j=0; j<width; ++j)
    {
      /*
      if (field[i][j] == 1) cout << '*';
      else end[i][j] = '0' + countAround(field, i, j);
      */

      if (field[i][j] == -1) cout << "*";
      else cout << countAround(field, i, j, width, height);
    }
    if (i != height-1) cout << endl;
  }

  return 0;
}
