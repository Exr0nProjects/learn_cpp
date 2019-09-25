/*
 * Problem #7201
 * struct 2
 */
#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 400;

struct nyan
{
    int legnum;
    int legs[MAXSZ];
    string head;
};

int main ()
{
    int num;
    scanf("%d", &num);
    for (int i=0; i<num; ++i)
    {
        nyan cat;
        scanf("%d", &cat.legnum);
        for (int j=0; j<cat.legnum; ++j) { scanf("%d", &cat.legs[j]); printf("%d ", cat.legs[j]); }
        cin >> cat.head;
        printf("%s\n", cat.head.c_str());
        
    }
    
    return 0;
}
