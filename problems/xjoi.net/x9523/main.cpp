/*
 * Problem #9523
 * 26 July 2019
 * floyd warsall
 */

#include <iostream>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <math.h>
#include <random>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

#define ll long long
#define dl double
#define INF 1000000
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1010; // todo

int matrix[MAXSZ][MAXSZ];

int main ()
{
  int num;
  scanf("%d\n", &num);
  for (int i=0; i<num; ++i)
  {
    string line;
    getline(cin, line);
    for (int j=0; j<=num; ++j)
    {
      matrix[i][j] = line[j] - 48;
      if (line[j] == '0') matrix[i][j] = INF;
      if (i == j) matrix[i][j] = 0;
    }
  }

  for (int k=0; k<num; ++k)
    for (int i=0; i<num; ++i)
      for (int j=0; j<num; ++j)
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];

  for (int i=0; i<num; ++i)
  {
    for (int j=0; j<num; ++j)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }


  return 0;
}
