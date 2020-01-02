/*
ID: spoytie2
TASK: evolution
LANG: C++14
*/

/*
 * Problem evolution (usaco/bronze/2019open/evolution)
 * Created Thu 02 Jan 2020 @ 10:10 (PST)
 * Accepted [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>
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
FILE *fin = fopen("evolution.in", "r");
FILE *_ = stderr;

const int MAXSZ = -1; // todo
int N;
set<set<string>> groups;

bool isSuperSet(set<string> a, set<string> b)
{ // nlogn*k
  for (ca s : b)
  {
    if (a.find(s) == a.end())
    {
      return false;
    }
  }
  return true;
}

int main()
{
  if (fin)
  {
    freopen("evolution.in", "r", stdin);
    stdout = fopen("evolution.out", "w+");
  }

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int t;
    cin >> t;
    if (t == 0) // FIX: forgot to add this condition (because the empty set can be ignored, as it is subset of everything)
    {
      --i;
      N -= 1;
      continue;
    }
    set<string> tmp;
    for (int j = 0; j < t; ++j)
    {
      string s;
      cin >> s;
      tmp.insert(s);
    }
    groups.insert(tmp);

    queue<set<string>> cache;
    for (ca s : groups) // also push the intersection with other sets
    {
      set<string> intersect;
      set_intersection(tmp.begin(), tmp.end(), s.begin(), s.end(), inserter(intersect, intersect.begin()));
      if (intersect.size() > 0)
        groups.insert(intersect);
    }
    //    for (; !cache.empty(); cache.pop())
    //    {
    //      groups.insert(cache.front());
    //    }
    //    groups.insert(tmp);
  }

  fprintf(_, "Checking %lu sets...\n", groups.size());

  for (const set<string> &sup : groups)
  {
    fprintf(_, "working on set of size %d: {", sup.size());
    for (const string &power : sup)
    {
      fprintf(_, "%s ", power.c_str());
    }
    fprintf(_, "}\n");

    set<set<string>> subs;
    for (ca sub : groups)
    {
      if (sup == sub)
        continue; // FIX: forgot to add this line
      if (isSuperSet(sup, sub))
      {
        subs.insert(sub);
        fprintf(_, "Superset #%d!\n", subs.size());
      }
    }
    if (subs.size() > 1)
    {
      for (ca a : subs) // FIX: (final) it was okay for a set to be super of 2 if one of the 2 was super of other (like if traits are A, AB, ABC)
        for (ca b : subs)
        {
          if (!isSuperSet(a, b) && !isSuperSet(b, a))
          {
            printf("no\n");
            return 0;
          }
        }
    }
  }
  printf("yes\n");

  return 0;
}

/*
 3
 1 cool
 1 cow
 2 cool cow
 -> no
 
 5
 0
 2 epic laser
 2 epic flight
 1 laser
 2 laser telepathy
 -> no
 
 3
 1 cool
 2 cool cow
 3 magic amazing legend
 -> yes
 
 4
 2 diabetes joy
 2 diabetes serenity
 2 cancer joy
 2 cancer serenity
 -> no
 
 3
 2 diabetes joy
 2 cancer joy
 2 cancer serenity
 -> no
 
 1
 5 ebola autism cancer allergies frostbite
 -> yes
 
 6
 2 a b
 3 a b c
 4 a b c d
 5 a b c d e
 6 a b c d e f
 1 a
 -> yes
 */
