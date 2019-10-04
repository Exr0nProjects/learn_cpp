/*
3 Oct 2019
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 100;
int tree[MAXSZ];

int find(cn a, cn b, cn c=1)
{
    if (tree[c] == 0) return 0;
    if (tree[c] == a || tree[c] == b) return tree[c];
    int fa = find(a, b, c*2), fb = find(a, b, c*2+1);
    if (fa && fb)
    {
        return tree[c];
    }
    else
    {
        return fa | fb;
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &tree[i]);
    }

    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d", find(a, b));
}