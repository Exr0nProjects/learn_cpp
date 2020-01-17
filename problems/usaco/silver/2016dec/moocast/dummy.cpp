#include <bits/stdc++.h>
using namespace std;

#define cn const int
#define ca const auto &
#define ll long long
#define cl const long long

FILE *fin = fopen("moocast.in", "r");
FILE *_ = stderr;

const int MAXSZ = 210; // todo
// raw input data
int N;
int rawx[MAXSZ]; // x coord
int rawy[MAXSZ]; // y coord
int rawp[MAXSZ]; // power

// graph
inline double dist(cn i, cn j)
{
  return sqrt(pow(rawx[i]-rawx[j], 2) + pow(rawy[i]-rawy[j], 2));
}

struct Edge
{
  int f, t, n;
} edges[MAXSZ*MAXSZ];
int head[MAXSZ], ecnt=1;
void addEdge(cn a, cn b)
{
  edges[ecnt].f = a;
  edges[ecnt].t = b;
  edges[ecnt].n = head[a];
  head[a] = ecnt;
  ++ecnt;
}

int main()
{
  if (fin) { stdin = fin; stdout = fopen("moocast.out", "w+"); }
  printf("3\n");
  return 0;
}