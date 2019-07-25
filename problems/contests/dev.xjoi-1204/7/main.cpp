/*
 * c1204-7
 * customers
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 10010;

int main ()
{
  int begs[MAXSZ] = { };
  int ends[MAXSZ] = { };
  ll dp[MAXSZ];
  ll ret = 0;

  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    scanf("%d%d", &begs[i], &ends[i]);
    int pt = i;
    for (; pt == 0 || ends[pt-1] > ends[pt]; --pt)
    {
      int _temp12 = begs[pt];
      begs[pt] = begs[pt-1];
      begs[pt-1] = _temp12;

      _temp12 = ends[pt];
      ends[pt] = ends[pt-1];
      ends[pt-1] = _temp12;
    }
  }

  for (int i=0; i<num; ++i)
  {
    ll mmax = 0;
    for (int j=0; j<i; ++j)
    {
      if (begs[i] >= ends[j] && dp[j] > mmax)
      {
        mmax = dp[j];
      }
    }
    dp[i] = mmax+1;
    if (dp[i] > ret) ret = dp[i];
  }

  printf("%lld", ret);

  return 0;
}
