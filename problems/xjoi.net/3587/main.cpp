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
int far[MAXSZ][MAXSZ]; // far = next index to start checking // todo: subproblem graph
int amt[MAXSZ][MAXSZ];

int main ()
{
  cin >> s1 >> s2;

  far[0][0] = amt[0][0] = s1[0] == s2[0];
  for (int i=1; i<s1.length(); ++i)
  {
    amt[i][0] = s1[i] == s2[0];
    far[i][0] = (i+1)*amt[i][0]; // amt[i][0] is either 0 or 1 representing if char is same
  }
  for (int i=0; i<s2.length(); ++i)
  {
    amt[0][i] = s1[0] == s2[i];
    far[0][i] = (i+1)*amt[0][i];
  }

  for (int i=1; i<s1.length(); ++i)
  {
    for (int j=1; j<s2.length(); ++j)
    {
      for (int k=far[i-1][j]; k<s1.length(); ++k)
      {
        if (s1[k] == s2[j])
        {
          amt[i][j] = amt[i-1][j] + 1;
          far[i][j] = 
        }
      }
    }
  }

  return 0;
}
