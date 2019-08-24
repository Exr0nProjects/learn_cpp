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

const int days[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayct[7] = { };

int main() {
  FILE* fin  = fopen("friday.in",  "r" );
  FILE* fout = fopen("friday.out", "w+");

  if (fin == NULL) return 100;
  if (fout == NULL) return 101;

  int num;
  fscanf(fin, "%d", &num);

  int dpt = 0, dct = 0, year=1900;
  for (int i=0; i<12*num; ++i)
  { // each month
    ++ dayct[(dct+12)%7];
    if (dpt == 1)
    {
      if ((!year%4 && year%100) || !year%400) { dct += 29; printf("+29 "); }
      else { dct += 28; printf("+28 "); }
    }
    dct += days[dpt];
    if (days[dpt] > 0) printf("+%d ", days[dpt]);
    ++dpt;
    if (dpt == 12) { dpt = 0; ++ year; }
    printf("year %d: %d", year, )
  }

  for (int i=5; i<12; ++i)
  {
    fprintf(fout, "%d", dayct[i%7]);
    if (i != 11) fprintf(fout, " ");
  }
  fprintf(fout, "\n");

  return 0;
}
