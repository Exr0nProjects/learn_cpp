/*
ID: spoytie2
TASK: gift1
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
  FILE* fin  = fopen("gift1.in",  "r" );
  FILE* fout = fopen("gift1.out", "w+");
  
  if (fin == NULL) return 100;
  if (fout == NULL) return 101;
  
  char tname [20];
  
  int num;
  fscanf(fin, "%d", &num);
  
  for (int i=0; i<num; ++i)
  {
    fscanf(fin, "%s", tname);
    names[i] = tname;
    bal[tname] = 0;
  }
  
  printf("br2\n");
  
  for (int i=0; i<num; ++i)
  {
    string temp;
    fscanf(fin, "%s", tname); temp = tname;
    int sum, div;
    fscanf(fin, "%d%d", &sum, &div);
    
    if (div > 0)
    {
      bal[temp] += sum % div;
      bal[temp] -= sum;
    }
    
    for (int j=0; j<div; ++j)
    {
      fscanf(fin, "%s", tname); temp = tname;
      bal[temp] += sum/div;
    }
    for (int j=0; j<num; ++j)
    {
      printf("%5d", bal[names[j]]);
    }
    printf("\n");
  }
  
  printf("br3\n");
  
  for (int i=0; i<num; ++i)
  {
    fprintf(fout, "%s %d\n", names[i].c_str(), bal[names[i]]);
  }
  return 0;
}
