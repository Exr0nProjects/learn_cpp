/*
ID: spoytie2
TASK: 3
LANG: C++14
*/

/*
 * Problem 3 (contests/dev.xjoi/dev.xjoi-1351/3)
 * Created Sat 28 Dec 2019 @ 18:08 (PST)
 * Accepted Sat 28 Dec 2019 @ 20:41 (PST)
 * hanoi with steps
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

const int MAXSZ = -1; // todo

string swip(string s, const char a, const char b)
{
  for (char &c : s)
  {
    if (c == a)
      c = b;
    else if (c == b)
      c = a;
  }
  return s;
}

int main()
{
  int n;
  scanf("%d", &n);

  string base = "1->3\n";
  for (int i = 1; i < n; ++i)
  {
    base = swip(base, '3', '2') + "1->3\n" + swip(base, '1', '2');
  }

  printf("%stot=%d", base.c_str(), (1 << n) - 1);

  return 0;
}
