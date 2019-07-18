// 1228 disjointed, XC1900105AH 18 July 2019
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXSZ = 20;

int yay = 0;

void place (int h[], int v[], int d1[], int d2[], const int siz, const int rem, const int srt=0)
{
    if (rem == 0) { ++ yay; return; }
    
    for (int i=srt; i<siz; ++i)
    {
        for (int j=0; j<siz; ++j)
        {
            if (v[i] + h[j] + d1[i-j+siz] + d2[j-i+siz] == 0) // can place
            {
                ++v[i];
                ++h[j];
                ++d1[i-j+siz];
                ++d2[j-i+siz];
                place(h, v, d1, d2, siz, rem-1, i);
                --v[i];
                --h[j];
                --d1[i-j+siz];
                --d2[j-i+siz];
            }
        }
    }
    return;
}

int main ()
{
    int num;
    scanf("%d", num);
    
    int horizontal [MAXSZ] = {};
    int vertical [MAXSZ] = {};
    int dia1[2*MAXSZ] = {};
    int dia2[2*MAXSZ] = {};
    
    place(horizontal, vertical, dia1, dia2, num, num);
    printf("%d", yay);
    
    return 0;
}
