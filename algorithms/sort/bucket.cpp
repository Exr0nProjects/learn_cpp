/*
 * bucket sort
 * 7 July 2019
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10000;

int buckets [MAXSIZE];

int main ()
{
  int num, temp;
  cin >> num;
  for (int i=0; i<num; ++i)
  {
    cin >> temp;
    ++buckets[temp];
  }

  for (int i=0; i<MAXSIZE; ++i)
    for (int j=0; j<buckets[i]; ++j) cout << i << " ";

  return 0;
}
