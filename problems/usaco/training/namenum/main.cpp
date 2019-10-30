/*
ID: spoytie2
TASK: namenum
LANG: C++14
*/

/*
 * Problem [!meta:pid!] (usaco/training/namenum)
 * Created Sun 27 Oct 2019 @ 17:28 (PDT)
 * Accepted [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE *fin = fopen("namenum.in", "r");
FILE *dict = fopen("dict.txt", "r");
FILE *fout = fopen("namenum.out", "w+");

const int MAXSZ = -1; // todo
char names[5000][20];

string numpad[10][3] = { {}, {},
  {"A", "B", "C"}, // 2
  {"D", "E", "F"}, // 3
  {"G", "H", "I"}, // 4
  {"J", "K", "L"}, // 5
  {"M", "N", "O"}, // 6
  {"P", "R", "S"}, // 7
  {"T", "U", "V"}, // 8
  {"W", "X", "Y"}  // 9
};

bool find(const string &name)
{

}

void dfs(const string num, string name = "")
{
  if (num.length() == 0 && find(name))
  {
    fprintf(fout, "%s\n", name.c_str());
  }
  for (int i=0; i<2; ++i)
  {
    dfs(num.substr(1), name + numpad[num[0]-'0'][i]);
  }
} 

int main()
{
  string s = "pls AC";
  printf("%s", s.c_str());
  char c[20];
  for (int i=0; i<5000; ++i)
  {
    if (incount > 5000) break; else ++incount;
    fscanf(dict, "%s", c);
    s = c;
    names.insert(s);
  }

  printf("finished inserting dict names\n");

  string n;
  fscanf(fin, "%s", c);
  s = c;

  printf("starting dfs\n");

  dfs(s);

  return 0;
}
