/*
ID: spoytie2
TASK: 4090
LANG: C++14
*/

/*
 * Problem 4090 (xjoi.net/4090)
 * Created Tue 31 Dec 2019 @ 09:23 (PST)
 * Accepted Tue 31 Dec 2019 @ 09:58 (PST)
 * usaco bronze2015feb
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
FILE *fin = nullptr;
FILE *_ = stderr;

const int MAXSZ = 1000010; // todo
string mag, censor;


int main ()
{
  if (fin) { stdin = fin; stdout = fopen("4090.out", "w+"); }
  cin >> mag >> censor;
  
  for (int j=0; j<mag.length(); ++j)
  {
    bool broken = false;
    for (int k=0; k<censor.length(); ++k)
    {
      if (mag[j+k] != censor[k])
      {
        broken = true;
        break;
      }
    }
    if (!broken)
    {
      //cout <<  mag << endl;
      mag.erase(j, censor.length());
      //cout << mag  << endl  << endl;
      j = max((int)j-(int)censor.length(), -1);
      //printf("backtracking to %d!\n", j);
    }
  
  }
  
  for (ca c : mag)
  {
    if (c > 0) printf("%c", c);
  }
  printf("\n");

  return 0;
}
