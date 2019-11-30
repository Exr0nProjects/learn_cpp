/*
ID: spoytie2
TASK: cowjog
LANG: C++14                 
*/

/*
 * Problem cowjog (usaco/bronze/dec2014/cowjog)
 * Created Sat 30 Nov 2019 @ 10:18 (PST)
 * Accepted Sat 30 Nov 2019 @ 13:01 (PST)
 ! Inspired by http://usaco.org/current/data/sol_cowjog_bronze.html
 ! 1/11 test cases, only the first one is AC, others are WA
 ? Analysis:
 ? I don't understand what the problem is asking, what happens if you have inputs [(1, 2), (2, 2)]? Do they form two groups? Or count as one?
 ? What happens if you have something like [(1, 1), (2, 2), (3, 1)]? Is this one group or two?
 ? The problem solution loops from the back, but the explanation says to count the number of cows who do not have any slower cows before them,
 ?  so shouldn't we loop from the front? Don't we need the speed of the slowest cow infront of any given cow to check if this condition is met? Why loop from the back? 
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
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE* fin = fopen("cowjog.in", "r");
FILE* fout = nullptr;

const int MAXSZ = -1; // todo
int n;



int main ()
{
  if (fin) { fout = fopen("cowjog.out", "w+"); } else { fin = stdin; fout = stdout; }
  fscanf(fin, "%d", &n);
  vector<int> spood;
  for (int i=0; i<n; ++i)
  {
    int _, s;
    fscanf(fin, "%d%d", &_, &s);
    spood.push_back(s);
  }

  reverse(spood.begin(), spood.end());

  int s = -1, count=0;
  for (int p : spood)
  {
    if (s < 0 || s >= p)
    {
      s = p;
      ++count;
    }
  }

  fprintf(fout, "%d\n", count);

  return 0;
}
