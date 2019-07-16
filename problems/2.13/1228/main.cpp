/*
 * Problem #1228
 * n queens problem
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;

const int MAXSZ = 10;

inline void printarr (const bool board[][MAXSZ], const int size, string prefix=" ")
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
  puts("");
}

int place (bool board[][MAXSZ], const int size, int queens)
{
  static int success = 0;
  if (queens == 0) ++success; // found successful solution

  for (int i=0; i<size; ++i) // todo: start at non (0, 0) in future iterations because we don't need to check for filling past gridspaces
  {
    for (int j=0; j<size; ++j)
    {
      if (board[i][j] == 0) // placeable
      {
        bool newbd[MAXSZ][MAXSZ];
        for (int l=0; l<size; ++l) for (int m=0; m<size; ++m) newbd[l][m] = board[l][m];

        for (int k=0; k<size; ++k)
        {
          newbd[i][k] = 1;
          newbd[k][j] = 1;
          try { newbd[i-k][j-k] = 1; } catch (exception& e) {}
          try { newbd[i+k][j+k] = 1; } catch (exception& e) {}
        }
        for (int k=0; k<=i+j; ++k) try { newbd[i+j-k][k] = 1; } catch (exception& e) {}
        
        printarr(newbd, size, to_string(queens-1) + ": ");

        place(newbd, size, queens-1);
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

  printarr(board, num, "");

  printf("%d", place(board, num, num));

  return 0;
}
