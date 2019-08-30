/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem #8121
 * Wed 28 Aug 2019 @ 20:00 (PDT)
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

const int MAXSZ = 110; // todo
int matrix[MAXSZ][MAXSZ];
int steps[MAXSZ][MAXSZ];
int a, b; // used to store size of matrix

inline int iRep(const pair<int, int> &n)
{
  return n.first * MAXSZ + n.second;
}
inline int iRep(const int a, const int b)
{
  return a * MAXSZ + b;
}
inline pair<int, int> pRep(const int n)
{
  pair<int, int> p;
  p.first = n / MAXSZ;
  p.second = n % MAXSZ;
  return p;
}

inline bool legit(pair<int, int> n)
{
  return n.first >= 0 && n.second >= 0 && n.first < a && n.second < b && matrix[n.first][n.second] == 0 && steps[n.first][n.second] == 0;
}

int main()
{
  scanf("%d%d\n", &a, &b);
  for (int i = 0; i < a; ++i)
  {
    for (int j = 0; j < b; ++j)
    {
      scanf("%1d", &matrix[i][j]);
    }
  }

  int si, sj, ei, ej;
  scanf("%d%d%d%d", &si, &sj, &ei, &ej);
  --ei;
  --ej;

  queue<int> q;
  q.push(iRep(si - 1, sj - 1));
  while (!q.empty())
  {
    int cur;
    if (q.front() == ei * MAXSZ + ej)
      break;
    else
      cur = max(steps[q.front() / MAXSZ][q.front() % MAXSZ], 1);
    steps[q.front() / MAXSZ][q.front() % MAXSZ] = cur;

    //    printf("%d %d (%d) => %d %d\n", q.front()/MAXSZ, q.front()%MAXSZ, cur, ei, ej); for (int i=0; i<a; ++i) { for (int j=0; j<b; ++j) printf("%d ", steps[i][j]); printf("\n"); } printf("\n\n");

    for (pair<int, int> n = pRep(q.front()); iRep(n) == q.front() || legit(n); ++n.first)
    {
      if (iRep(n) == q.front())
        continue;
      steps[n.first][n.second] = cur + 1;
      q.push(iRep(n));
    }
    for (pair<int, int> n = pRep(q.front()); iRep(n) == q.front() || legit(n); ++n.second)
    {
      if (iRep(n) == q.front())
        continue;
      steps[n.first][n.second] = cur + 1;
      q.push(iRep(n));
    }
    for (pair<int, int> n = pRep(q.front()); iRep(n) == q.front() || legit(n); --n.first)
    {
      if (iRep(n) == q.front())
        continue;
      steps[n.first][n.second] = cur + 1;
      q.push(iRep(n));
    }
    for (pair<int, int> n = pRep(q.front()); iRep(n) == q.front() || legit(n); --n.second)
    {
      if (iRep(n) == q.front())
        continue;
      steps[n.first][n.second] = cur + 1;
      q.push(iRep(n));
    }

    q.pop();
  }

  printf("%d", steps[ei][ej] - 2);

  return 0;
}

/*
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 1 0 1
0 1 1 0 0 0 0
0 0 0 0 1 1 0
1 3 1 7
  
4 4
0 1 1 1
0 0 1 1
1 0 0 1
1 1 0 0
1 1 4 4
 
4 4
0 1 1 0
0 1 0 0
0 1 0 1
0 0 0 0
1 1 1 4
  
4 4
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
2 3 4 4
 */