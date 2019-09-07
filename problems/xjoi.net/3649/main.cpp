/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 3649 (xjoi.net/3649)
 * Created Sat 07 Sep 2019 @ 06:31 (PDT)
 * Accepted [!meta:end!]
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

inline int cv (const char& c) { return c-'0'; }

string one_digit (string& main, const int n)
{
  int carry = 0;
  for (char& c : main)
  {
    c = (cv(c) * n + carry) % 10 + '0';
    carry = cv(c) * n / 10;
  }
  if (carry) main = string {carry+'0'} + main;
  return main;
}

int main ()
{
  int num;
  string prod = "1";
  scanf("%d", &num);
  for (int i=2; i<=num; ++i)
  {
    for (int j=i; j>0; j/=10)
    {
      one_digit(prod, j%10);
    }
  }

  printf("%s", prod.c_str());

  return 0;
}
