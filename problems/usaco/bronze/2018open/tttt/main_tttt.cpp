/*
ID: spoytie2
TASK: tttt
LANG: C++14
*/

/*
 * Problem tttt (usaco/bronze/2018open/tttt)
 * Created Tue 31 Dec 2019 @ 15:14 (PST)
 * Accepted Sun 05 Jan 2020 @ 18:37 (PST)
 * FIX: both players in each pair must appear in the winning combo.
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#define cn const int
#define ca const auto &
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE *fin = fopen("tttt.in", "r");
FILE *_ = stderr;

const int MAXSZ = 5; // todo
char board[MAXSZ][MAXSZ];
set<char> players;

bool canWin(char a, char b)
{
  bool ret = false;
  for (int i=0; i<3; ++i)
  {
    // in arr, true = bad (screwed up, not a win)
    bool ah, av, bh, bv;
    ah = av = bh = bv = false;
    bool v=true, h=true;
    for (int j=0; j<3; ++j)
    {
      char c = board[i][j];
      char d = board[j][i];
      if (!(c==a||c==b)) h=false;
      if (!(d==a||d==b)) v=false;
      
      // scuffed player tracking
      // FIX: originally had it so that if one player could win on their own then it would get paired with every other and carry that other player, resulting in way too many pairs
      // Thus, we simply make sure that both players have contributed per win.
      ah |= c == a;
      av |= d == a;
      bh |= c == b;
      bv |= d == b;
      
//      if (a == 'A' && b == 'B')
//      {
//        printf("(%d, %d) c=%c, d=%c, h=%d, v=%d\n", i, j, c, d, h, v);
//        printf("ah: %d, av: %d, bh: %d, bv: %d\n\n", ah, av, bh, bv);
//      }
    }
    
    ret |= ((h&&ah&&bh) || (v&&av&&bv)); // direction good and both used
    
    
    
//    bool h=true, v=true;
//    bool _a = false, _b = false;
//    for (int j=0; j<3; ++j)
//    {
//      char c = board[i][j];
//      char d = board[j][i];
//      if (!(c==a||c==b)) h=false;
//      if (!(d==a||d==b)) v=false;
//
//      if (c==a || d==a) _a = true;
//      if (c==b || d==b) _b = true; // used a and b
//    }
//    ret |= (h || v)*(_a && _b);
  }

  // center
  if (board[1][1] == a || board[1][1] == b)
  {
    ret |= (board[0][0] == a || board[0][0] == b) && (board[2][2] == a || board[2][2] == b);
    ret |= (board[0][2] == a || board[0][2] == b) && (board[2][0] == a || board[2][0] == b);
  }
  return ret;
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("tttt.out", "w+"); }
  
  for (int i=0; i<3; ++i)
  {
    scanf("\n");
    for (int j=0; j<3; ++j)
    {
      scanf("%c", &board[i][j]);
      players.insert(board[i][j]);
      }
  }
  
  // fprintf(_, "%d\n", canWin('A', 'A'));
  // return 0;

  for (int i=0; i<3; ++i)
  {
    for (int j=0; j<3; ++j)
    {
      fprintf(_, "%c", board[i][j]);
    }
    fprintf(_, "\n");
  }
  
  int ret=0;
  for (char c:players)
    ret += canWin(c, c);
  printf("%d\n", ret);
  
  ret = 0;
  for (char c:players)
    for (char d:players)
    {
      if (c < d) ret += canWin(c, d);
    }
    
  printf("%d\n", ret);

  return 0;
}


