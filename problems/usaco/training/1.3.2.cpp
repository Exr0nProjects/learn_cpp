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
bool times[MAXSZ];

int main() {
  printf("test\n");
  FILE* fin  = fopen("milk2.in",  "r" );
  FILE* fout = fopen("milk2.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num, maxm=0, maxi=0, maxt=0, mint=-1;
  fscanf(fin, "%d", &num);
  for (int i=0; i<num; ++i)
  {
    int beg, end;
    fscanf(fin, "%d%d", &beg, &end);
    for (int j=beg; j<=end; ++j) times[j] = true;
    maxt = max(maxt, end);
    if (mint == -1) mint = beg;
    else mint = min(beg, mint);
  }
  
  int curm = 0, curi = 0;
  for (int i=mint; i<maxt; ++i)
  {
    if (times[i])
    {
      ++ curm;
      curi = 0;
      maxm = max(curm, maxm);
    }
    else
    {
      ++ curi;
      curm = 0;
      maxi = max(curi, maxi);
    }
  }

  fprintf(fout, "%d %d\n", maxm, maxi);
  
  return 0;
}
