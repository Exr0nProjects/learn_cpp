/*
 * Post-array test (sub): Problem #4
 * 14 June 2019
 * doublesort
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


int main ()
{
  int fir [100010];
  int sec [100010];
  int num, tempp, tempn;
  //cout << "soy\n";
  cin >> num;
  cin >> fir[0] >> sec[0];
  //d:for (int tfli=0; tfli<num; ++tfli) cout << "(" << fir[tfli] << ", " << sec[tfli] << ")  "; cout << endl;
  for (int i=1; i<num; ++i)
  {
    cin >> fir[i] >> sec[i];

    tempp = i;
    //d:cout << i << " " << fir[i] << " " << sec[i] << endl;

    while (fir[tempp] < fir[tempp-1])
    {

      tempn = fir[tempp-1];
      fir[tempp-1] = fir[tempp];
      fir[tempp] = tempn;

      tempn = sec[tempp-1];
      sec[tempp-1] = sec[tempp];
      sec[tempp] = tempn;

      -- tempp;
      if (tempp == 0) break;
    }

    while (sec[tempp] < sec[tempp-1] && fir[tempp-1] == fir[tempp])
    {
      tempn = fir[tempp-1];
      fir[tempp-1] = fir[tempp];
      fir[tempp] = tempn;

      tempn = sec[tempp-1];
      sec[tempp-1] = sec[tempp];
      sec[tempp] = tempn;

      -- tempp;
      if (tempp == 0) break;
    }

    //d;for (int i=0; i<num; ++i) cout << "(" << fir[i] << ", " << sec[i] << ")  "; cout << endl << endl;
  }

  for (int i=0; i<num; ++i) cout << fir[i] << " " << sec[i] << endl;

  return 0;
}

/*
4
1 1
2 2
2 1
1 2
 */
