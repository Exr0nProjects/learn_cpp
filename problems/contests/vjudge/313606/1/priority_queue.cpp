/*
 * VJudge 313606  1
 * 26 July 2019
 * Alice's weird dishes with priority queue
 */

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
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 100010; // todo

class Dish
{
public:
  int remain, price;
  bool operator< (const Dish& oth) const
  { return this->price < oth.price; }
} dishes[MAXSZ];

  int remain[MAXSZ];
  int price [MAXSZ];

  int main ()
  {
    priority_queue< Dish, vector<Dish> > cheapq;

    int food, cust;
    scanf("%d%d", &food, &cust);
    for (int i=0; i<food; ++i)
      scanf("%d", &dishes[i].remain);

    for (int i=0; i<food; ++i)
    {
      scanf("%d", &dishes[i].price);
      cheapq.push( dishes[i] );
    }

    for (int i=0; i<cust; ++i)
    {
      int type, amnt;
      scanf("%d%d", &type, &amnt);

      Dish* dish = &dishes[type];

      for (; amnt;)
      {
        if (dish->remain)
        {
          int temp = dish->remain;
          dish->remain -= amnt;
          amnt -= temp;
        }
        if (!dish->remain)
        {
          if (i) cheapq.pop();
          dish = ( cheapq.top() ); // brick
        }
      }
    }

    return 0;
  }
