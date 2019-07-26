/*
 * Problem VJudge 314632 1
 * 26 July 2019
 * Substring count
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>

#define ll long long
#define dl double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 200010; // todo
const int ALHSZ = 30;

int dp [MAXSZ][ALHSZ] = { }; // for every readable ascii and then some padding

int main ()
{
  int len, sub;
  scanf("%d%d\n", &len, &sub);
  string inp;
  getline(cin, inp);

  if (sub == 1) dp[0][inp[0]-'a'] = 1;

  //d*/ printf("   "); for (int i=0; i<ALHSZ; ++i) printf("  %c", (char) 'a'+i); printf("\n");
  //d*/ printf("%d %c", 0, inp[0]); for (int j=0; j<ALHSZ; ++j) printf("%3c", (dp[0][j]==0 ? '.' : dp[0][j]+'0') ); printf("\n");

  char t = inp[0];
  int count = 1;
  for (int i=1; i<len; ++i)
  {
    if (inp[i] == t) count ++;
    else             count =1;
    t = inp[i];

    for (int j=0; j<ALHSZ; ++j)
      dp[i][j] = dp[i-1][j];

    if (count >= sub)
    {
      if (i < sub) dp[i][t-'a'] = 1; // first inp[sub] is a valid sequence
      else dp[i][t-'a'] = max(dp[i][t-'a'], dp[i-sub][t-'a']+1);
      count = 0;
    }
    //d*/ printf("%d %c", i, inp[i]); for (int j=0; j<ALHSZ; ++j) printf("%3c", (dp[i][j]==0 ? '.' : dp[i][j]+'0') ); printf("\n");
  }


  int mmax=0;
  for (int i=0; i<ALHSZ; ++i)
    mmax = max(mmax, dp[len-1][i]);

  printf("%d", mmax);

  return 0;
}
