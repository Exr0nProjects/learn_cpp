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
int dp[MAXSZ][MAXSZ]; // far = next index to start checking // todo: subproblem graph

// int dp[MAXSZ][MAXSZ];

// int recurse(cn a, cn b)
// {
//   if (dp[a][b] >= 0) return dp[a][b];
//   int ret;
//   if (a == b && b == 0)
//   {
//     ret = s1[0] == s2[0]
//   }
//   else if (a == 0)
//   {
//     for (int i=0; i<=b; ++i)
//     {
//       ret |= s1[a] == s2[b]; // boolean max 
//     }
//   }
//   else if (b == 0)
//   {
//     for (int i=0; i<=a; ++i)
//     {
//       ret |= s1[a] == s2[b] // boolean max, see above
//     }
//   }
//   if (ret)
//   {
//     dp[a][b] = ret;
//     return ret;
//   }


// }

int main ()
{
  cin >> s1 >> s2;

  dp[0][0] = s1[0] == s2[0];
  for (int i=1; i<s1.length(); ++i)
  {
    dp[i][0] = s1[i] == s2[0];
  }
  for (int i=0; i<s2.length(); ++i)
  {
    dp[0][i] = s1[0] == s2[i];
  }

  for (int i=1; i<s1.length(); ++i)
  {
    for (int j=1; j<s2.length(); ++j)
    {
      dp[i][j] = dp[i-1][j-1] + (s1[i] == s2[j]);
    }
  }

  printf("%d\n", dp[s1.length()][s2.length()]);

  return 0;
}
