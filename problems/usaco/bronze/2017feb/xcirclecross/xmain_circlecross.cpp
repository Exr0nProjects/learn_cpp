/*
ID: spoytie2
TASK: circlecross
LANG: C++14
*/

/*
 * Problem circlecross (usaco/bronze/2017feb/circlecross)
 * Created Sun 29 Dec 2019 @ 14:11 (PST)
 * Accepted Sun 29 Dec 2019 @ 14:27 (PST)
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
FILE *fin = fopen("circlecross.in", "r");
FILE *_ = stderr;

const int MAXSZ = 30; // todo
bool tracker[MAXSZ];
int start;

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("circlecross.out", "w+"); }
  char s[60];
  scanf("%s", s);

  int ret  =0;
  for (int i='A'; i<='Z'; ++i)
  {
    for (int j=0; j<MAXSZ; ++j) tracker[j] = false;
    start=-1;
    int tmp = 0; // holds number of crossings with this cow

    for (int j=0; j<52; ++j)
    {
      if (s[j] == i)
      {
        if (start >= 0)
        {
          fprintf(_, "  end %c: %2d\n", i, j);
          for (int k=0; k<26; ++k)
            tmp += tracker[k];
        }
        else if (start == -1)
          fprintf(_, "  beg %c: %2d\n", i, j);
          start = j;
      }
      else
      {
        if (start >= 0) tracker[s[j]-'A'] = !tracker[s[j]-'A'];
      }
    }
    ret += tmp;
    fprintf(_, "crossings with %c: %d\n\n", i, tmp);
  }

  if (ret % 2) fprintf(_, "hmMmmmMMMMMMMMMMmmmmmMMMmmmMMmmMMMmmMMmmMMMmmMMMmmMMmm\n");
  printf("%d\n", ret/2);

  return 0;
}
