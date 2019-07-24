/*
 * Vjudge 313606 2
 * 24 July 2019
 */

#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <math.h>
#include <random>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1000010; // todo

int main ()
{
  int num;
  scanf("%d", &num);

  int numbers[MAXSZ] = { };
  for (int i=0; i<num; +=i)
    scanf("%d", &numbers[i]);

  sort(numbers, numbers+num);

  long long ret = 0;
  for (int i=0; i<(num>>1); ++i)
    ret += (numbers[i] + numbers[num-i-1]) * (numbers[i] + numbers[num-i-1]);

  printf("%d", ret);

  return 0;
}
