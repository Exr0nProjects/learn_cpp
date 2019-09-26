/*
26 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1010;
typedef int nix;
typedef int nval;
typedef int nrnd;
nix child[MAXSZ*2]; // children of i are at child[2*i] and child[2*i+1]
nval val[MAXSZ];
nrnd rnd[MAXSZ];

void insert (const nval k)
{
    // create node
    static int count = 1;
    val[count] = k;
    rnd[count] = rand()%MAXSZ;
    // put into place for BST
    nix p = 1;
    for (; child[p];)
    {
        if (val[child[p]] == k)
            break;
        else if (val[child[p]] > k)
        {
            p = p*2+1;
        }
        else if (val[child[p]] < k)
        {
            p = p*2;
        }
    }
    child[p] = count;
    // heapify
    heapify(p);
    ++ count;
}

void heapify (const nix c)
{
    if (c == 1) return;
    if (val[child[c]] > val[child[c/2]])
    {
        // rotate
        if (c%2) // right child
        {

        }
        else // left child
        {
            nix t = child[c/2];
            child[c/2] = child[c];
        }
        
    }
}

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        nval t;
        scanf("%d", &t);
        insert(t);
    }
}