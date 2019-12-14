/*
ID: spoytie2
TASK: lineup
LANG: C++14
*/

/*
 * Problem lineup (usaco/bronze/2019dec/lineup)
 * Created Sat 14 Dec 2019 @ 12:20 (PST)
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
FILE *fin = fopen("lineup.in", "r");
FILE *fout = nullptr;

const int MAXSZ = 8; // todo
int n;

vector<string> names({"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"});
//vector<string> names({"A", "B", "C", "D"});
vector<pair<string, string>> conns;

bool checkConditions(const vector<string> &names)
{
  //  printf("checking:");
  //  for (auto s : names) printf(" %s", s.c_str());
  //  printf("\n");
  ll count = 0;
  for (ll i = 1; i < names.size(); ++i)
  {
    for (const pair<string, string> &c : conns)
    {
      //    printf("%s, %s == %s, %s\n", names[i-1].c_str(), names[i].c_str(), c.first.c_str(), c.second.c_str());
      if ((names[i - 1] == c.first && names[i] == c.second) || (names[i - 1] == c.second && names[i] == c.first))
      {
        ++count;
        break;
      }
    }
  }
  //  printf("reached the end of condition checker! count=%d, size=%d\n", count, conns.size());
  return count == conns.size();
}

/*

bool permute(vector<string> &names, cl s)
{
  if (s + 1 == names.size() && true)
  {
    printf("winner:");
    for (auto s : names)
    {
      printf(" %s", s.c_str());
    }
    printf("\n");
    return true;
  }
  for (ll i = s; i < names.size(); ++i)
  {
    swap(names[s], names[i]);
    if (permute(names, s + 1))
      true;
    swap(names[s], names[i]);
  }
  for (ll i = s; i < names.size(); ++i)
  {
    swap(names[s], names[i]);
    if (permute(names, s + 1))
      true;
    swap(names[s], names[i]);
  }
  return false;
}
 */

//bool permute(vector<string> &names)
//{
//  do
//  {
//    if (checkConditions(names))
//    {
//      printf("winner:");
//      for (auto s : names)
//      {
//        printf(" %s", s.c_str());
//      }
//      printf("\n");
//      return true;
//    }
//  } while (next_permutation(names.begin(), names.end()));
//  return false;
//}
//
//bool checkConditions(const deque<string> &tab)
//{
//  ll count = 0;
//  for (ll i = 1; i < tab.size(); ++i)
//  {
//    for (const pair<string, string> &c : conns)
//    {
//      //    printf("%s, %s == %s, %s\n", names[i-1].c_str(), names[i].c_str(), c.first.c_str(), c.second.c_str());
//      if ((tab[i - 1] == c.first && tab[i] == c.second) || (tab[i - 1] == c.second && tab[i] == c.first))
//      {
//        ++count;
//        break;
//      }
//    }
//  }
//  //  printf("reached the end of condition checker! count=%d, size=%d\n", count, conns.size());
//  return count == conns.size();
//}

bool permute(const vector<string> &names, set<ll> vis = set<ll>{}, vector<string> tab = vector<string>{})
{
  if (vis.size() == names.size())
  {
    if (!checkConditions(tab))
      return false;
    for (ca s : tab)
    {
      fprintf(fout, "%s\n", s.c_str());
    }
    return true;
  }
  for (ll i = 0; i < names.size(); ++i)
  {
    if (vis.find(i) != vis.end())
      continue; // already used
    tab.push_back(names[i]);
    vis.insert(i);
    if (permute(names, vis, tab))
      return true;
    vis.erase(i);
    tab.pop_back();
  }
  return false;
}

int main()
{
  if (fin)
  {
    fout = fopen("lineup.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }

  //  permute(names);
  //  printf("end\n");
  //  return 10000000000000000;

  fscanf(fin, "%d\n", &n);
  for (int i = 0; i < n; ++i)
  {
    char b1[20], b2[20];
    fscanf(fin, "%s must be milked beside %s", b1, b2);
    conns.push_back(make_pair(b1, b2));
  }

  if (!permute(names))
  {
    fprintf(fout, "THIS SHOULD NEVER HAPPEN!\n");
  }

  return 0;
}

/*
 
1
C must be milked beside B
 */
