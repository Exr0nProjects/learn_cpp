/*
 * Problem #1228
 * n queens problem (bitwise)
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double

using namespace std;

inline bool val (const unsigned ll board, const int y, const int x) { return (board >> (8*y+x)) & 1; }

void printarr (const unsigned ll board, const int size)
{
  //return; // remove for debug
  for (int i=0; i<size; ++i)
  {
    for  (int j=0; j<size; ++j)
    {
      printf("%2c", (val(board, i,j) ? '#' : '.'));
    }
    printf("\n");
  }
  puts("");
}

inline unsigned long long place (unsigned ll board, unsigned ll pos) 
{
	unsigned ll lp = log2(pos);
	board |= 255 << ((lp >> 3) << 4); // horizontal
	board |= 72340172838076673 << (lp % 8); // vertical
	for (int i=7; i<8; ++i) // todo: change int i=7 to int i=1
	{
//		board |= pos << i << 1;
//		board |= pos << i >> 1;
//		board |= pos >> i << 1;
//		board |= pos >> i >> 1;
		printf("\n\n");
		cout << board << endl;
		printarr(board, 8);
	}
}

inline int backtrack (unsigned ll board, const int siz, const short rem, unsigned ll pos=1) // can we get away with this being inline?
{
    static short total = 0; // can store an answer for an 8x8 board
    if (!rem) return ++total; // todo: this may be too slow...
    for (; pos; pos <<= 1) // for each spot
    {
        if (!(board & pos)) // can place
        {
            
            printarr(board, siz);
        }
        char _t; scanf("%c", &_t);
    }
    return total;
}

int main ()
{
  short num;
  scanf("%d", &num);

  printarr(0, num);
  
  for (unsigned long long i = 1 << 20; i; i <<= 1) { printf("\n\n%d\n", (int) log2(i)); printarr(i, num); place(0, i); }

  //printf("%d", backtrack(0, num, num));

  return 0;
}
