/*
 * Problem #9306
 * Wed 07 Aug 2019 @ 11:14 CST)
 * accuracy
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

int main ()
{
  int a, b, c;
  char op;
  scanf("%d", &a);
  scanf("%c", &op);
  scanf("%d?=", &b);
  scanf("%d", &c);
  
  int ans;
  switch (op)
  {
    case '+':
      ans = a+b;
      break;
    case '*':
      ans = a*b;
      break;
    case '-':
      ans = a-b;
      break;
    default:
      printf("QwQ");
      return 1;
  }
  
  ans = abs(ans-c);
  if (ans < 10) printf("Good");
  else if (ans < 20) printf("not bad");
  else printf("QwQ");
  
  return 0;
}
