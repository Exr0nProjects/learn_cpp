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

int egcd(const int a, const int b)
{
  if (b == 0) return a;
  return egcd(b, a%b);
}

int main ()
  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d", egcd(a, b));

  return 0;
}
