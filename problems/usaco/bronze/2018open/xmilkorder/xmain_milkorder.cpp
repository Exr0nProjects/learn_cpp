/*
ID: spoytie2
TASK: family
LANG: C++14
*/

/*
 * Problem family (usaco/bronze/2018open/family)
 * Create date Mon 06 Jan 2020 @ 18:32 (PST)
 * Accept date Tue 07 Jan 2020 @ 20:32 (PST)
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
FILE *fin = fopen("milkorder.in", "r");
FILE *_ = stderr;

const int MAXSZ = 110; // todo
int N, m, k;
bool used_cow[MAXSZ];
bool used_pos[MAXSZ];

int pos_fixed[MAXSZ]; // pos_fixed[i] = the position of cow i if it is fixed
int hierarchy[MAXSZ];

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("milkorder.out", "w+");
  }

  scanf("%d%d%d", &N, &m, &k);

  bool cow_in_hier = false;
  for (int i=1; i<=m; ++i)
  {
    scanf("%d", &hierarchy[i]);
    if (hierarchy[i] == 1)
      cow_in_hier = true;
  }
  for (int i=1; i<=k; ++i)
  {
    int c, p;
    scanf("%d%d", &c, &p);
    used_cow[c] = used_pos[p] = true;
    pos_fixed[c] = p;
  }

  if (pos_fixed[1])
  {
    // already fixed position, no change possible
    printf("%d\n", pos_fixed[1]);
    return 0;
  }
  
  fprintf(_, "fixed:\n");
  for (int i=1; i<=N; ++i)
    fprintf(_, "%d ", pos_fixed[i]);
  fprintf(_, "\n");
  
//  fprintf(_, "position fixed\n");
//  for (int i=1; i<=k; ++i) printf("%3d", i);
//  for (int i=1; i<=k; ++i) printf("");

  if (cow_in_hier)
  {
    int next_placement = 1;
    for (int i=1; i<=m; ++i)
    {
      if (pos_fixed[hierarchy[i]]) next_placement = pos_fixed[hierarchy[i]];
      else
      {
        for (; used_pos[next_placement]; ++next_placement); // go forwards until we find a free spot
        used_cow[hierarchy[i]] = used_pos[next_placement] = true;
        if (hierarchy[i] == 1)
        {
          printf("%d\n", next_placement);
          return 0;
        }
      }
    }
  }
  else // sick cow not in hierarchy, therefore we should try to stuff hierarchy cows as far back as possible
  {
    int next_placement = MAXSZ-10;
    for (int i=m; i>0; --i)
    {
      if (pos_fixed[hierarchy[i]])
        next_placement = pos_fixed[hierarchy[i]];
      else
      {
        fprintf(_, "pos %d used? %d\n", next_placement, used_pos[next_placement]);
        for (; used_pos[next_placement]; --next_placement); // keep checking towards front until its an unoccupied position
        fprintf(_, "hierarchy[i] = %d, next_p = %d\n", hierarchy[i], next_placement);
        used_cow[hierarchy[i]] = used_pos[next_placement] = true;
      }
    }
    for (int i=1; i<MAXSZ; ++i)
    {
      if (!used_pos[i])
      {
        printf("%d\n", i);
        return 0;
      }
    }
  }

  return 0;
}
