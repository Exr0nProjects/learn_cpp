/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 7982 (xjoi.net/7982)
 * Created Fri 30 Aug 2019 @ 17:13 (PDT)
 * Accepted Sun 01 Sep 2019 @ 15:26 (PDT)
 * (Final fix: target was the B stack not C stack, didn't read problem correctly.)
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

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1; // todo

string swap(string s, const char f, const char t)
{
  for (char &r : s)
  {
    if (r == f)
      r = t;
    else if (r == t)
      r = f;
  }
  return s;
}

int main()
{
  int num;
  scanf("%d", &num);

  string base = "A->B\n";

  for (int i = 1; i < num; ++i)
  {
    base = swap(base, 'C', 'B') + "A->B\n" + swap(base, 'A', 'C');
  }

  cout << base;

  return 0;
}
