/*
 * Problem #1228
 * n queens problem
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double

using namespace std;

const int MAXSZ = 100;

inline void printarr (const int board[][MAXSZ], const int size, const int rem, string prefix=" ")
{
  return; // remove for debug
  for (int i=0; i<size; ++i)
  {
    cout << prefix;
    for  (int j=0; j<size; ++j)
    {
      printf("%2c", (board[i][j] ? '#' : '.'));
    }
    printf("\n");
  }
  printf("  to place: %d\n", rem);
  puts("");
}

int place (int board[][MAXSZ], const int size, const int queens, const int sy_=0, const int sx_=0) // todo: sx_ is not used
{
//	char _del; scanf("%c",&_del);
//d	printf("  called, seed: (%d, %d)\n", sy_, sx_);
  static int success = 0;
  if (queens == 0) { return ++success; } // found successful solution

  for (int i=sy_; i<size; ++i)
  {
    for (int j=0; j<size; ++j)
    {
      if (!board[i][j]) // placeable
      {
//d      	printf("found placable at (%d, %d), rem: %d, scs %d\n", i, j, queens, success);

        for (int k=0; k<size; ++k)
        {
          board[i][k] ++;
          board[k][j] ++;
          if (i-k>0 && j-k>0) board[i-k][j-k] ++;
          if (i+k<size && j+k<size) board[i+k][j+k] ++;
        }
        for (int k=max(i+j-size+1, 0); k<min(i+j+1, size); ++k) board[i+j-k][k] ++;

        printarr(board, size, queens-1, ": ");

        place(board, size, queens-1, i, j);


        for (int k=0; k<size; ++k)
        {
          board[i][k] --;
          board[k][j] --;
          if (i-k>0 && j-k>0) board[i-k][j-k] --;
          if (i+k<size && j+k<size) board[i+k][j+k] --;
        }
        for (int k=max(i+j-size+1, 0); k<min(i+j+1, size); ++k) board[i+j-k][k] --;
      }
    }
  }
  return success;
}

int main ()
{
  int num;
  scanf("%3d", &num);

  int board[MAXSZ][MAXSZ];
  for (int i=0; i<num; ++i) for (int j=0; j<num; ++j) board[i][j] = false;

  printarr(board, num, num, "");

  printf("%d", place(board, num, num, 0, 0));

  return 0;
}
