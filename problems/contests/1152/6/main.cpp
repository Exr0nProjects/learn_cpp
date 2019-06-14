/*
 * Post-array test (sub): Problem #6
 * 14 June 2019
 * line block
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#define PI 3.14159265

using namespace std;


int main ()
{
  int max, pos, rad=-PI, trad, dist=40, fin=0;
  cin >> max, pos;
  int line [5010];
  for (int i=0; i<max; ++i) cin >> line[i];

  for (int i=pos-1; i>=0; --i)
  {
    trad = asin( (line[i]-line[pos]) / (pos-i)*dist );
    if (trad >= rad)
    {
      ++ fin;
      rad = trad;
    }
    else
      break;
  }

  for (int i=pos+1; i<max; ++i)
  {
    trad = asin( (line[i]-line[pos]) / (i-pos)*dist );
    if (trad >= rad)
    {
      ++ fin;
      rad = trad;
    }
    else
      break;
  }

  cout << fin;

  return 0;
}
