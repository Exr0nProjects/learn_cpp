/*
ID: spoytie2
TASK: piggyback
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 40010;
int steps[MAXSZ];
int vis[MAXSZ];
struct Edge
{
    int from, to, next, layer=0;
} edges[MAXSZ*2];
int head[MAXSZ], hnext = 1;

void addEdge (const int a, const int b)
{
    edges[hnext].from = a;
    edges[hnext].to = b;
    edges[hnext].next = head[a];
    head[a] = hnext;
    ++hnext;
}

int main()
{
    printf("test\n");
    FILE *fin = fopen("piggyback.in", "r");
    FILE *fout = fopen("piggyback.out", "w+");
    if (fin == NULL)
        return 100;
    if (fout == NULL)
        return 101;

    int a, b, c, m, n;
    fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &m, &n);
    for (int i=0; i<n; ++i)
    {
        int _a, _b;
        scanf("%d%d", &_a, &_b);
        addEdge(_a, _b);
        addEdge(_b, _a);
    }

    queue<int> q;
    q.push(1);
    while (! q.empty())
    {
        steps[edges[head[q.front()]].to] = steps[edges[head[q.front()]].from] + 1;
        for (int i = head[q.front()]; i != 0; i = edges[i].next)
        {
            if (steps[edges[i].to] > 0)
            {
                q.push(edges[i].to);
            }
        }
        q.pop();
    }

    q.push(2);
    while (! q.empty())
    {
        steps[edges[head[q.front()]].to] = steps[edges[head[q.front()]].from] + 1;
        for (int i=head[q.front()]; i!= 0; i = edges[i].next)
        {
            if (vis[edges[i].to] == 0)
            {
                q.push(edges[i].to);
                vis[edges[i].to] = 1;
            }
        }
        q.pop();
    }

    int layer = 0;
    q.push(m);
    while (! q.empty())
    {
        steps[edges[head[q.front()]].to] += edges[head[q.front()]].layer + 1;
        layer = edges[head[q.front()]].layer;
        for (int i=head[q.front()]; i!=0; i=edges[i].next)
        {
            if (vis[edges[i].to] > 0)
            {
                q.push(edges[i].to);
                edges[edges[i].to].layer = layer+1;
                vis[edges[i].to] = -1;
            }
        }
        q.pop();
    }

    int m = 0;
    for (int i=0; i<m; ++i)
    {
        m = max(m, steps[i]);
    }
    fprintf(fout, "%d", m);

    return 0;
}
