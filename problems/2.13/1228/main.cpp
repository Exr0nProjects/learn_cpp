/*
 * Problem #1228
 * n queens problem
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;

const int MAXSZ = 10;

inline void printarr (const bool board[][MAXSZ], const int size)
{
  for (int i=0; i<size; ++i)
  {
    for  (int j=0; j<size; ++j)
    {
      printf("%4d", board[i][j]);
    }
    printf("\n");
  }
  puts("");
}

int place (bool board[][MAXSZ], const int size, int queens)
{
  static int success = 0;
  if (queens == 0) ++success; // found successful solution

  for (int i=0; i<size; ++i)
  {
    for (int j=0; j<size; ++j)
    {
      if (board[i][j] == 0)
      {
        -- queens;

        for (int k=0; k<size; ++k)
        {
          board[i][k] = 1;
          board[k][j] = 1;
          if (i-k >= 0 && j-k >= 0) board[i-k][j-k] =1;
          if (i+k < size && j+k < size) board[i-k][j-k] =1;
          if (i-k >= 0 && j+k < size) board[i-k][j+k] =1;
          if (i+k < size && j-k >= 0) board[i+k][j-k] =1;
        }
        printarr(board, size);

        place(board, size, queens);
      }
    }
  }
  return success;
}

int main ()
{
  int num;
  scanf("%d", &num);

  bool board[MAXSZ][MAXSZ];
  for (int i=0; i<num; ++i) for (int j=0; j<num; ++j) board[i][j] = 0;

  printarr(board, num);

  printf("%d", place(board, num, num));

  return 0;
}
