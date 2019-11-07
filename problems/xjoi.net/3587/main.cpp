/*
ID: spoytie2
TASK: 3587
LANG: C++14                 
*/

/*
 * Problem 3587 (xjoi.net/3587)
 * Created Thu 07 Nov 2019 @ 07:43 (PST)
 * Accepted [!meta:end!]
 * 
 */


#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
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
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("3587.in", "r");
// auto fout = fopen("3587.out", "w+");

const int MAXSZ = 1010;
string s1, s2;
int dp[MAXSZ][MAXSZ]; // todo: subproblem graph

int main ()
{
  cin >> s1 >> s2;

  dps[0] = 0;
  for (int i=0; i<s1.length(); ++i)
  {
    char c = s1[i];
    for (int j = dps[max(i-1, 0)]; j < s2.length(); ++j)
    {
      if (c == s2[j])
      {
        dps[i] = j+1;
        break;
      }
    }
    dps[i] = max(dps[i], dps[max(0, i-1)]);
  }

  printf("%d", dps[s1.length()-1]);

  return 0;
}
