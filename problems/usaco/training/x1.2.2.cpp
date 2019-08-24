/*
ID: spoytie2
TASK: ride
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string a, b;
  fin >> a >> b;
  
  int pa=1, pb=1;
  for (int i=0; i<a.length(); ++i) if (a[i] != '\n') pa *= (a[i]-'A'+1); pa %= 47;
  for (int i=0; i<b.length(); ++i) if (b[i] != '\n') pb *= (b[i]-'A'+1); pb %= 47;
  
  if (pa % 47 == pb % 47) fout << "GO\n";
  else fout << "STAY\n";
  return 0;
}
