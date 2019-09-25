// 1228 disjointed, XC1900105AH 18 July 2019
#include <bits/stdc++.h>
#define ll long long
  
using namespace std;
  
const int MAXSZ = 20;
  
int yay = 0;
  
void place (int h[], int v[], int d1[], int d2[], const int siz, const int rem, const int srt)
{
//  printf("    place called, rem %d\n", rem);
      
    if (rem == 0) { ++ yay; return; }
      
    //for (int i=srt; i<siz; ++i)
    //{
    int i=srt;
        for (int j=0; j<siz; ++j)
        {
            if (v[i] + h[j] + d1[i-j+siz] + d2[2*siz-1-i-j] == 0) // can place
            {
                ++v[i];
                ++h[j];
                ++d1[i-j+siz];
                ++d2[2*siz-1-i-j];
                place(h, v, d1, d2, siz, rem-1, i+1);
                --v[i];
                --h[j];
                --d1[i-j+siz];
                --d2[2*siz-1-i-j];
            }
        }
    //}
    return;
}
  
int main ()
{
    int num;
    cin >> num;
      
    int horizontal [MAXSZ] = {};
    int vertical [MAXSZ] = {};
    int dia1[2*MAXSZ] = {};
    int dia2[2*MAXSZ] = {};
      
    place(horizontal, vertical, dia1, dia2, num, num, 0);
    printf("%d", yay);
      
    return 0;
}
