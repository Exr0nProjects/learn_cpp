/*
24 Sep
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1010;
int val[MAXSZ];
int rnd[MAXSZ];
int p[MAXSZ]; // contains the pos of each child/parent as an index

const int MAXWG = 1000;
int cnt = 1;

void rotate (const int i)
{
    if (i == 1) return;
    int t = p[i/2];
    p[i/2] = p[i];
    p[i]
}

void heapify (const int i)
{
    if (i == 1) return;
    if (rnd[p[i]] > rnd[p[i/2]])
    {
        rotate(i);
        heapify(i/2);
    }
}

void insert (const int c)
{
    // insert based on BST 
    int i;
    for (i=1; p[i];)
    {
        if (val[c] < val[p[i]]) i *= 2;
        else if (val[c] > val[p[i]]) i = i*2+1;
        else break;
    }
    p[i] = c;
    // heapify
    heapify(i);
}

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        int w;
        scanf("%d", &w);

        val[cnt] = w;
        rnd[cnt] = rand()%MAXWG;

        insert(cnt);
        ++cnt;
    }
}