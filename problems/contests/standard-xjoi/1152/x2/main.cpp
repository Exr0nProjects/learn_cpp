/*
 * Post-array test (sub): Problem #2
 * 14 June 2019
 * merge
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


int main ()
{
  int sa, sb;
   // should use vector but dont understand yet
  cin >> sa;
  int * aa = new int [sa];
  for (int i=0; i<sa; ++i) cin >> aa[i];
  cin >> sb;
  int * ab = new int [sb];
  for (int i=0; i<sb; ++i) cin >> ab[i];

  int size = sa + sb, pa=0, pb=0;
  int * fin = new int [size];
  for (int i=0; i<size; ++i)
  {
    if      (pa == sa) fin[i] = ab[pb++];
    else if (pb == sb) fin[i] = aa[pa++];
    else if (aa[pa] > ab[pb]) fin[i] = ab[pb++];
    else fin[i] = aa[pa++];
    cout << fin[i] << " ";
  }

  return 0;
}
