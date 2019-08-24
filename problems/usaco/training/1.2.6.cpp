/*
ID: spoytie2
TASK: friday
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const string NAME = "gift1";

const int MAXSZ = 20;
string names[MAXSZ];
unordered_map<string, int> bal;

int main() {
  FILE* fin  = fopen("friday.in",  "r" );
  FILE* fout = fopen("friday.out", "w+");
  
  if (fin == NULL) return 100;
  if (fout == NULL) return 101;
  
  int num;
  fscanf(fin, "%d", &num);
  
  int days[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int count[7] = { };
  
  int dpt = 0, dct = 0, year=1900;
  for (int i=0; i<12*num; ++i) 
  { // each month
    ++ count[(dct+12)%7];
    if (dpt == 2)
    {
      if ((!year%4 && year%100) || !year%400) dpt += 29;
      else dpt += 28;
    }
    dct += days[dpt];
    ++dpt;
    if (dpt == 12) { dpt = 0; ++ year; }
  }
  
  for (int i=5; i<12; ++i)
  {
    fprintf(fout, "%d", count[i%7] +1);
    if (i != 11) fprintf(fout, " ");
  }
  fprintf(fout, "\n");
  
  return 0;
}
