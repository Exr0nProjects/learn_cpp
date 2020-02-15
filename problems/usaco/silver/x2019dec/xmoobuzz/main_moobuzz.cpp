/*
ID: spoytie2
TASK: moobuzz
LANG: C++14
*/

/*
 * Problem moobuzz (usaco/silver/2019dec/moobuzz)
 * Created Sun 15 Dec 2019 @ 13:21 (PST)
 * Accepted Sun 15 Dec 2019 @ 13:30 (PST)
 * 
 */

#include <bits/stdc++.h>

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
#define ll long long
#define cl const long long
#define UN unsigned
#define ST static
#define CN const
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("moobuzz.in", "r");
FILE* fout = nullptr;

const int MAXSZ = -1; // todo
int n;


int main ()
{
  int arr[] = {-1, 1, 2, 4, 7, 8, 11, 13, 14};
  if (fin) { fout = fopen("moobuzz.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d", &n);
  int k = n/8;
  fprintf(fout, "%d", k*15 + arr[n%8]);


  return 0;
}
