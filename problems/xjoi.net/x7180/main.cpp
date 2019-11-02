// #7180 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 2010;
int matrix[maxsize][maxsize];

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

  // init top row and left column
  for (int i = 1; i < size; ++i)
  {
    matrix[0][i] += matrix[0][i - 1];
    matrix[i][0] += matrix[i - 1][0];
  }

  // dp
  for (int i = 1; i < size; ++i)
  {
    for (int j = 1; j < size; ++j)
    {
      matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1]);
    }
  }

  cout << matrix[size - 1][size - 1];

  return 0;
}
