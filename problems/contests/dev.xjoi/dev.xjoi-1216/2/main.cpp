#include <iostream>
#include <math.h>

using namespace std;

const int MAXSZ = 1010;
int tin[MAXSZ][MAXSZ];

const int MOD = 1000000007; // todo

inline void compute (const int i, const int j, const int v)
{
  tin [i][j] = v;
}

int main ()
{
  int num, siz;
  scanf("%d", &num);
  siz = (int) sqrt(num) + 1;
  
  tin[0][0] = 1;
  int posy=0, posx=1, count=1;
  bool flip = 0;
  for (int i=2; i<num;)
  {
    for (int j=0; j<count && i<num; ++j)
    {
      compute(posy, posx, i);
      ++i;
      
      if (flip) ++posx;
      else ++posy;
    }
    for (int j=0; j<count && i<num; ++j)
    {
      compute(posy, posx, i);
      ++i;
      
      if (flip) --posy;
      else --posx;
    }
    compute(posy, posx, i);
    ++i;
    
    if (flip) ++posx;
    else ++posy;
    
    flip = !flip;
    ++count;
  }
  
  long long ans = 0;
  
  for (int i=posy; i>=0; --i)
  {
    for (int j=posx; j>=0; --j)
    {
      ans += (tin[i][j] * ((int) pow(2, (posy-i + posx-j)) % MOD) ) % MOD;
    }
  }
  printf("%lld", ans);
}
