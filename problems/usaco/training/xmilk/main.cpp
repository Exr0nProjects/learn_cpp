/*
ID: spoytie2
TASK: milk
LANG: C++14                 
*/

/*
 * Problem milk (usaco/training/milk)
 * Created Sun 03 Nov 2019 @ 17:03 (PST)
 * Accepted Tue 05 Nov 2019 @ 07:43 (PST)
 * 
 */


#include <iostream>
#include <algorithm>

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
auto fin = fopen("milk.in", "r");
auto fout = fopen("milk.out", "w+");

const int MAXSZ = 50100; // todo
struct Melk
{
  int p, m;
  bool operator< (const Melk &o) const { return p < o.p; }
} melks[MAXSZ];
int n, m;

int main ()
{
  fscanf(fin, "%d%d", &n, &m);
  for (int i=0; i<m; ++i)
  {
    fscanf(fin, "%d%d", &melks[i].p, &melks[i].m);
  }

  printf("finished input\n");

  stable_sort(melks, melks+m);

  for (int i=0; i<m; ++i)
  {
    printf("%3d", melks[i].p);
  }

  int ret = 0;
  for (int c=0; n>0; ++c)
  {
    if (melks[c].m > n) ret += n*melks[c].p; // final
    else ret += melks[c].m * melks[c].p;
    n -= melks[c].m;
  }

  fprintf(fout, "%d\n", ret);

  return 0;
}
