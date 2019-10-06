/*
6 Oct 2019
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 20;
bool v[MAXSZ];

int choose(cn n, cn k, deque<int> q)
{
    static int count = 0;
    if (k == 0)
    {
        ++count;
        for (int p = q.front(); !q.empty(); q.pop_front())
        {
            p = q.front();
            printf("%3d", p);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i])
            continue;
        v[i] = true;
        q.push_back(i);
        choose(n, k - 1, q);
        q.pop_back();
        v[i] = false;
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    deque<int> q;
    printf("total: %d", choose(n, k, q));
}
