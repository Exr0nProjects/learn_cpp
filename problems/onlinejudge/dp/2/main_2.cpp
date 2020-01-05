/*
ID: spoytie2
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (onlinejudge/dp/2)
 * Created Fri 03 Jan 2020 @ 09:28 (PST)
 * Accepted [!meta:end!]
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=970
 * problem 10029 - Edit Step Ladders
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
FILE *fin = fopen("2.in", "r");
FILE *_ = stderr;

const int MAXSZ = 25010; // todo
vector<string> strs(1);
int tabu[MAXSZ];

//struct Edge
//{
//  int f, t, n;
//} edges[MAXSZ * MAXSZ];
//int head[MAXSZ], ect = 1;
//void _addEdge(cn a, cn b)
//{
//  //d*/fprintf(_, "Adding edge %d!\n", ect);
//  edges[ect].f = a;
//  edges[ect].t = b;
//  edges[ect].n = head[a];
//  head[a] = ect;
//  ++ect;
//}

int adj[MAXSZ][MAXSZ];
void addEdge(cn a, cn b)
{
  adj[a][b] = adj[b][a] = 1;
}

bool isStep(string &a, string &b)
{
  //d*/printf("isStep %s %s?\n", a.c_str(), b.c_str());
  int ld = a.length() - b.length();
  if (abs(ld) > 1)
    return false;
  else if (ld == -1)
  {
    swap(a, b);
    ld = 1;
  }

  if (ld == 0)
  {
    bool c = false;
    for (int i = 0; i < a.length(); ++i)
    {
      if (a[i] != b[i])
      {
        if (!c)
          c = true; // one char is different
        else
          return false; // more than one char is different
      }
    }
    return c;
  }
  else if (ld == 1)
  {
    auto l = a.length();
    for (int i = 0; i < l; ++i)
    {
      char tmp[] = {a[i]};
      if (strcmp(a.erase(i, 1).c_str(), b.c_str()) == 0)
      {
        a.insert(i, tmp);
        return true;
      }
      a.insert(i, tmp);
    }
  }
  return false;
}

int dp(cn i)
{
  int ret = tabu[i];
  if (ret > 0)
    return ret;
  ret = 1; // not 1 because what if there are no edges?
//  for (int e = head[i]; e; e = edges[e].n)
//  {
//    if (strcmp(strs[i].c_str(), strs[edges[e].t].c_str()) > 0) // lex compare
//    {
//      ret = max(ret, dp(edges[e].t) + 1);
//    }
//  }
  for (int j=1; j<strs.size(); ++j)
  {
    if (adj[i][j] && strcmp(strs[i].c_str(), strs[j].c_str()) > 0)
    {
      ret = max(ret, 1+dp(j));
    }
  }
  fprintf(_, "dp(%d) -> %d\n", i, ret);
  tabu[i] = ret;
  return ret;
}

int main()
{
  if (fin)
  {
    stdin = fin;
    stdout = fopen("2.out", "w+");
  }
  
//  string a, b;
//  cin >> a >> b;
//  cout << isStep(a, b) << endl;
//  cout << a << endl << b << endl;
//  return 0;
  
  int N; scanf("%d", &N); // TODO: this only exists becasue I don't know how to input an arbitrary number of strings

  char buf[20];
  for (int k = 1; k<=N; ++k)
  {
    scanf("%s", buf);
    string s = buf;
    for (int i = 1; i < strs.size(); ++i)
    {
      //d*/fprintf(_, "Checking %s, %s -> %d\n", strs[i].c_str(), s.c_str(), isStep(strs[i], s));
      if (isStep(strs[i], s))
      {
        addEdge(i, k);
        addEdge(k, i);
      }
    }
    strs.push_back(s);
  }

//  fprintf(_, "Head: "); for (int i=1; i<N; ++i) fprintf(_, "%4d", head[i]);
//
//  fprintf(_, "\n\nidx:  "); for (int i=1; i<ect; ++i) fprintf(_, "%4d", i);
//  fprintf(_, "\nfrom: "); for (int i=1; i<ect; ++i) fprintf(_, "%4d", edges[i].f);
//  fprintf(_, "\nto:   "); for (int i=1; i<ect; ++i) fprintf(_, "%4d", edges[i].t);
//  fprintf(_, "\nnext: "); for (int i=1; i<ect; ++i) fprintf(_, "%4d", edges[i].n); fprintf(_, "\n\n\n");
  
  fprintf(_, "   "); for (int i=1; i<strs.size(); ++i) fprintf(_, "%3d", i);
  for (int i=1; i<strs.size(); ++i)
  {
    fprintf(_, "\n%2d:", i);
    for (int j=1; j<strs.size(); ++j)
    {
      fprintf(_, "%3c", adj[i][j]?'#':'.');
    }
  } fprintf(_, "\n");

  int ret = 0;
  for (int i = 1; i < strs.size(); ++i)
  {
    if (tabu[i] == 0)
    {
      ret = max(ret, dp(i));
    }
  }

  printf("%d", ret);

  return 0;
}
