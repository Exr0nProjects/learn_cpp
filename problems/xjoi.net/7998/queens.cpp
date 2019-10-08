/*
 * Problem #7998
 * work division
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double
#define cn const int

using namespace std;

const int MAXSZ = 30;
bool h[MAXSZ], v[MAXSZ];
int c[MAXSZ][MAXSZ];
int gmn = 0, n;

void dfs(cn r)
{
    if (r == 1)
    {
        int _c;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (h[i] && v[j])
                {
                    _c += c[i][j];
                }
            }
        }
        if (gmn == 0) gmn = _c;
        else gmn = min(gmn, _c);
        return;
    }

    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (h[i] || v[j]) continue;
            h[i] = v[j] = true;
            dfs(r-1);
            h[i] = v[j] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            scanf("%d", &c[i][j]);
        }
    }

    dfs(n);
    printf("%d", gmn);

    return 0;
}
