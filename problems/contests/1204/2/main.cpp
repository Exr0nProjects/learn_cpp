/*
 * c1204-1
 * gcd
 */

#include <cstdio>
#include <algorithm>
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

int arr[MAXSZ];

int main ()
{
  int n, m, pt=0, t;
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; ++i)
  scanf("%d", &arr[i]);

  scanf("%d", &t);
  for (int i=0; i<m;)
  {
    if (t < arr[pt] || pt == n)
    {
      printf("%d ", t);
      scanf("%d", &t);
      ++i;
    }
    else
    {
      printf("%d ", arr[pt]);
      ++pt;
    }
  }
  for (; pt<n; ++pt) printf("%d ", arr[pt]);

  return 0;
}
