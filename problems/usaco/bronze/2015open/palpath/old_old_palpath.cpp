/*
ID: spoytie2
TASK: palpath
LANG: C++14
*/

/*
 * Problem palpath (usaco/bronze/2015open/palpath)
 * Created Sun Dec 15 2019 @ 08:56 (PST)
 * Accepted [!meta:end!]
 ! 2x DFS going from one corner to the center diagonal line
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
FILE *fin = fopen("palpath.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 30; // todo
int n;
char farm[MAXSZ][MAXSZ];
set<string> pals;

void walk(cl i, cl j, const string &p = "")
{
  if (!farm[i][j]) // out of bounds
    return;
  // if (i == n && j == n) // at the end
  // {
  //   printf((p + "\n").c_str());
  //   // check if its a palendrome
  //   for (int i=1; i<p.length(); ++i)
  //   {
  //     if (p[i] != p[p.length()-i]) return;
  //   }
  //   printf(("palendrome: " + p + "\n").c_str());
  //   pals.insert(p);
  //   return;
  // }
  if (i + j - 2 > n && (p[2 * n - i - j + 1] != p[i + j - 3])) // if this step makes it a non-palendrome
  {
    printf("\n%d, %d", 2 * n - i - j + 1, i + j - 3);
    printf("\n%c == %c\n", p[2 * n - i - j + 1], p[i + j - 3]);
    printf(("not a palendrome: " + p + "\n").c_str());
    return;
  }
  if (i == n && j == n) // if this is the end and we still have a palendrome
  {
    printf("made it to the end!\n");
    pals.insert(p);
    return;
  }
  walk(i + 1, j, p + string{farm[i][j]});
  walk(i, j + 1, p + string{farm[i][j]});
}

int main()
{
  if (fin)
  {
    fout = fopen("palpath.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  fscanf(fin, "%d", &n);
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= n + 1; ++j)
      farm[i][j] = '\0';
  for (int i = 1; i <= n; ++i)
  {
    fscanf(fin, "\n");
    for (int j = 1; j <= n; ++j)
    {
      fscanf(fin, "%c", &farm[i][j]);
    }
  }
  if (farm[1][1] != farm[n][n]) // dfs only checks for palendromes in the center (since you must start at beginning and end at end)
  {
    printf("0\n");
    return 0;
  }
  walk(1, 1);

  fprintf(fout, "%d\n", pals.size());

  return 0;
}
