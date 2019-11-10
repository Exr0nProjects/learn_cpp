/*
ID: spoytie2
TASK: combo
LANG: C++14
*/

/*
 * Problem combo (usaco/training/combo)
 * Created Sun 10 Nov 2019 @ 10:18 (PST)
 * Accepted Sun 10 Nov 2019 @ 11:06 (PST)
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
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
auto fin = fopen("combo.in", "r");
auto fout = fopen("combo.out", "w+");

const int MAXSZ = 1; // todo
int n;
vector<int> a(3), b(3);
set<vector<int>> legit;

void generate(vector<int> s) // old: this generates combos where atmost one rotor is within 2 of correct
{
  int mod[] = {2, 1, -1, -2};
  
  legit.insert(s);
  for (int i=0; i<3; ++i)
  {
    for (int j : mod)
    {
      int t = s[i];
      s[i] = (s[i] + j) % n;
      legit.insert(s);
      s[i] = t;
    }
  }
  
//  for (int i : mod)
//  {
//    printf("%d + %d = %d\n", s, i, (s+i)%n);
//    legit.insert((s+i)%n);
//  }
}

void generate(vector<int> s, cn i) // actual function used
{
  if (i == s.size())
  {
    printf("  inserting:"); for (int k : s) printf("%3d", k); printf("\n");
    legit.insert(s);
    return;
  }
  int mod[5] = {2, 1, 0, -1, -2}; // issue: i was missing a comma so the init values read {2, 1, 0, -1 -2} = {2, 1, 0, -3}
  
  for (int m : mod)
  {
    printf("m: %d\n", m);
    int t = s[i];
    s[i] = (s[i] + m + n) % n;
    generate(s, i+1);
    s[i] = t;
  }
}

int main ()
{
  fscanf(fin, "%d", &n);
  for (int i=0; i<3; ++i) { fscanf(fin, "%d", &a[i]); a[i] %= n; }
  for (int i=0; i<3; ++i) { fscanf(fin, "%d", &b[i]); a[i] %= n; }
  
  printf("%d:\n", n);
  for (auto i : a) printf("%3d", i); printf("\n");
  for (auto i : b) printf("%3d", i); printf("\n");

  generate(a, 0); // add all near to a
  generate(b, 0); // add all near to b
  
  for (const vector<int> &v : legit)
  {
    for (int i : v)
    {
      printf("%2d,", i);
    }
    printf("\n");
  }
  
  fprintf(fout, "%d\n", legit.size());

  return 0;
}

/*
50
1 2 3
5 6 7
 */
