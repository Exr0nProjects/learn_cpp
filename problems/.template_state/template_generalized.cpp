/*
todo: use preprocesser to change all scanf and printf to fscanf and fprintf if usacon_name is defined and also do all the file handling automatically
*/

/*
ID: spoytie2
TASK: gift1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#define meta_usaco_name gift1
#ifdef meta_usaco_name
#define scanf(s,a) fscanf(meta_usaco_name+)


using namespace std;

const int MAXSZ = 11;
string beg[MAXSZ];
string end[MAXSZ];

int main() {
#ifdef meta_usaco_name
  FILE* fin  = fopen("meta_usaco_name.in",  "r" );
  FILE* fout = fopen("meta_usaco_name.out", "w+");
#endif
  int num;
  fscanf(fin, )
  
  int pa=1, pb=1;
  for (int i=0; i<a.length(); ++i) if (a[i] != '\n') pa *= (a[i]-'A'+1); pa %= 47;
  for (int i=0; i<b.length(); ++i) if (b[i] != '\n') pb *= (b[i]-'A'+1); pb %= 47;
  
  if (pa % 47 == pb % 47) fout << "GO\n";
  else fout << "STAY\n";
  return 0;
}
