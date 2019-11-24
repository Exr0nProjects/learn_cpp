/*
ID: spoytie2
TASK: 7077
LANG: C++14
*/

/*
 * Problem 7077 (xjoi.net/7077)
 * Created Sun 24 Nov 2019 @ 13:54 (PST)
 * Accepted Sun 24 Nov 2019 @ 14:10 (PST)
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
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("7077.in", "r");
// auto fout = fopen("7077.out", "w+");

const int MAXSZ = 1; // todo
string s;

string recurse(string in)
{
  for (int i=1; i<in.length(); ++i)
  {
    if (in[i] != in[i-1]) return "C" + recurse(in.substr(0, in.length()/2)) + recurse(in.substr(in.length()/2));
  }
  return in[0] == '0' ? "A" : "B";
}

int main ()
{
  cin >> s;

  cout << recurse(s);

  return 0;
}
