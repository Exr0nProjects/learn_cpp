/*
ID: spoytie2
TASK: beads
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const string NAME = "gift1";

const int MAXSZ = 20;
char necklace[360];
int maxln[360];

const int days[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayct[7] = { };

inline bool canAdd (char& base, const char add)
{
  if (base == 'w' || add == 'w')
  {
    if (base == 'w') base = add;
    return true;
  }
  else
    return base == add;
}

int main() {
  printf("test\n");
  FILE* fin  = fopen("beads.in",  "r" );
  FILE* fout = fopen("beads.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num;
  fscanf(fin, "%d", &num);
  fscanf(fin, "%s", &necklace);
  
  int gmax = 0, midx = 0;
  for (int i=0; i<num; ++i)
  {
    int cb = 0, ca = 0;
    char bc=necklace[(i-1+num)%num], ac=necklace[i%num];
    
    printf("%d: %c|%c, %d, %d  =>  ", i, bc, ac, cb, ca);
    
    int pt=(i-1+num)%num, ppt;
    for (; pt != i; pt=(pt-1+num)%num)
    {
      if (canAdd(bc, necklace[pt])) ++cb; else break;
    }
    ppt = pt;
    for (pt=i; pt != (i-1+num)%num && pt != (ppt+1+num)%num; pt=(pt+num+1)%num)
    {
      if (canAdd(ac, necklace[pt])) ++ca; else break;
    }
    
    printf("%d: %c|%c, %d, %d\n", i, bc, ac, cb, ca);
    
    if (cb + ca > gmax)
    {
      gmax = cb + ca;
      midx = i;
    }
    // return 404;
  }
  
  printf("%d", midx);
  fprintf(fout, "%d\n", gmax);
  
  return 0;
}
