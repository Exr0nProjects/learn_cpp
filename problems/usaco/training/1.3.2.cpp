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

const int MAXSZ = 20;

bool 

int main() {
  printf("test\n");
  FILE* fin  = fopen("milk2.in",  "r" );
  FILE* fout = fopen("milk2.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num;
  fscanf(fin, "%d", &num);
  for (int i=0; i<num; ++i)
  {
    int beg, end;
    fscanf(fin, "%d%d", &times[i].beg, &times[i].end);
    for (int j=beg; j<end; ++j)
    {
      
    }
  }
  
  return 0;
}
