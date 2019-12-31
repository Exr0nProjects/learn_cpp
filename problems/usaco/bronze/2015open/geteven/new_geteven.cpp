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
vector<int> letters[MAXSZ];


int main ()
{
  if (fin) { fout = fopen("geteven.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d", &N);
  
  for (int i=0; i<N; ++i)
  {
    char c; int d;
    fscanf(fin, "\n%c%d",  &c, &d);
    letters[c-'A'].push_back(d);
  }
  
  int A=0, B=0, C=0, _A=0, _B=0, _C=0;
  for (int b:letters['B'-'A'])  for (int i:letters['I'-'A'])
  { ++_A; if ((b+i)%2  == 0) ++A; }
  for (int g:letters['G'-'A']) for(int o:letters['O'-'A']) for (int e:letters['E'-'A']) for (int s:letters['S'-'A'])
  { ++_B; if ((g+o+e+s)%2 ==  0) ++  B; }
  for (int m:letters['M'-'A'])
  {  ++_C; if  (m%2 == 0) ++C; }
  
  printf("%d %d %d, %d %d %d\n", A, B, C, _A, _B, _C);
 
  fprintf(fout, "%d\n", A*_B*_C+_A*B*_C+_A*_B*C - A*B*_C - A*_B*C - _A*B*C - A*B*C);

  return 0;
}
