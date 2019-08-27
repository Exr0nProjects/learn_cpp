/*
ID: spoytie2
TASK: milk2
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 1000010;
int times[MAXSZ];

int main() {
  FILE* fin  = fopen("milk2.in",  "r" );
  FILE* fout = fopen("milk2.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num, maxm=0, maxi=0, maxt=0, mint=-1, curi=0;
  fscanf(fin, "%d", &num);
  for (int i=0; i<num; ++i)
  {
    int beg, end;
    fscanf(fin, "%d%d", &beg, &end);
    for (int j=beg; j<end; ++j)
    {
      if (j == beg) times[j] = max(1, max(times[j], times[max(j-1, 0)]));
      else times[j] = times[beg] + j-beg;
    }

    maxm = max(maxm, times[end-1]);
    if (mint == -1) mint = beg;
    else mint = min(mint, beg);
    maxt = max(maxt, end);
  }

  for (int i=mint; i<maxt; ++i)
  {
    if (times[i] == 0)
    {
      ++curi;
      maxi = max(maxi, curi);
    }
    else
    {
      curi=0;
    }
  }
  
  fprintf(fout, "%d %d\n", maxm, maxi);
  
  return 0;
}
