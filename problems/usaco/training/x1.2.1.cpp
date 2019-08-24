/*
ID: spoytie2
TASK: test
LANG: C++14                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("test.out");
  ifstream fin ("test.in");
  int a, b;
  fin >> a >> b;
  fout << a+b << endl;
  return 0;
}
