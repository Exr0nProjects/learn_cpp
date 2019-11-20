/*
 * binary min heap
 * 19 November 2019
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

#define cn const int
#define ll long long
#define dl double
#define i32x 2147483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 10010; // todo
int heap[MAXSZ];
int n, last = 1;

void heapify_up(cn pos)
{
  if (pos <= 1 || pos >= last)
    return;
  if (heap[pos / 2] < heap[pos])
  {
    swap(heap[pos / 2], heap[pos]);
    heapify_up(pos / 2);
  }
}

void push(cn num)
{
  heap[last] = num;
  ++last;
  heapify_up(last - 1);
}

void heapify_down(cn pos)
{
  if (pos < 1 || (int)log2(pos) >= (int)log2(last))
    return; // pos is less than root or leaf node
  if (heap[pos] < max((2 * pos < last ? heap[2 * pos] : 0), (2 * pos + 1 < last ? heap[2 * pos + 1] : 0)))
  {
    int targ = 0;
    if (2 * pos >= last)
      return; // then 2*pos+1 cannot be less than last since its a full binary tree
    if (2 * pos + 1 >= last)
      targ = 2 * pos;
    else if (heap[2 * pos + 1] > heap[2 * pos])
      targ = 2 * pos + 1;
    else
      targ = 2 * pos;
    swap(heap[pos], heap[targ]);
    heapify_down(targ);
  }
}

void pop()
{
  --last;
  swap(heap[1], heap[last]);
  heapify_down(1);
}

int top()
{
  return heap[1];
}

int empty()
{
  return last <= 1;
}

int main()
{
  printf("enter your numbers!\n> ");
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int a;
    scanf("%d", &a);
    push(a);
  }

  for (; !empty();)
  {
    printf("%d\n", top());
    pop();
  }

  return 0;
}
