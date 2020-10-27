/*
 11 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
    int f, t, n;
} edges[MAXSZ*2];
int head[MAXSZ];
int rem[MAXSZ];

void addEdge (const int a, const int b)
{
    static int c = 1;
    edges[c].f = a;
    edges[c].t = b;
    edges[c].n = head[a];
    head[a] = c;
    ++c;
    ++rem[b];
}

auto comp (const int& r, const int& l)
{
    return rem[r] > rem[l];
}

int main()
{
    int p, q;
    scanf("%d%d", &p, &q);
    
    priority_queue<int, vector<int>, function<bool(int,int)> > pq(comp);
    for (int i=0; i<q; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    
    for (int i=1; i<=p; ++i) pq.push(i);
    
    for (; !pq.empty(); pq.pop())
    {
        if (rem[pq.top()])
        {
            printf("\nNot a DAG!");
            break;
        }
        printf("%d ", pq.top());
        for (int p=head[pq.top()]; p; p = edges[p].n)
        {
            --rem[edges[p].t];
        }
    }
    
    return 0;
}

/*
4 3
1 3
3 2
2 4
*/
