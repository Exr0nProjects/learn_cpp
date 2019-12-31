
/*
ID: spoytie2
TASK: moocrypt
LANG: C++14
*/

/*
 * Problem geteven (usaco/bronze/2015open/geteven)
 * Created Tue 31 Dec 2019 @ 11:33 (PST)
 * Accepted [!meta:end!]
 *
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
FILE* fin = fopen("geteven.in", "r");
FILE* fout = nullptr;

const int MAXSZ = 30; // todo
int N;
int letters[MAXSZ][3];


int main ()
{
  if (fin) { fout = fopen("geteven.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d", &N);
  
  for (int i=0; i<N; ++i)
  {
    char c; int d;
    fscanf(fin, "\n%c%d",  &c, &d);
    ++letters[c-'A'][abs(d%2)];
  }
  
  ll ret=0;
  for (int b=0; b<2; ++b)
  for (int e=0; e<2; ++e)
  for (int s=0; s<2; ++s)
  for (int i=0; i<2; ++i)
  for (int g=0; g<2; ++g)
  for (int o=0; o<2; ++o)
  for (int m=0; m<2; ++m)
    if (((b+e+e+s+s+i)*(g+o+e+s)*(m+o+o)) %2 == 0)
      ret += letters['B'-'A'][b]*letters['E'-'A'][e]*letters['S'-'A'][s]*letters['I'-'A'][i]*letters['G'-'A'][g]*letters['O'-'A'][o]*letters['M'-'A'][m];
  
  // printf("%d %d %d, %d %d %d\n", A, B, C, _A, _B, _C);
  // fprintf(fout, "%d\n", A*_B*_C+_A*B*_C+_A*_B*C - A*B*_C - A*_B*C - _A*B*C - A*B*C);

  fprintf(fout, "%lld\n", ret);

  return 0;
}
