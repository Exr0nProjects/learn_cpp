/*
ID: spoytie2
TASK: cowcode
LANG: C++14
*/

/*
 * Problem cowcode (usaco/silver/2017jan/cowcode)
 * Create time: Fri 17 Jan 2020 @ 16:57 (PST)
 * Accept time: Fri 17 Jan 2020 @ 18:10 (PST)
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
#include <cstring>
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
FILE *fin = fopen("cowcode.in", "r");
FILE *_ = stderr;

const ll MAXSZ = 50; // todo
ll N;
int len;

bool isPwr2(cl n)
{
  return n && (!(n&(n-1))); // https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/
}

ll pos(cl i)
{
  if (i < len) return i;
  
  int l = (int) log2(i/len);
//  printf("i=%llu, l=%d\n", i, l);
  
  if (isPwr2(i/len) && i%len == 0)
  {
//    printf("new segment! %llu\n", 1llu << l);
    return pos(i-1); // i/len is a power of 2
  }
  else
  {
//    printf("folding at %llu\n", len*((1ll<<l)));
    return pos(i - len*(1ll<<l) - 1);
  }
}

int main ()
{
  if (fin) { stdin = fin; stdout = fopen("cowcode.out", "w+"); }
  char code[MAXSZ];
  scanf("%s%n%lld", code, &len, &N);
  
  if (len == 1)
  {
    printf("%c\n", code[0]);
    return 0;
  }
  
  printf("%c\n", code[pos(N-1)]);

  return 0;
}
