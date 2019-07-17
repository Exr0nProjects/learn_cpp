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

inline void printarr (const bool board[][MAXSZ], const int size, const int rem, string prefix=" ")
{
  //return; // remove for debug
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

int place (bool board[][MAXSZ], const int size, const int queens, const int sy_=0, const int sx_=0)
{
	char _del; scanf("%c",&_del);
	printf("  called, seed: (%d, %d)\n", sy_, sx_);
  static int success = 0;
  if (queens == 0) { return ++success; printf("\n\n\n\n\nsuccess\n\n\n\n\n"); } // found successful solution

  for (int i=sy_; i<size; ++i)
  {
    for (int j=sx_; j<size; ++j)
    {
      if (board[i][j] == 0) // placeable
      {
      	printf("found placable at (%d, %d), rem: %d, scs %d\n", i, j, queens, success);
        bool newbd[MAXSZ][MAXSZ];
        for (int l=0; l<size; ++l) for (int m=0; m<size; ++m) newbd[l][m] = board[l][m];

        for (int k=0; k<size; ++k)
        {
          newbd[i][k] = 1;
          newbd[k][j] = 1;
          if (i-k>0 && j-k>0) newbd[i-k][j-k] = 1;
          if (i+k<size && j+k<size) newbd[i+k][j+k] = 1;
        }
        for (int k=max(i+j-size+1, 0); k<min(i+j+1, size); ++k) newbd[i+j-k][k] = 1; 
        
        printarr(newbd, size, queens-1, ": ");

        place(newbd, size, queens-1, i, j);
      }
    }
  }
  return success;
}

int main ()
{
  int num;
  scanf("%3d", &num);

  bool board[MAXSZ][MAXSZ];
  for (int i=0; i<num; ++i) for (int j=0; j<num; ++j) board[i][j] = false;

  printarr(board, num, num, "");

  printf("%d", place(board, num, num, 0, 0));

  return 0;
}
