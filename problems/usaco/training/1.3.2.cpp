/*
ID: spoytie2
TASK: milk2
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 5010;
struct Time
{
  int b, e;
  bool operator< (const Time& o) const { return b < o.b; }
} times[MAXSZ];

int main() {
  FILE* fin  = fopen("milk2.in",  "r" );
  FILE* fout = fopen("milk2.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num, maxt=0, mint=-1;
  fscanf(fin, "%d", &num);
  for (int i=0; i<num; ++i)
  {
    int beg, end;
    fscanf(fin, "%d%d", &beg, &end);
    times[i].b = beg;
    times[i].e = end;
    maxt = max(maxt, end);
    if (mint == -1) mint = beg;
    else mint = min(beg, mint);
  }

  sort(times, times+num);
  
  int cmx=times[0].e-times[0].b, gmx=cmx, gmn=-1, pend=times[0].e;
  for (int i=1; i<num; ++i)
  {
    if (times[i].b <= pend)
    {
      cmx += times[i].e-pend;
      gmx = max(cmx, gmx);
      pend = max(pend, times[i].e);
    }
    else
    {
      if (gmn == -1) gmn = times[i].b - pend;
      else gmn = min(gmn, times[i].b - pend);
      pend = times[i].e;
    }
  }

  gmn = max(gmn, 0);

  fprintf(fout, "%d %d\n", gmx, gmn);
  
  return 0;
}
