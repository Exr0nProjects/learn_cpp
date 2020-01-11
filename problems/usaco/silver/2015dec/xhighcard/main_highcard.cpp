/*
ID: spoytie2
TASK: highcard
LANG: C++14
*/

/*
 * Problem highcard (usaco/silver/2015dec/highcard)
 * Create time: Fri 10 Jan 2020 @ 16:37 (PST)
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
FILE *fin = fopen("highcard.in", "r");
FILE *_ = stderr;

const int MAXSZ = 500010; // todo
int N;
int bessie_cards[MAXSZ];
int elsie_cards[MAXSZ];


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("highcard.out", "w+"); }
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
  {
    scanf("%d", &elsie_cards[i]);
  }

  sort(elsie_cards, elsie_cards+N);

  int ptr=N-1, cnt=0;
  for (int i=N*2; i>0; --i)
  {
    if (elsie_cards[ptr] == i)
    {
      --ptr; // FIX: forgot to also decrement pointer
      if (cnt > 0)
        --cnt;
    }
    else
      ++cnt;
  }

  printf("%d\n", N-cnt);

  return 0;
}

/*
5
1 3 5 8 9
=> 4

4
1 2 3 4
=> 4
*/