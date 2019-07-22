/*
 * c1204-8
 * hampster hitting
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 110;

int mtime[MAXSZ];
int score[MAXSZ];

int main ()
{
  int num, maxtm = 0;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    scanf("%d", &mtime[i]);
    if (maxtm < mtime[i]) maxtm = mtime[i];
  }

  for (int i=0; i<num; ++i)
  {
    int s;
    scanf("%d", &s);

    if (score[mtime[i]] == 0) score[mtime[i]] = s;
    else score[mtime[i]] = max(s, score[mtime[i]]);
  }

  ll sum = 0;
  for (int i=0; i<=maxtm; ++i)
    sum += score[i];

  printf("%lld", sum);

  return 0;
}

/*

 5
 5  3  6  6  4
 7  9  2  1  5

 */
