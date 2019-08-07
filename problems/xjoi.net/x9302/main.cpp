/*
 * Problem #9302
 * Wed 07 Aug 2019 @ 11:43 CST)
 * time test
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

class Time
{
  int year, month, day;
public:
  Time () {year=0; month=0; day=0;}
  Time (const int y, const int m, const int d)
  {
    year = y;
    month = m;
    day = d;
  }
  
  bool operator== (const Time& o)
  {
    return year == o.year && month == o.month && day == o.day;
  }
  bool operator!= (const Time& o)
  {
    return ! (*this == o);
  }
  bool operator< (const Time& o)
  {
    if (year < o.year) return true;
    else if (year == o.year)
    {
      if (month < o.month) return true;
      else if (month == o.month)
      {
        return day < o.day;
      }
    }
    return false;
  }
  bool operator<= (const Time& o)
  {
    return (*this < o) || (*this == o);
  }
  bool operator> (const Time& o)
  {
    return ! (*this == o || *this < o);
  }
  bool operator>= (const Time& o)
  {
    return !(*this < o);
  }
};

int main ()
{
  int a, b, c;
  Time beg, end, in;
  scanf("%d%d%d", &a, &b, &c);
  beg = Time {a, b, c};
  scanf("%d%d%d", &a, &b, &c);
  end = Time {a, b, c};
  
  if (end < beg)
  {
    end = beg;
    beg = Time {a, b, c};
  }
  
  scanf("%d%d%d", &a, &b, &c);
  in = Time {a, b, c};
  
  if (beg <= in && in <= end) printf("Yes");
  else printf("No");
  
  return 0;
}
