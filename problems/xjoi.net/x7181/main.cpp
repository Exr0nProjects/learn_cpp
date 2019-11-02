// #7181 by XC1900105AH on 10 July 2019
// apple picking with two runs

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 70;

int matrix[maxsize][maxsize];
int dp[2 * maxsize][maxsize][maxsize];
//      tot_steps  y_val_1  y_val_2

int main()
{
  int size;
  cin >> size;

  int tx, ty, tv;
  cin >> ty >> tx >> tv;
  while (!(tx == ty && ty == tv && tv == 0))
  {
    matrix[ty - 1][tx - 1] = tv;
    cin >> ty >> tx >> tv;
  }

  /*/ init top row and left column
    dp[0][0][0] = matrix[0][0];
    for (int i=1; i<size; ++i)
    {
        dp[i][i][i] = dp[i-1][i-1][i-1] + matrix[0][i];
        dp[i][0][0] = dp[i-1][0][0] + matrix[i][0];
    }
    /**/

  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = matrix[0][0];
  for (int i = 1; i < 2 * size - 1; ++i)
  {
    for (int j = max(0, i - size); j <= i && j < size; ++j)
    {
      for (int k = max(0, i - size); k <= i && k < size; ++k)
      {
        int temp = dp[i - 1][j][k];
        if (j > 0)
          temp = max(temp, dp[i - 1][j - 1][k]);
        if (k > 0)
          temp = max(temp, dp[i - 1][j][k - 1]);
        if (j > 0 && k > 0)
          temp = max(temp, dp[i - 1][j - 1][k - 1]);

        temp += matrix[i - j][j];
        if (j != k)
          temp += matrix[i - k][k];

        dp[i][j][k] = temp;
      }
    }
  }

  cout << dp[size * 2 - 2][size - 1][size - 1];

  //debug cout << endl; for (int i=0; i<size; ++i) { for (int j=0; j<size; ++j) cout << matrix[i][j] << " "; cout << endl; }
  //debug for (int i=0; i<size*2-1; ++i) { cout << i; for (int j=0; j<size; ++j) for (int k=0; k<size; ++k) cout << "  (" << j << "|" << k << ": " << dp[i][j][k] << ")"; cout << endl; }

  return 0;
}

/*
 
int main ()
{
    int size;
    cin >> size;
     
    int tx, ty, tv;
    cin >> ty >> tx >> tv;
    while (! (tx == ty && ty == tv && tv == 0))
    {
        matrix[ty][tx][ty][tx] = tv;
        cin >> ty >> tx >> tv;
    }
     
    // init top row and left column
    for (int i=1; i<size; ++i)
    {
        matrix[0][i][0][i] += matrix[0][i-1][0][i-1];
        matrix[i][0][i][0] += matrix[i-1][0][i-1][0];
    }
     
    for (int i=1; i<size; ++i)
    {
        for (int j=1; j<size; ++j)
        {
            for (int k=1; k<size; ++k)
            {
                int l = i + j - k; // ensure that both "runs" have the same numberof steps
                 
                if (!(i == k && j == l)) matrix[i][j][k][l] *= 2;
                 
                matrix[i][j][k][l] += (max( matrix[i-1][j][k-1][l],
                                            matrix[i-1][j][k][l-1],
                                            matrix[i][j-1][k-1][l],
                                            matrix[i][j-1][k][l-1]))
            }
        }
    }
     
    cout << matrix[size-1][size-1][size-1][size-1];
     
    return 0;
}
*/
