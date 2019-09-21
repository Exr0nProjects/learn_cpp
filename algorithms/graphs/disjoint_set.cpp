/*
20 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
    int from, to, next;
} edges[MAXSZ*2];
int head[MAXSZ];
int bigboi[MAXSZ];

void addEdge (const int a, const int b)
{
    static int next = 1;
    edges[next].from = a;
    edges[next].to = b;
    edges[next].next = head[a];
    head[a] = next;
    ++next;
}

int find (const int s)
{
    if (bigboi[s] == s) return s;
    bigboi[s] = find(bigboi[s]);
  return bigboi[s];
}


int main ()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i=0; i<n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }

    for (int i=1; i<=m; ++i)
    {
        if (bigboi[i] == 0) bigboi[i] = i;
        for (int e=head[i]; e; e=edges[e].next)
        {
            if (bigboi[edges[e].to])
            {
                bigboi[i] = bigboi[edges[e].to];
            }
        }
    }

    for (int i=1; i<=m; ++i)
    {
        printf("%3d", find(i));
    }

    return 0;
}