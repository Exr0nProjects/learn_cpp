/*
 * Problem #7202
 * struct 3
 */
#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 100010;

struct nyan
{
    int a, b;
    char cow;
};

struct nyan2
{
    int legnum;
    int legs[MAXSZ];
    string head;
};

int main ()
{
    int num;
    scanf("%d", &num);
    
    nyan kittehz [MAXSZ];
    
    for (int i=0; i<num; ++i)
    {
        nyan cat;
        scanf("%d %d %c", &cat.a, &cat.b, &cat.cow);
        kittehz[i] = cat;
    }
    
    for (int i=0; i<num; ++i)
    {
        nyan2 cat;
        scanf("%d", &cat.legnum);
        printf("%d %d %c ", kittehz[i].a, kittehz[i].b, kittehz[i].cow);
        for (int j=0; j<cat.legnum; ++j) { scanf("%d", &cat.legs[j]); printf("%d ", cat.legs[j]); }
        cin >> cat.head;
        printf("%s\n", cat.head.c_str());
    }
    
    return 0;
}
