/*
 ID: spoytie2
 TASK: XXXX
 LANG: C++14
 */

/*
 * Problem 9403 (xjoi.net/9403)
 * Created Sun 15 Sep 2019 @ 14:59 (PDT)
 * Accepted Thu 10 Oct 2019 @ 06:49 (PDT)
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

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 10010; // todo
int bricks[MAXSZ], vis[MAXSZ], fakedp[MAXSZ] = {};
int num, siz;

int dfs(cn top = 100000)
{
  int cur = 0;
  if (top < 100000 && fakedp[top])
    return fakedp[top];
  if (top < 100000)
  {
    //for (int i=0; i<num; ++i) printf("%3d", bricks[i]); printf("\n");
    //for (int i=0; i<num; ++i) printf("%3d", vis[i]); printf("\n\n");
    //cnt = (cnt+1)%1000000007;
    cur += 1;
  }
  for (int i = 0; i < num; ++i)
  {
    if (!vis[i] && bricks[i] + siz <= top)
    {
      vis[i] = true;
      cur = (cur + dfs(bricks[i])) % 1000000007;
      vis[i] = false;
    }
    else
    {
      break;
    }
  }
  fakedp[min(MAXSZ - 1, top)] = cur;
  return cur;
}

int main()
{
  scanf("%d%d", &num, &siz);

  for (int i = 0; i < num; ++i)
  {
    scanf("%d", &bricks[i]);
  }
  sort(bricks, bricks + num);
  printf("%d", dfs());

  return 0;
}

/*
 1 1
 10
 
 4 2
 1 2 3 100
 */
