/*
ID: spoytie2
TASK: mowing
LANG: C++14
*/

/*
 * Problem mowing (usaco/bronze/2016jan/mowing)
 * Created Sat 28 Dec 2019 @ 09:44 (PST)
 * Accepted [!meta:end!]
 * This problem was not "purified" because it uses the same approach as the given usaco soln
 ! The one error that caused this code to not work first time was forgetting to add the logic at line 118 <CodeMark-FB19B95A14B68930F9D0E03C8874F5DF11CC6E9D>
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
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
FILE *fin = fopen("mowing.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 2100; // todo
// i thought these arrays might be too big but apparently its okay?
int previ[MAXSZ][MAXSZ];
int N, x = 1050, y = 1050, t = 1, ret = 1100;

void debug()
{
  printf("time: %d, pos: (%d, %d), -> %d\n    ", t, x, y, ret);
  for (int j = 1025; j < 1075; ++j)
    printf("%4d", j - 1050);
  printf("\n");
  for (int i = 1025; i < 1075; ++i)
  {
    printf("%3d:", i - 1050);
    for (int j = 1025; j < 1075; ++j)
    {
      if (previ[i][j] == 0)
        printf("   .");
      else
        printf("%4d", previ[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  if (fin)
  {
    fout = fopen("mowing.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d\n", &N);
  for (int i = 0; i < N; ++i)
  {
    char d;
    int s;
    // get values
    fscanf(fin, "%c%d\n", &d, &s);
    printf("  movement: %c %d\n", d, s);

    // simulate
    for (int j = 0; j < s; ++j)
    {
      // move
      if (d == 'N')
        --y;
      else if (d == 'E')
        ++x;
      else if (d == 'S')
        ++y;
      else if (d == 'W')
        --x;
      // do math
      if (previ[y][x] != 0) // been here before
      {
        printf("\n\n\n  dejavu! (%d, %d)\n\n\n", x - 1050, y - 1050);
        ret = min(ret, t - previ[y][x]);
      }
      // update
      previ[y][x] = t;
      ++t;
    }
    debug();
  }

  if (ret > 1000) ret = -1; // forgot to add edge case<CodeMark-FB19B95A14B68930F9D0E03C8874F5DF11CC6E9D>
  fprintf(fout, "%d\n", ret);

  return 0;
}
