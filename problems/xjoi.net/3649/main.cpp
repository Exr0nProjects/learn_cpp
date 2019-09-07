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
  for (LL c=main.length()-1; c>=0; --c)
  {
    int p = cv(main[c])*n+carry;
    main[c] = p % 10 + '0';
    carry = p / 10;
    printf("%d>%d ", p, carry);
  }
  printf(": ");
  if (carry) main = string {(char)(carry+'0')} + main;
  return main;
}

string add (string& a, const string& b)
{
  int carry = 0, v, i;
  for (i=0; i<min(a.length(), b.length()); ++i)
  {
    v = (a[a.length()-i]-'0') + (b[b.length()-i]-'0') + carry;
    a[a.length()-i] = (char) (v % 10 + '0');
    carry = v/10;
  }
  for (; i<max(a.length(), b.length()); ++i)
  {
    a[a.length()-i] = (char) (a[a.length()-i]-'0' + carry) % 10 + '0';
    carry = (a[a.length()-i]-'0' + carry) % 10;
  }
  if (carry) a = string{(char)(carry+'0')} + a;
  return a;
}

int main ()
{
  string a = "12349";
  string b = "111111";
  add(a, b);
  printf("%s", a.c_str());
  return 0;
  
  int num;
  string prod = "1";
  scanf("%d", &num);
  for (int i=2; i<=num; ++i)
  {
    string t = prod;
    for (int j=i; j>0; j/=10)
    {
      one_digit(t, j%10);
      prod += t;
      printf("%d, %s\n", j%10, prod.c_str());
    }
    cout << endl;
  }
  
  printf("%s", prod.c_str());
  
  return 0;
}
