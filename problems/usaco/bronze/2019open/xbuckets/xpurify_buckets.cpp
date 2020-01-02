/*
ID: spoytie2
TASK: buckets
LANG: C++14
*/

/*
 * Problem buckets (usaco/bronze/2019open/buckets)
 * Created Thu 02 Jan 2020 @ 10:12 (PST)
 * Accepted [!meta:end!]
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
FILE *fin = fopen("buckets.in", "r");
FILE *_ = stderr;

const int MAXSZ = 10; // todo
pair<int, int> barn, lake, rock;

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("buckets.out", "w+");
  }

  for (int i = 0; i < MAXSZ; ++i)
  {
    for (int j = 0; j < MAXSZ; ++j)
    {
      char c;
      scanf("%c", &c);
      if (c == 'B')
        barn = make_pair(i, j);
      if (c == 'R')
        rock = make_pair(i, j);
      if (c == 'L')
        lake = make_pair(i, j);
    }
    if (i < MAXSZ - 1)
      scanf("\n");
  }

  fprintf(_, "barn: %d, %d\nlake: %d, %d\nrock: %d, %d\n", barn.first, barn.second, lake.first, lake.second, rock.first, rock.second);

  int dist = abs(barn.first - lake.first) + abs(barn.second - lake.second);

  if ((barn.first == rock.first && lake.first == rock.first && min(barn.second, lake.second) < rock.second && rock.second < max(barn.second, lake.second)) || (barn.second == rock.second && lake.second == rock.second && min(barn.first, lake.first) < rock.first && rock.first < max(barn.first, lake.first)))
    dist += 2;

  printf("%d\n", dist - 1);

  return 0;
}
