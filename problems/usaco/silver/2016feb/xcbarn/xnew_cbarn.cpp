/*
ID: spoytie2
TASK: cbarn
LANG: C++14
*/

/*
 * Problem cbarn (usaco/silver/2016feb/cbarn)
 * Create time: Wed 15 Jan 2020 @ 19:55 (PST)
 * Accept time: [!meta:end!]
 *
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
FILE *fin = fopen("cbarn.in", "r");
FILE *_ = stderr;

const int MAXSZ = 1010; // todo
int N;
int rooms[MAXSZ];

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cbarn.out", "w+"); }
  scanf("%d", &N);
  int moving_cows = 0;
  for (int i=0; i<N; ++i)
  {
    scanf("%d", &rooms[i]);
    moving_cows = max(0, moving_cows+rooms[i]-1); // number of extra cows that we pick up from this room minus the one that we drop off.
  }

  for (int i=0; i<N; ++i) // basically we loop through the entire barn twice because that will gaurentee that we check every position for whether it is a suitable ending one (aka leads to there being zero moving cows)
  {                       //   then we start at the next position, with rotate();
    if (moving_cows == 0) // at this point we used up all the cows
    {
      rotate(rooms, rooms+i, rooms+N); // rotate so that we start the final count just after the end, which should be the start
      break;
    }
    moving_cows = max(0, moving_cows+rooms[i]-1); // max with zero to avoid going into the negatives (if there are many empty rooms in a row)
  }
  
  for (int i=0; i<N; ++i) fprintf(_, "%3d", rooms[i]); fprintf(_, "\n");

  ll ret = 0;
  queue<int> q; // the moving cows 
  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<rooms[i]; ++j) // make all of the cows in this room start walking around the barn
    {
      q.push(i); // store the room that this cow came from
    }
    // take the first cow and have her stay there (she's the one that's been walking the longest)
    ret += (int) pow(q.front()-i, 2);
    q.pop(); // first cow stays in this room so its not moving anymore
  }

  printf("%d\n", ret);

  return 0;
}

/*
 3
 1
 1
 1
 => 0
 
 3
 1
 2
 0
 => 1
 */
